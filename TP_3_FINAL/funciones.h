#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[250];
    int puntaje;
    char linkImagen[250];
    int estado;
}EMovie;

void inicializarEstados(EMovie*, int);

int obtenerEspacioLibre(EMovie*,int);

void mostrarPelicula(EMovie*);

void altaPelicula(EMovie*,int);

int buscarMovie(EMovie*,int,char[]);

void bajaPelicula(EMovie*,int);

void generarPagina(EMovie*,int);

#endif // FUNCIONES_H_INCLUDED
