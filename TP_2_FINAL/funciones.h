#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int tam);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * \param tam el tamaño del array lista
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni, int tam);

/**
 * \brief inicializa el parametro estados de todo el array lista en 0
 * @param lista el array se pasa como parametro.
 * \param tam el tamaño del array lista
 *
 */
void inicializarEstados(EPersona lista[],int tam);

/**
 * \brief completa una persona del array lista
 * @param lista el array se pasa como parametro.
 * \param tam el tamaño del array lista
 *
 */
 void addNewPersona(EPersona lista[], int tam);

 /**
 * \brief realiza una baja a una persona del array lista
 * @param lista el array se pasa como parametro
 * \param tam el tamaño del array lista
 *
 */
void borrarPersona(EPersona lista[], int tam);

 /**
 * \brief imprime una persona del array lista por pantalla
 * @param lista el array se pasa como parametro
 * \param indice la ubicacion de la persona a mostrar en el array lista
 */
void printPersona(EPersona lista[], int indice);

/**
 * \brief ordena el array lista por nombre alfabeticamente
 * @param lista el array se pasa como parametro
 * \param tam el tamaño del array lista
 *
 */
 void ordenarLista(EPersona lista[], int tam);

/**
 * \brief imprime todas las personas con estado 1 del array lista
 * @param lista el array se pasa como parametro
 * \param tam el tamaño del array lista
 *
 */
void printLista(EPersona lista[], int tam);


#endif // FUNCIONES_H_INCLUDED
