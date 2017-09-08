#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float operandoA=0;
    float operandoB=0;
    float resultado=0;
    int flagMenu=0;
    int flagMenuDos=0;
    int flagDivisor;

    while(seguir=='s')
    {
        if(flagMenu==0)
        {
            printf("1- Ingresar 1er operando (A=x)\n");
            flagMenu=1;
        }
        else if(flagMenu!=0)
            printf("1- Ingresar 1er operando (A=%f)\n", operandoA);

        if(flagMenuDos==0)
        {
            printf("2- Ingresar 2do operando (B=y)\n");
            flagMenuDos=1;
        }
        else if(flagMenuDos!=0)
            printf("2- Ingresar 2do operando (B=%f)\n", operandoB);

        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            operandoA=getFloat("\nIngreso del 1\247 numero: ");

            break;

        case 2:
            operandoB=getFloat("\nIngreso del 2\247 numero: ");
            flagDivisor=verificaCero(operandoB);
            break;

        case 3:
            resultado=suma(operandoA, operandoB);
            printf("\nEl resultado de la suma de %f y %f: %f\n", operandoA, operandoB, resultado);
            system("pause");
            system("cls");
            break;

        case 4:
            resultado= resta(operandoA, operandoB);
            printf("\nEl resultado de la resta de %f y %f: %f\n", operandoA, operandoB, resultado);
            system("pause");
            system("cls");
            break;

        case 5:
            if(flagDivisor==1)
            {
                resultado=division(operandoA, operandoB);
                printf("\nEl resultado de la division de %f y %f: %f\n", operandoA, operandoB, resultado);
            }
            else
            {
                printf("no se puede dividivir por cero, reingrese\n");
            }

            system("pause");
            system("cls");
            break;

        case 6:
            resultado=multiplicacion(operandoA, operandoB);
            printf("\nEl resultado de la multiplicacion de %f y %f: %f\n", operandoA, operandoB, resultado);
            system("pause");
            system("cls");
            break;

        case 7:
            resultado= factorial(operandoA);
            printf("\nEl resultado del factorial de %f: %f\n", operandoA, resultado);
            system("pause");
            system("cls");
            break;

        case 8:
            showAllOperations(operandoA, operandoB);
            break;

        case 9:
            seguir = 'n';
            break;
        }
    }

    return 0;
}
