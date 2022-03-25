#include <stdio.h>
#include <string.h>
#include "configuracion.h"
#include "palabras/palabras.h"
#include "utilidades/utilidades.h"

int jugar()
{
    char palabraAdivinar[6];
    strcpy(palabraAdivinar, palabras[numeroAleatorio()]);

    char palabrasUsuario[NUM_RONDAS][6];

    for (int ronda = 0; ronda <= NUM_RONDAS; ronda++)
    {
        limpiarConsola();
        // printf("La palabra es %s\n", palabraAdivinar);
        for (int i = 0; i < ronda; i++)
        {
            imprimirPalabra(palabrasUsuario[i], palabraAdivinar);
        }
        for (int i = 0; i < NUM_RONDAS - ronda; i++)
        {
            imprimirVacio();
        }
        if (strcmp(palabrasUsuario[ronda - 1], palabraAdivinar) == 0)
        {
            return ronda;
        }
        if (ronda == NUM_RONDAS)
        {
            printf("La palabra era %s\n", palabraAdivinar);
            return -1;
        }

        do
        {
            printf("Introduce una palabra: ");
            fgets(palabrasUsuario[ronda], 6, stdin);
            fflush(stdin);
            palabrasUsuario[ronda][5] = 0; // Para quitar el \n
        } while (!existePalabra(palabrasUsuario[ronda])); //pedir palabra hasta que la palabra exista
    }
}

int main()
{
    cargarPalabras();
    printf("Adivinado a la %d", jugar());

    return 0;
}