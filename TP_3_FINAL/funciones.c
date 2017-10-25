#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void inicializarEstados(EMovie* listaMovie, int tamMovie)
{
    int i;

    for(i=0; i<tamMovie; i++)
    {
        (listaMovie+i)->estado=0;
    }
}

int obtenerEspacioLibre(EMovie* listaMovie,int tamMovies)
{
    int i;
    int flag=0;
    int espacioLibre;

    for(i=0; i<tamMovies; i++)
    {
        if((listaMovie+i)->estado==0)
        {
            espacioLibre=i;
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        espacioLibre=-1;
    }

    return espacioLibre;
}

void mostrarPelicula(EMovie* pelicula)
{
    printf("\nTitulo: %s\nGenero: %s\nDuracion: %d\nDescripcion: %s\nPuntaje: %d\nLink de imagen: %s\n", pelicula->titulo, pelicula->genero, pelicula->duracion, pelicula->descripcion, pelicula->puntaje,pelicula->linkImagen);
}

void altaPelicula(EMovie* listaMovies, int tamMovies)
{
    int i;
    int indice;
    int flag=0;
    char titulo[50];

    indice=obtenerEspacioLibre(listaMovies,tamMovies);

    if(indice== -1)
    {
        printf("\nNo hay lugar disponible!\n\n");
        system("pause");
    }
    else
    {
        printf("\n\nIngrese titulo: ");
        fflush(stdin);
        gets(titulo);

        for(i=0; i<tamMovies; i++)
        {
            if(strcmpi(titulo,(listaMovies+i)->titulo)==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            printf("\n\nEsa pelicula ya se encuentra ingresada en el sistema.\n\n");
            system("pause");
        }
        else
        {
            strcpy((listaMovies+indice)->titulo,titulo);

            printf("Ingrese genero: ");
            fflush(stdin);
            gets((listaMovies+indice)->genero);

            printf("Ingrese Duracion en minutos: ");
            scanf("%d",&(listaMovies+indice)->duracion);

            printf("Ingrese descripcion: ");
            fflush(stdin);
            gets((listaMovies+indice)->descripcion);

            printf("Ingrese puntaje: ");
            scanf("%d", &(listaMovies+indice)->puntaje);

            printf("Ingrese el link de la imagen de la pelicula: ");
            fflush(stdin);
            gets((listaMovies+indice)->linkImagen);

            (listaMovies+indice)->estado=1;

            printf("\n\nPelicula agregada con exito!\n\n");
            system("pause");
        }
    }
}

int buscarMovie(EMovie* listaMovies,int tamMovies, char coincidencia[20])
{
    int indice=-1;
    int i;

    for(i=0; i<tamMovies; i++)
    {
        if(strcmpi((listaMovies+i)->titulo,coincidencia)==0 && (listaMovies+i)->estado!=0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void bajaPelicula(EMovie* listaMovies, int tamMovies)
{
    char auxTitulo[50];
    int i;
    char opcion;

    printf("\nIngrese el titulo de la pelicula que desea eliminar: ");
    gets(auxTitulo);

    i=buscarMovie(listaMovies,tamMovies,auxTitulo);

    if(i!=-1)
    {
        printf("\nPelicula a eliminar: \n\n");
        mostrarPelicula((listaMovies+i));

        printf("\nConfirma la eliminacion: (s/n)\n");
        scanf("%c", &opcion);

        if(opcion=='s')
        {
            (listaMovies+i)->estado=0;
            printf("\nPelicula eliminada con exito!!");
        }
        else
        {
            printf("La eliminacion fue cancelada con exito!");
        }
    }
    else
    {
        printf("El titulo no se encontro ingresado en el sistema");
    }
}

void generarPagina(EMovie* listaMovies,int tamMovies)
{
    FILE* htmlView;
    int i;

    if((htmlView=fopen("Web.html","w"))==NULL)
    {
        printf("\nLa pagina no pudo ser creada");
        exit (1);
    }
    else
    {
        for(i=0; i<tamMovies; i++)
        {
            if((listaMovies+i)->estado!=0)
            {
                fprintf(htmlView,"<article class='col-md-4 article-intro'>\n<a href='#'>\n<img class='img-responsive img-rounded' src='%s' alt=''>\n</a>\n<h3>\n<a href='#'>%s</a>\n</h3>\n<ul>\n<li>Género:%s</li>\n<li>Puntaje:%d</li>\n<li>Duración:%d</li>\n</ul>\n <p>%s</p>\n</article>",(listaMovies+i)->linkImagen,(listaMovies+i)->titulo,(listaMovies+i)->genero,(listaMovies+i)->puntaje,(listaMovies+i)->duracion,(listaMovies+i)->descripcion);
            }
        }
        printf("Pagina creada con exito!\n");
        system("pause");
    }
    fclose(htmlView);
}
