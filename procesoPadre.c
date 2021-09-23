#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]){

    char resultado = 0;
    int statushijo = 0;

    FILE *fin = fopen(argv[1],"r");
    if (fin == NULL){
        perror("Falla en la apertura del archivo de entrada: ");
        return(EXIT_FAILURE);
    }

    char buffer[32];
    char *status = NULL;

    status = fgets(buffer, sizeof(buffer), fin);
    if (status != NULL)
    {
    char *token;
    token = strtok(buffer, " "); //strtok es para partir una cadena de caracteres en subcadenas indicando el separador
    if (token == NULL)
    {
        printf("No hay elementos en el arreglo");
        EXIT_FAILURE;
    }
    resultado = token;
    char *token2;
    token2 = strtok(NULL, "");
    statushijo = atoi(token2);
    }
    //Una vez teniendo los datos, esperamos al hijo
    wait(statushijo);

    printf("Primer proceso: resultado=%s\n", resultado);
}