#include "duarte.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

float sumar(float a, float b)
{
    return a + b;
}

float restar(float a, float b)
{
    return a - b;
}

float dividir(float a, float b)
{
    float resultado;

    if (b == 0)
    {
        resultado = -1;
    }else
    {
        resultado = a / b;
    }

    return resultado;
}

float multiplicar(float a, float b)
{
    return a * b;
}

int factorial(int a)
{
    int resultado = 1;

    if(a < 0)
    {
        return -1;
    }else
    {
        for (int i = a; i >= 1; i--)
        {
            resultado *= i;
        }
    }

    return resultado;
}

int menuOpciones(float* a, float* b)
{
    int opcion;

    system("cls");
    printf("-----Menu de Opciones-----\n");
    printf("1- Ingresar 1er operando (A = %.2f)\n", *a);
    printf("2- Ingresar 2do operando (B = %.2f)\n", *b);
    printf("3- Sumar\n");
    printf("4- Restar\n");
    printf("5- Dividir\n");
    printf("6- Multipliplicar\n");
    printf("7- Factorial\n");
    printf("8- Calcular todas las operaciones\n");
    printf("9- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = getche();

    return opcion;
}

void todas(float a, float b)
{
    float sum;
    float res;
    float div;
    float mult;
    long long factoA;
    long long factoB;

    sum = sumar(a, b);
    printf("\nLa suma de %.2f + %.2f es: %.2f\n", a, b, sum);

    res = restar(a, b);
    printf("\nLa resta de %.2f - %.2f es: %.2f\n", a, b, res);

    div = dividir(a, b);
    if(div == -1)
    {
        printf("\nNo se realizo la operacion porque no se puede dividir por 0\n");
    }else
    {
        printf("\nLa division de %.2f / %.2f es: %.2f\n", a, b, div);
    }

    mult = multiplicar(a, b);
    printf("\nLa multiplicacion de %.2f * %.2f es: %.2f\n", a, b, mult);

    factoA = factorial(a);
    factoB = factorial(b);
    if(factoA == -1 || factoB == -1)
    {
        printf("\nError, los factoriales de los numeros negativos no existen\n");
    }else
    {
        printf("\nEl factorial de %.2f es: %lli y el de %.2f es: %lli\n", a, factoA, b, factoB);
    }
}
