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
    int contMenor18=0;
    int contEntre19y35=0;
    int contMayor35=0;
    int i;

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
            for(i=0; i<MAX; i++)
            {
                if(lista[i].estado==1)
                {
                    if(lista[i].edad<18)
                    {
                        contMenor18++;
                    }
                    else if(lista[i].edad >19 && lista[i].edad < 35)
                    {
                        contEntre19y35++;
                    }
                    else
                    {
                        contMayor35++;
                    }
                }
            }
            imprimirGraficoEdades(contMenor18,contEntre19y35,contMayor35);
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
