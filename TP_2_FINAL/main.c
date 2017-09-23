#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define MAX 20

int main()
{
    char seguir='s';
    int opcion=0;
    EPersona lista[MAX];

    inicializarEstados(lista,MAX);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                obtenerEspacioLibre(lista,MAX);
                addNewPersona(lista,MAX);
                break;
            case 2:
                borrarPersona(lista,MAX);
                break;
            case 3:
                ordenarLista(lista,MAX);
                printLista(lista,MAX);
                break;
            case 4:
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("\nSe ingreso una opcion incorrecta, reingrese (1/5)\n\n");
        }
    }
    return 0;
}
