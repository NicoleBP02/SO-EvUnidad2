#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <pthread.h>
#include <termios.h>

void upper(char *buffer);
void words(char *buffer);
void vowels(char *buffer);
void *procesohilo(void *param);
void ECHOoff();

// Declaracion de variable que funcionara como switch de manera global
int conv = 5;

int main(int argc, char **argv)
{
    FILE *fin = fopen(argv[1], "r");
    if (fin == NULL)
    {
        perror("Falla en la apertura del archivo de entrada: ");
        return (EXIT_FAILURE);
    }

    pthread_t threadID;
    pthread_create(&threadID, NULL, &procesohilo, NULL);

    char buffer[256];
    char *status = NULL;
    // Leer todo el archivo e imprimir segun el conv
    do
    {
        status = fgets(buffer, sizeof(buffer), fin);
        if (status != NULL)
        {
            switch (conv)
            {
            case 1: //Upper
                printf("Original: %s", buffer);
                //procesa UPPER
                upper(buffer);
                sleep(1);
                break;
            case 2: //Words
                printf("Original: %s", buffer);
                //procesa words
                words(buffer);
                sleep(1);
                break;
            case 3: //Vowels
                printf("Original: %s", buffer);
                //procesa vowels
                vowels(buffer);
                sleep(1);
                break;
            case 4: //None
                printf("%s", buffer);
                sleep(1);
                break;
            default:
                printf("%s", buffer);
                sleep(1);
                break;
            }
        }
    } while (status != NULL);
}

void upper(char *buffer) //1
{
    for (int i = 0; buffer[i] != '\0'; ++i)
    {
        buffer[i] = toupper(buffer[i]);
    }
    printf("Procesada (UPPER): %s", buffer);
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
    printf("Procesada (cantidad de palabras): %d\n", contador);
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
    printf("Procesada (cantidad de vocales): %d\n", vocales);
}
void *procesohilo(void *param)
{
    ECHOoff();
    char respuesta[16];
    while (1)
    {
        scanf("%s", respuesta);
        // printf("------------------------Respuesta %s ----------------------------------\n", respuesta);
        for (int i = 0; respuesta[i] != '\0'; ++i)
        {
            respuesta[i] = tolower(respuesta[i]);
        }
        // Compara la entrada con los metodos de escritura
        int eqUpper = strcmp(respuesta, "upper");
        int eqWords = strcmp(respuesta, "words");
        int eqVowels = strcmp(respuesta, "vowels");
        int eqNone = strcmp(respuesta, "none");

        // Cambia el valor de conv segun la entrada de usuario
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
        else if (eqNone == 0)
        {
            conv = 4;
        }
    }
    return NULL;
}
void ECHOoff()
{
    struct termios term;
    tcgetattr(fileno(stdin), &term);

    term.c_lflag &= ~ECHO;
    tcsetattr(fileno(stdin), 0, &term);
}
