#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

//función Padre
int main(int argc, char **argv)
{
    pid_t pid_hijo;
    pid_t pid_hijo2;
    pid_t pid_hijo3;

    pid_hijo = fork();
    int status;

    switch (pid_hijo)
    {
    case -1: /* Error */
        printf("Error al crear el proceso");
        return -1;
    case 0: ;/* Código ejecutado por el hijo */
        argv[0] = "./variadicaProm";
        execv("./variadicaProm",argv);
        break;
    default:
    { /* Código ejecutado por el padre */

        pid_hijo2 = fork();
        switch (pid_hijo2)
        {
        case -1: /* Error */
            printf("Error al crear el proceso");
            return -1;
        case 0: ;/* Código ejecutado por el hijo */
            argv[0] = "./variadicaMin";
            execv("./variadicaMin",argv);
            break;
        default: /* Código ejecutado por el padre */
            pid_hijo3 = fork();
            switch (pid_hijo3)
            {
            case -1: /* Error */
                printf("Error al crear el proceso");
                return -1;
            case 0: ;/* Código ejecutado por el hijo */
                argv[0] = "./variadicaMax";
                execv("./variadicaMax",argv);
                break;
            default:           /* Código ejecutado por el padre */
                wait(&status); //espera que el acta de defunción de los hijos zombies
                wait(&status);
                wait(&status);
                printf("El padre terminó\n");
            }
        }
    }
    }
}