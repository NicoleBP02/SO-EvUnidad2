#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <pthread.h>

void upper(char *buffer);
void words(char *buffer);
void vowels(char *buffer);
void* procesohilo(void *param);


int main(int argc, char **argv)
{
    FILE *fin = fopen(argv[1], "r");
    if (fin == NULL)
    {
        perror("Imagen 2 Falla en la apertura del archivo de entrada: ");
        return (EXIT_FAILURE);
    }
    int *conv = malloc(sizeof(int));
    *conv = 2;

    pthread_t threadID;
    pthread_create(&threadID,NULL,&procesohilo,&conv); //REVISAR LOS PARAMETROS

    char buffer[256];
    char *status = NULL;
    do
    {
        status = fgets(buffer, sizeof(buffer), fin);
        if (status != NULL)
        {
            switch (*conv)
            {
            case 1: //Upper
                printf("Original: %s", buffer);
                //procesa UPPER
                upper(buffer);
                printf("Procesado (upper): %s", buffer);
                sleep(1);
                break;
            case 2: //Words
                printf("Original: %s", buffer);
                //procesa words
                words(buffer);
                printf("Procesado (words): %s", buffer);
                sleep(1);
                break;
            case 3: //Vowels
                printf("Original: %s", buffer);
                //procesa vowels
                vowels(buffer);
                printf("Procesado (vowels): %s", buffer);
                sleep(1);
                break;
            default: //none
                printf("%s", buffer);
                sleep(1);
                break;
            }
        }
    } while (status != NULL);
    //printf("\n");
}

void upper(char *buffer) //1
{
    for (int i = 0; buffer[i] != '\0'; ++i)
    {
        buffer[i] = toupper(buffer[i]);
    }
    printf("Procesada (UPPER): %s\n", buffer);
}

void words(char *buffer) //2
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

void vowels(char *cadena) //3
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
void* procesohilo(void *param)
{
    char respuesta[16];
    int conv = *((int*) param);
    while (1)
    {
        //printf("Esperando conversion");
        scanf("%s", respuesta);
        /*for (int i = 0; respuesta[i] != '\0'; ++i)
        {
		    char letraActual = tolower(respuesta[i]);
	    }*/
        int eqUpper = strcmp(respuesta, "upper");
        int eqWords = strcmp(respuesta, "words");
        int eqVowels = strcmp(respuesta, "vowels");

        if (eqUpper == 0)
        {
            conv = 1;
        }
        else if (eqWords == 0)
        {
            conv = 2;
        }
        else if (eqVowels == 0)
        {
            conv = 3;
        }
        else{
            conv = 4; //NONE
        }
    }
    return NULL;
}
