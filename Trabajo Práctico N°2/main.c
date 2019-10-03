#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"

#define TAM 1000

int main()
{
    Employee listEmployee[TAM];
    int employeeID = 1000;
    int checkTrue;
    char follow = 'n';

    initEmployees(listEmployee, TAM);

    do
    {
        switch(menu())
        {
        case 1:
            if(newEmployee(listEmployee, TAM, employeeID))
            {
                employeeID++;
            }
            break;

        case 2:
            checkTrue = checkEmployee(listEmployee, TAM);
            if (checkTrue == 1)
            {
                modifyEmployee(listEmployee, TAM);
            }
            else
            {
                printf("\nNo hay empleados activos para realizar esta operacion.\n");
            }
            break;

        case 3:
            checkTrue = checkEmployee(listEmployee, TAM);
            if (checkTrue == 1)
            {
                removingEmployee(listEmployee, TAM);
            }
            else
            {
                printf("\nNo hay empleados activos para realizar esta operacion.\n");
            }
            break;

        case 4:
            checkTrue = checkEmployee(listEmployee, TAM);
            if (checkTrue == 1)
            {
                reportEmployees(listEmployee, TAM);
            }
            else
            {
                printf("\nNo hay empleados activos para realizar esta operacion.\n");
            }
            break;

        case 5:
            printf("\n\nConfirmar salida (y/n): ");
            fflush(stdin);
            follow = getchar();
            follow = tolower(follow);
            printf("\n");
            while(follow != 'y' && follow != 'n')
            {
                printf("\nError, reingrese: \n");
                fflush(stdin);
                follow = getchar();
                follow = tolower(follow);
            }
            break;

        default:
            system("cls");
            printf("Opcion elegida invalida, volviendo al menu...\n");
            break;
        }
        printf("\n\n");
        system("pause");
    }
    while (follow == 'n');

    return 0;
}
