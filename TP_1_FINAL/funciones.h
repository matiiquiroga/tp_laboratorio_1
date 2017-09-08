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
float resta (float x, float y);

/**
* \brief Realiza una division entre dos numeros
* \param Primer numero ingresado
* \param Segundo numero ingresado
* \return el resultado del calculo
*/
float division(float x, float y);

/**
* \brief Realiza una multiplicacion entre dos numeros
* \param Primer numero ingresado
* \param Segundo numero ingresado
* \return el resultado del calculo
*/
float multiplicacion(float x, float y);

/**
* \brief Realiza el factorial de un numero
* \param numero a factorizar
* \return el resultado del calculo
*/
float factorial(float x);

/**
* \brief Solicita un float al usuario
* \param mensaje a ser mostrado en pantalla para solicitar float
* \return el numero ingresado
*/
float getFloat(char mensaje[]);

/**
* \brief Verifica si el numero ingresado es 0 o no lo es
* \param el numero ingresado a verificar
* \return 0 si es igual a 0 o 1 si no es 0
*/
int verificaCero(float);

/**
* \brief recibe dos numeros, calcula y muestra por pantalla los resultados
* \param el primer numero ingresado a calcular para mostrar
* \param el segundo numero ingresado a calcular para mostrar
*/
void showAllOperations(float x, float y);
#endif // FUNCIONES_H_INCLUDED
