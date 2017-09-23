#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

int obtenerEspacioLibre(EPersona lista[], int tam)
{
    int i;
    int flag=0;
    int espacioLibre;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            espacioLibre=i;
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        espacioLibre=1;
    }
    return espacioLibre;
}

void inicializarEstados(EPersona lista[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        lista[i].estado = 0;
    }
}

void addNewPersona(EPersona lista[], int tam)
{

    char buffer[255];
    int espacioLibre=obtenerEspacioLibre(lista, tam);
    int auxEdad, auxDni, posDni;

    if(lista[espacioLibre].estado==0 && espacioLibre != -1)
    {
        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(buffer);

        while(strlen(buffer)<2||strlen(buffer)>49)
        {
            printf("ERROR, reingrese nombre valido: ");
            fflush(stdin);
            gets(buffer);
        }
        strcpy(lista[espacioLibre].nombre,buffer);

        printf("Ingrese edad: ");
        scanf("%d", &auxEdad);
        while(auxEdad<0)
        {
            printf("ERROR, la edad no puede ser negativa. Reingrese edad valida: ");
            scanf("%d", &auxEdad);
        }
        lista[espacioLibre].edad=auxEdad;

        printf("Ingrese DNI: ");
        scanf("%d", &auxDni);

        posDni=buscarPorDni(lista,auxDni,tam);

        while(posDni!=-1)
        {
            printf("ERROR, ese DNI se encuentra en uso. Reingrese DNI: \n");
            scanf("%d", &auxDni);
            posDni=buscarPorDni(lista,auxDni,tam);
        }
        lista[espacioLibre].dni = auxDni;
        printf("\nAgregado con exito.\n\n");
        lista[espacioLibre].estado=1;
    }

    if(espacioLibre == -1)
    {
        printf("\nNo hay mas espacio disponible.");
    }
}

int buscarPorDni(EPersona lista[], int dni, int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1 && lista[i].dni==dni)
        {
            return i;
            break;
        }
    }
    return -1;
}

void borrarPersona(EPersona lista[], int tam)
{
    int auxDni;
    int posDni;
    char elimina;
    int flagEliminar=0;

    printf("\nIngrese numero de DNI de la persona a eliminar: ");
    scanf("%d", &auxDni);

    posDni=buscarPorDni(lista,auxDni,tam);

    if(posDni!=-1)
    {
        printPersona(lista,posDni);
        printf("\nSeguro desea eliminar? (s|n)");
        fflush(stdin);
        scanf("%c", &elimina);
        flagEliminar=1;

        if(elimina=='s')
        {
            printf("\nEliminado con exito.\n");
            lista[posDni].estado=0;
        }
        else
        {
            printf("\nCancelado.\n");
        }
    }

    if(flagEliminar==0) // si no encuentra coincidencia con dni el flag queda en 0
    {
        printf("\nERROR, esa persona no existe en el sistema.\n");
    }
}

void printPersona(EPersona lista[], int indice)
{
    printf("\nNombre: %s, Edad: %d, DNI: %d\n",lista[indice].nombre, lista[indice].edad, lista[indice].dni);
}

void ordenarLista(EPersona lista[], int tam)
{
    int i,j;
    EPersona aux;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmpi(lista[i].nombre, lista[j].nombre) >0)
            {
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }
    }
}

void printLista(EPersona lista[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {
            printPersona(lista,i);
        }
    }
}

void imprimirGraficoEdades(int contMenor18, int contEntre19y35, int contMayor35)
{
    int i, j;
    int maxCont=0;
    int arrayCont[3] = {contMenor18, contEntre19y35, contMayor35};

    for(i=0; i<3; i++)
    {
        if(arrayCont[i]>maxCont)
        {
            maxCont=arrayCont[i];
        }
    }

    for(i=maxCont; i>0; i--)
    {
        for(j=0; j<3; j++)
        {
            if(arrayCont[j]>=i)
            {
                printf("\t*");
            }
            else
            {
                printf("\t");
            }
        }
        printf("\n");
    }

    printf("\t18\t19>35\t>35\n");
}
