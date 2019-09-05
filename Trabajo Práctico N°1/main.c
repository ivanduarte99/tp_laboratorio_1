#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "duarte.h"

int main()
{
    char salir = 'n';
    float a = 0;
    float b = 0;
    float resultadoSum;
    float resultadoRes;
    float resultadoDiv;
    float resultadoMult;
    long long factoA;
    long long factoB;

    do{
        switch(menuOpciones(&a, &b))
        {
            case '1':
                printf("\nIngrese el primer operador: ");
                scanf("%f", &a);
                break;
            case '2':
                printf("\nIngrese el segundo operador: ");
                scanf("%f", &b);
                break;
            case '3':
                resultadoSum = sumar(a, b);
                printf("\nLa suma de %.2f + %.2f es: %.2f\n", a, b, resultadoSum);
                break;
            case '4':
                resultadoRes = restar(a, b);
                printf("\nLa resta de %.2f - %.2f es: %.2f\n", a, b, resultadoRes);
                break;
            case '5':
                resultadoDiv = dividir(a, b);
                if(resultadoDiv == -1)
                {
                    printf("\nNo es posible dividir por 0\n");
                }else
                {
                    printf("\nLa division de %.2f / %.2f es: %.2f\n", a, b, resultadoDiv);
                }
                break;
            case '6':
                resultadoMult = multiplicar(a, b);
                printf("\nLa multiplicacion de %.2f * %.2f es: %.2f\n", a, b, resultadoMult);
                break;
            case '7':
                factoA = factorial(a);
                factoB = factorial(b);
                if(factoA == -1 || factoB == -1)
                {
                    printf("\nError, los factoriales de los numeros negativos no existen\n");
                }else
                {
                    printf("\nEl factorial de %.2f es: %lli y el de %.2f es: %lli\n", a, factoA, b, factoB);
                }
                break;
            case '8':
                todas(a, b);
                break;
            case '9':
                printf("\nConfirma salida? ");
                fflush(stdin);
                salir = getchar();
                break;
            default:
                printf("\nOpcion invalida\n");
                fflush(stdin);
                break;
        }
        system("pause");

    }while(salir == 'n');

    return 0;
}
