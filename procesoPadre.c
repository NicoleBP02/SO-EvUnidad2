#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]){

    int resultado = 0;
    int statushijo;

    //Esperamos al hijo antes de abrir el archivo
    wait(&statushijo);

    FILE *fin = fopen("resultadohijo.txt","r");
    if (fin == NULL){
        perror("Imagen 2 Falla en la apertura del archivo de entrada: ");
        return(EXIT_FAILURE);
    }

    char buffer[16];
    char *status = NULL;

    status = fgets(buffer, sizeof(buffer), fin);
    if (status != NULL)
    {
    char *token;
    token = strtok(buffer, ""); //strtok es para partir una cadena de caracteres en subcadenas indicando el separador
    if (token == NULL)
    {
        printf("No hay elementos en el arreglo");
        EXIT_FAILURE;
    }
    resultado = atoi(token);
    }
    printf("Primer proceso: resultado=%d\n", resultado);
}