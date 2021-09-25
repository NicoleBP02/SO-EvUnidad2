#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <pthread.h>

void upper(char *buffer);
void words(char *buffer);
void vowels(char *buffer);
void* procesohilo(char *buffer);

int main(int argc, char **argv)
{
    FILE *fin = fopen(argv[1], "r");
    if (fin == NULL)
    {
        perror("Imagen 2 Falla en la apertura del archivo de entrada: ");
        return (EXIT_FAILURE);
    }

    pthread_t threadID;

    char buffer[256]; //REVISAR BUFFER PARA USARLO EN OTRAS FUNCIONES
    char *status = NULL;
    do
    {
        status = fgets(buffer, sizeof(buffer), fin);
        if (status != NULL)
        {
            printf("Original: %s", buffer);
            sleep(1);
        }

        pthread_create(&threadID,NULL,&procesohilo,&buffer); //REVISAR LOS PARAMETROS

    } while (status != NULL);
    //printf("\n");
}

void upper(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; ++i)
    {
        buffer[i] = toupper(buffer[i]);
    }
    printf("Procesada (UPPER): %s\n", buffer);
}

void words(char *buffer)
{
    int contador = 0;
    int largo = strlen(buffer);

    for (int i = 0; i < largo; i++)
    {
        if (buffer[i] == ' ' && buffer[i + 1] != ' ')
        {
            contador++;
        }
    }
    printf("Procesada (cantidad de palabras): %d \n", contador);
}

void vowels(char *cadena)
{
	int vocales = 0;
	for (int indice = 0; cadena[indice] != '\0'; ++indice)
    {
		char letraActual = tolower(cadena[indice]);
		if (letraActual == 'a' || letraActual == 'e' || letraActual == 'i' || letraActual == 'o' || letraActual == 'u')
		{
			vocales++;
		}
	}
	printf("Procesada (cantidad de vocales): %d \n", vocales);
}
void* procesohilo(char *buffer)
{
    
}
