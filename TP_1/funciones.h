#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/**
* \brief Realiza una suma entre dos numeros
* \param Primer numero ingresado
* \param Segundo numero ingresado
* \return el resultado del calculo
*/
float suma(float x, float y);

/**
* \brief Realiza una resta entre dos numeros
* \param Primer numero ingresado
* \param Segundo numero ingresado
* \return el resultado del calculo
*/
float resta (int x, int y);

/**
* \brief Realiza una division entre dos numeros
* \param Primer numero ingresado
* \param Segundo numero ingresado
* \return el resultado del calculo
*/
float division(int x, int y);

/**
* \brief Realiza una multiplicacion entre dos numeros
* \param Primer numero ingresado
* \param Segundo numero ingresado
* \return el resultado del calculo
*/
float multiplicacion(int x, int y);

/**
* \brief Realiza el factorial de un numero
* \param numero a factorizar
* \return el resultado del calculo
*/
float factorial(int x);

/**
* \brief Solicita un float al usuario
*
* \return el numero ingresado
*/
float getFloat(char mensaje[]);

/**
* \brief Verifica si el numero ingresado es 0 o no lo es
* \param el numero ingresado a verificar
* \return 0 si es igual a 0 o 1 si no es 0
*/
int verificaCero(float);

#endif // FUNCIONES_H_INCLUDED
