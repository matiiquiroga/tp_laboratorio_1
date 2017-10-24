#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define TAMMOVIES 20

int main()
{
    char seguir='s';
    int opcion=0;
    char guardar='s';
    EMovie arrayMovies[TAMMOVIES];

    inicializarEstados(arrayMovies);

	if(cargarDesdeArchivo(arrayMovies))
	{
		printf("No se pudo abrir el archivo\n");
	}
	else
	{
		printf("Se cargaron las estructuras con exito\n");
	}

	system("pause");

	system("cls");

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
            altaPelicula(arrayMovies);
            break;

        case 2:
            bajaPelicula(arrayMovies);
            break;

        case 3:
            generarPagina(arrayMovies);
            break;

        case 4:
            printf("DeseaGuarda los cambios? (s/n)");
            scanf("%c",&guardar);

            if(guardar == 's')
				{
					if(guardarEnArchivo(arrayMovies))
					{
						printf("\nNo se pudo abrir el fichero\n");
					}
					else
					{
						printf("\nSe guardo la informacion con exito\n");
					}
				}
            seguir = 'n';
            break;
        }
    }
    return 0;
}
