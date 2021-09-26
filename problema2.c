#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

//función Padre
int main(int argc, char **argv)
{
    pid_t pid_hijo;

    pid_hijo = fork();

    switch (pid_hijo)
    {
    case -1: /* Error */
        printf("Error al crear el proceso");
        return -1;
    case 0: ;/* Código ejecutado por el hijo */
        FILE *fout = fopen("resultadohijo.txt","r+");
        if (fout == NULL){
            perror("Principal Falla en la apertura del archivo de salida: ");
            return(EXIT_FAILURE);
        }
        int cont = 0;
        int suma = 0;

        for (int i = 1; i < argc; i++)
        {
            suma+= atoi(argv[i]);
            cont++;
        }
        fprintf(fout, "%d", suma/cont);
        break;
    default:
        { /* Código ejecutado por el padre */
            //DEBE CAMBIAR SU IMAGEN
            argv[0] = "./procesoPadre";
            execv("./procesoPadre",argv);
            printf("No funciono execv para el padre\n");
        }
    }
}