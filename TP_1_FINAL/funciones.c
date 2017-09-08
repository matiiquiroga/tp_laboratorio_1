#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float suma(float x, float y)
{
    float resultado;
    resultado= x+y;
    return resultado;
}

float resta (float x, float y)
{
    float resultado;
    resultado= x-y;
    return resultado;
}

float division(float x, float y)
{
    float resultado;
    resultado= x/y;
    return resultado;
}

float multiplicacion(float x, float y)
{
    float resultado;
    resultado= x*y;
    return resultado;
}

float factorial(float x)
{
    float resultado;
    if(x==1)
        return 1;
    resultado=x*factorial(x-1);
    return resultado;
}

float getFloat(char mensaje[])
{
    float x;
    printf("%s", mensaje);
    scanf("%f", &x);
    return x;
}

int verificaCero(float x)
{
    if (x != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void showAllOperations(float x, float y)
{
            float result;
            result=suma(x, y);
            printf("\nEl resultado de la suma de %f y %f: %f\n", x, y, result);
            result= resta(x, y);
            printf("\nEl resultado de la resta de %f y %f: %f\n", x, y, result);
            result=division(x, y);
            printf("\nEl resultado de la division de %f y %f: %f\n", x, y, result);
            result=multiplicacion(x, y);
            printf("\nEl resultado de la multiplicacion de %f y %f: %f\n", x, y, result);
            result= factorial(x);
            printf("\nEl resultado del factorial de %f: %f\n\n", x, result);
            system("pause");
            system("cls");
}
