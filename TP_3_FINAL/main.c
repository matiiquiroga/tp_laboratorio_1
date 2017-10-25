#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define TAMMOVIES 20

int main()
{
    char seguir='s';
    int opcion=0;
    EMovie arrayMovies[TAMMOVIES];

    EMovie* punteroArrayMovies;
    FILE* data;

    punteroArrayMovies=&arrayMovies[0];

    if((data=fopen("data.bin","rb"))==NULL)
    {
        if((data=fopen("data.bin","wb"))==NULL)
        {
            printf("\nEl archivo no puede ser abierto");
            exit (1);
        }
        else
        {
            inicializarEstados(punteroArrayMovies,TAMMOVIES);
            printf("Archivo creado con exito!\n");
            system("pause");
            system("cls");
        }

        fclose(data);
    }
    else
    {
        fread(punteroArrayMovies,sizeof(EMovie),TAMMOVIES,data);
        printf("Archivo abierto correctamente!\n");
        fclose(data);
        system("pause");
        system("cls");
    }

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            altaPelicula(punteroArrayMovies,TAMMOVIES);
            break;

        case 2:
            bajaPelicula(punteroArrayMovies,TAMMOVIES);
            break;

        case 3:
            generarPagina(punteroArrayMovies,TAMMOVIES);
            break;

        case 4:
            data=fopen("data.bin","wb");
            fwrite(punteroArrayMovies,sizeof(EMovie),TAMMOVIES,data);
            fclose(data);
            seguir = 'n';
            break;
        }
    }
    return 0;
}
