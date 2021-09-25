#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv){

    FILE *fin = fopen(argv[1],"r");
    if (fin == NULL){
        perror("Imagen 2 Falla en la apertura del archivo de entrada: ");
        return(EXIT_FAILURE);
    }

    char buffer[128];
    char *status =  NULL;
    do{
        status = fgets(buffer, sizeof(buffer),fin);
        if(status != NULL){
            printf("%s",buffer);
            sleep(1);
        }
    }while (status !=NULL);
    printf("\n");

}