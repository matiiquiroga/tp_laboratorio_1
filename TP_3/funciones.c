#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void inicializarEstados(EMovie lista[])
{
    int i;

    for(i=0; i<20; i++)
    {
        lista[i].estado=0;
    }
}

int obtenerEspacioLibre(EMovie listaMovie[])
{
    int i;
    int flag=0;
    int espacioLibre;

    for(i=0; i<20; i++)
    {
        if(listaMovie[i].estado==0)
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

void altaPelicula(EMovie listaMovies[])
{
    int i;
    int indice;
    int flag=0;
    char titulo[50];
    char linky[100];

    indice=obtenerEspacioLibre(listaMovies);

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

        for(i=0; i<20; i++)
        {
            if(strcmpi(titulo,listaMovies[i].titulo) ==0)
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
            strcpy(listaMovies[indice].titulo,titulo);

            printf("Ingrese genero: ");
            fflush(stdin);
            gets(listaMovies[indice].genero);

            printf("Ingrese Duracion en minutos: ");
            scanf("%d",&listaMovies[indice].duracion);

            printf("Ingrese descripcion: ");
            fflush(stdin);
            gets(listaMovies[indice].descripcion);

            printf("Ingrese puntaje: ");
            scanf("%d", &listaMovies[indice].puntaje);

            printf("Ingrese el link de la imagen de la pelicula: ");
            fflush(stdin);
            gets(linky);
            fflush(stdin);
            strcpy(listaMovies[indice].linkImagen,linky);

            printf("\n\nPelicula agregada con exito!\n\n");
            system("pause");
        }
    }
}

void bajaPelicula(EMovie* listaMovies)
{
    char auxTitulo[50];
    int i;
    char opcion;

    printf("\nIngrese el titulo de la pelicula que desea eliminar: ");
    gets(auxTitulo);

    for (i=0; i<20; i++)
    {
        if(strcmpi(auxTitulo,listaMovies[i].titulo)==0 && listaMovies[i].estado!=0)
        {
            printf("\nPelicula a eliminar: \n\n");
            mostrarPelicula((listaMovies + i));

            printf("\nConfirma la eliminacion: (s/n)\n");
            scanf("%c", &opcion);

            if(opcion=='s')
            {
                listaMovies[i].estado=0;
                printf("\nPelicula eliminada con exito!!");
            }
            else
            {
                printf("La eliminacion fue cancelada con exito!");
            }
            break;
        }
        else
        {
            printf("El titulo no se encontro ingresado en el sistema");
        }
    }
}

/*void modificarPelicula(EMovie* listaMovies)
{
    char auxTitulo[50];
    int i;

    printf("\nIngrese el titulo de la pelicula que desea modificar: ");
    gets(auxTitulo);

    for (i=0;i<20;i++)
    {
        if(strcmpi(auxTitulo,listaMovies[i].titulo)==0 && listaMovies[i].estado!=0)
        {
            printf("\nIngrese nuevo titulo: ");
        }
    }

    me di cuenta despeus de que lo habia empezado que la modificacion no entraba en el tp.
}*/

void generarPagina(EMovie* listaMovie)
{
    FILE* html;
    int i;

    if((html=fopen("Web.html","w"))==NULL)
    {
        printf("\nLa pagina no pudo ser creada");
        exit(1);
    }
    else
    {
        for(i=0; i<20; i++)
        {
            if(listaMovie[i].estado!=0)
            {
                fprintf(html,"<article class='col-md-4 article-intro'>\n<a href='#'>\n<img class='img-responsive img-rounded' src='%s' alt=''>\n</a>\n<h3>\n<a href='#'>%s</a>\n</h3>\n<ul>\n<li>Género:%s</li>\n<li>Puntaje:%d</li>\n<li>Duración:%d</li>\n</ul>\n <p>%s</p>\n</article>",(listaMovie+i)->linkImagen,(listaMovie+i)->titulo,(listaMovie+i)->genero,(listaMovie+i)->puntaje,(listaMovie+i)->duracion,(listaMovie+i)->descripcion);
            }
        }
        printf("Pagina creada con exito!\n");
    }
    fclose(html);
}

int guardarEnArchivo(EMovie* movie)
{
    FILE *data;

    data=fopen("bin.dat","wb");

    if(data == NULL)
    {
        return 1;
    }

    fwrite(movie,sizeof(EMovie),20,data);

    fclose(data);

    return 0;
}

int cargarDesdeArchivo(EMovie* Movie)
{
    int flag= 0;
	FILE *data;

	data=fopen("bin.dat", "rb");

	if(data==NULL)
	{
		data=fopen("bin.dat", "wb");

		if(data==NULL)
		{
			return 1;
		}

		flag=1;
	}

	if(flag==0)
	{
        fread(Movie,sizeof(EMovie),20,data);
    }

	fclose(data);

	return 0;
}
