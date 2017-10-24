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

//void modificarPelicula(EMovie*);

void inicializarEstados(EMovie*);

int obtenerEspacioLibre(EMovie*);

void altaPelicula(EMovie*);

void mostrarPelicula(EMovie*);

void bajaPelicula(EMovie*);

void generarPagina(EMovie*);

int guardarEnArchivo(EMovie*);

int cargarDesdeArchivo(EMovie*);

#endif // FUNCIONES_H_INCLUDED
