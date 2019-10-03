#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"
int menu()
{
    int option;
    system("cls");

    printf("***** ABM UTNFRA *****\n\n");
    printf("1) Altas\n");
    printf("2) Modificar\n");
    printf("3) Bajas\n");
    printf("4) Informes \n");
    printf("5) Salir\n\n");
    printf("Opcion elegida: ");
    fflush(stdin);
    scanf("%d", &option);
    return option;
}

int modifyMenu(Employee employees[], int len, int id)
{
    int option;
    int indice;

    indice = findEmployeeById(employees, len, id);
    printf("Ingrese ID del empleado a modificar: %d\n", id);
    system("cls");
    printf("-ID-     -NOMBRE-        -APELLIDO-        -SALARIO-       -SECTOR-\n");
    printEmployee(employees[indice]);
    printf("\n");

    printf("***** MODIFICAR EMPLEADO *****\n\n");
    printf("1) Modificar Nombre\n");
    printf("2) Modificar Apellido\n");
    printf("3) Modificar Salario\n");
    printf("4) Modificar Sector\n");
    printf("5) Salir\n\n");
    printf("Opcion elegida: ");
    scanf("%d", &option);

    return option;
}

void modifyMenuOptions(Employee employees[], int tam, int id)
{
    char follow = 'n';
    char name[51];
    char lastName[51];
    char resp;
    int salary;
    int sector;
    int index;

    index = findEmployeeById(employees, tam, id);

    do
    {
        switch(modifyMenu(employees, tam, id))
        {

        case 1:
            printf("Ingrese el nuevo nombre (max 51 caracteres): ");
            fflush(stdin);
            gets(name);
            while (strlen(name) > 20)
            {
                printf("Error, reingrese nombre (max 51 caracteres): ");
                gets(name);
            }

            printf("Confirma el cambio? (y/n): ");
            fflush(stdin);
            resp = getchar();
            resp = tolower(resp);
            while (resp != 'y' && resp != 'n')
            {
                printf("Error, reintente (y/n): ");
                fflush(stdin);
                resp = getchar();
                resp = tolower(resp);
            }
            if (resp == 'y')
            {
                strcpy(employees[index].name, name);
                printf("Nombre modificado exitosamente.\n\n");
                system("pause");
            }
            else
            {
                printf("Se cancelo la operacion.\n\n");
                system("pause");
            }
            break;

        case 2:
            printf("Ingrese el nuevo apellido (max 51 caracteres): ");
            fflush(stdin);
            gets(lastName);
            while (strlen(lastName) > 20)
            {
                printf("Error, reingrese apellido (max 51 caracteres): ");
                gets(lastName);
            }

            printf("Confirma el cambio? (y/n): ");
            fflush(stdin);
            resp = getchar();
            resp = tolower(resp);
            while (resp != 'y' && resp != 'n')
            {
                printf("Error, reintente (y/n): ");
                fflush(stdin);
                resp = getchar();
                resp = tolower(resp);
            }
            if (resp == 'y')
            {
                strcpy(employees[index].lastName, lastName);
                printf("Apellido modificado exitosamente.\n\n");
                system("pause");
            }
            else
            {
                    printf("Se cancelo la operacion.\n\n");
                    system("pause");
            }
            break;

        case 3:
            printf("Ingrese el nuevo salario (16000-100000): ");
            scanf("%d", &salary);
            while ((salary < 16000 || salary > 100000))
            {
                printf("Error, reingrese salario (16000-100000): ");
                scanf("%d", &salary);
            }

            printf("Confirma el cambio? (y/n): ");
            fflush(stdin);
            resp = getchar();
            resp = tolower(resp);
            while (resp != 'y' && resp != 'n')
            {
                printf("Error, reintente (y/n): ");
                fflush(stdin);
                resp = getchar();
                resp = tolower(resp);
            }
            if (resp == 'y')
            {
                employees[index].salary = salary;
                printf("Salario modificado exitosamente.\n\n");
                system("pause");
            }
            else
            {
                printf("Se cancelo la operacion.\n\n");
                system("pause");
            }
            break;

        case 4:
            printf("Ingrese el nuevo sector (1-5): ");
            scanf("%d", &sector);
            while ((sector > 5 || sector < 1))
            {
                printf("Error, reingrese sector (1-5): ");
                scanf("%d", &sector);
            }

            printf("Confirma el cambio? (y/n): ");
            fflush(stdin);
            resp = getchar();
            resp = tolower(resp);
            while (resp != 'y' && resp != 'n')
            {
                printf("Error, reintente (y/n): ");
                fflush(stdin);
                resp = getchar();
                resp = tolower(resp);
            }
            if (resp == 'y')
            {
                employees[index].sector = sector;
                printf("Sector modificado exitosamente.\n\n");
                system("pause");
            }
            else
            {
                    printf("Se cancelo la operacion.\n\n");
                    system("pause");
            }
            break;

        case 5:
            printf("Confirma que desea salir? (y/n): ");
            fflush(stdin);
            follow = getchar();
            resp = tolower(resp);
            while(follow != 'y' && follow != 'n')
            {
                printf("Error, reintente (y/n): \n");
                fflush(stdin);
                follow = getchar();
                resp = tolower(resp);
            }
            break;

        default:
            printf("Error, opcion no existe\n");
            system("pause");
            break;
        }
    }
    while(follow == 'n');
}

Employee addEmployee(int id, char name[],char lastName[],float salary,int sector)
{
    Employee newEmployee;

    newEmployee.id = id;
    strcpy(newEmployee.name, name);
    strcpy(newEmployee.lastName, lastName);
    newEmployee.salary = salary;
    newEmployee.sector = sector;
    newEmployee.isEmpty = 0;
    return newEmployee;
}

int initEmployees(Employee employees[], int len)
{
    int isOk = 0;
    for (int i = 0; i < len; i++)
    {
        employees[i].isEmpty = 1;
        isOk = 1;
    }
    return isOk;
}

int newEmployee(Employee employees[], int len, int id)
{
    int isOk = 0;
    int flag = 0;
    int index;
    int salary;
    int sector;
    char checkIn = 'x';
    char name[51];
    char lastName[51];
    char auxCad[100];

    system("cls");
    printf("*****  ALTAS DE EMPLEADOS  *****\n\n");
    index = searchEmpty(employees, len);
    if (index == -1)
    {
        printf("Error, no hay espacio para ingresar mas empleados.\n");
    }
    else
    {
        while (checkIn == 'x' || flag == 0)
        {
            printf("Ingrese el nombre del empleado (max 51 caracteres): ");
            fflush(stdin);
            gets(auxCad);
            while(strlen(auxCad) > 20)
            {
                printf("Error, reingrese nombre (max 51 caracteres): ");
                fflush(stdin);
                gets(auxCad);
            }
            strcpy(name, auxCad);
            printf("\n");

            printf("Ingrese el apellido del empleado (max 51 caracteres): ");
            fflush(stdin);
            gets(auxCad);
            while(strlen(auxCad) > 20)
            {
                printf("Error, reingrese nombre (max 51 caracteres): ");
                fflush(stdin);
                gets(auxCad);
            }
            strcpy(lastName, auxCad);
            printf("\n");

            printf("Ingrese el salario del empleado(16000-100000): ");
            scanf("%d", &salary);
            while (salary > 100000 || salary < 16000)
            {
                printf("Error, reingrese salario(16000-100000): ");
                scanf("%d", &salary);
            }
            printf("\n");

            printf("Ingrese el sector del empleado (1-5): ");
            scanf("%d", &sector);
            while (sector < 1 || sector > 5)
            {
                printf("Error, reingrese sector: ");
                scanf("%d", &sector);
            }
            flag = 1;
            checkIn = 'y';
        }
        if (checkIn == 'y')
        {
            employees[index] = addEmployee(id, name, lastName, salary, sector);
            printf("Empleado ingresado exitosamente.");
            isOk = 1;
        }
        else
        {
            printf("Error, no se pudo ingresar el empleado.");
        }
    }

    return isOk;
}

int findEmployeeById(Employee employees[], int len, int id)
{
    int index = -1;
    for(int i = 0; i < len; i++)
    {
        if (employees[i].isEmpty == 0 && employees[i].id == id)
        {
            index = i;
            break;
        }
    }

    return index;
}

int searchEmpty(Employee employees[], int len)
{
    int index = -1;
    for(int i = 0; i < len; i++)
    {
        if (employees[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}

int removeEmployee(Employee employees[], int len, int id)
{
    int follow = 0;
    char resp;
    int index;

    system("cls");
    printf("-ID-     -NOMBRE-        -APELLIDO-        -SALARIO-       -SECTOR-\n");
    index = findEmployeeById(employees, len, id);
    printEmployee(employees[index]);
    printf("\nConfirma la baja? (y/n): ");
    fflush(stdin);
    resp = getchar();
    resp = tolower(resp);
    while(resp != 'y' && resp != 'n')
    {
        printf("\nError, reingrese (y/n): ");
        fflush(stdin);
        resp = getchar();
        resp = tolower(resp);
    }
    if (resp == 'y')
    {
        employees[index].isEmpty = 1;
        printf("Se dio de baja al empleado exitosamente.");
        follow = 1;
    }
    else
    {
        printf("Operacion cancelada.");
    }

    return follow;
}

int sortEmployees(Employee employees[], int len)
{
    int isOk = 0;
    char auxCad[51];
    int auxSal;
    int auxId;
    int auxSector;
    int swap = 0;
    char auxLastName1;
    char auxLastName2;

    for(int i = 0; i < len - 1; i++)
    {
        for(int j = i + 1; j < len; j++)
        {
            auxLastName1 = employees[i].lastName[0];
            auxLastName2 = employees[j].lastName[0];

            if((employees[i].sector > employees[j].sector) && (employees[i].isEmpty == 0 && employees[j].isEmpty == 0))
            {
                swap = 1;
            }
            else if((employees[i].sector == employees[j].sector) && (employees[i].isEmpty == 0 && employees[j].isEmpty == 0) && (auxLastName1 > auxLastName2))
            {
                swap = 1;
            }

            if(swap == 1)
            {
                strcpy(auxCad, employees[i].lastName);
                strcpy(employees[i].lastName, employees[j].lastName);
                strcpy(employees[j].lastName, auxCad);

                auxSector = employees[i].sector;
                employees[i].sector = employees[j].sector;
                employees[j].sector = auxSector;

                strcpy(auxCad, employees[i].name);
                strcpy(employees[i].name, employees[j].name);
                strcpy(employees[j].name, auxCad);

                auxSal = employees[i].salary;
                employees[i].salary = employees[j].salary;
                employees[j].salary = auxSal;

                auxId = employees[i].id;
                employees[i].id = employees[j].id;
                employees[j].id = auxId;
                isOk = 1;
            }
            swap = 0;
        }
    }

    return isOk;
}

int checkEmployee(Employee employees[], int len)
{
    int isOk = 0;
    for(int i = 0; i < len; i++)
    {
        if (employees[i].isEmpty == 0)
        {
            isOk = 1;
        }
    }
    return isOk;
}

void printEmployee(Employee employeeX)
{
    printf("%d   %10s        %10s         %.2f          %02d\n",
           employeeX.id,
           employeeX.name,
           employeeX.lastName,
           employeeX.salary,
           employeeX.sector);
}

void printEmployees(Employee employees[], int len)
{
    int flag = 0;

    printf("\n\n-ID-      -NOMBRE-       -APELLIDO-        -SALARIO-       -SECTOR-\n");

    for(int i=0; i < len; i++)
    {
        if(employees[i].isEmpty == 0)
        {
            printEmployee(employees[i]);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        system("cls");
        printf("\nNo se han encontrados empleados en el sistema.\n");
    }

    printf("\n");
}

void removingEmployee(Employee employees[], int len)
{
    int auxID;
    int indice;

    system("cls");
    printf("***** EMPLEADOS ACTIVOS *****");
    printEmployees(employees, len);
    printf("Ingrese ID del empleado a dar de baja: ");
    scanf("%d", &auxID);
    indice = findEmployeeById(employees, len, auxID);
    if (indice == -1)
    {
        printf("El ID ingresado no existe o no esta activo.\n\n");
    }
    else
    {
        removeEmployee(employees, len, auxID);
    }
}

void modifyEmployee(Employee employees[], int len)
{
    int auxID;
    int indice;

    system("cls");
    printf("***** EMPLEADOS ACTIVOS *****");
    printEmployees(employees, len);
    printf("Ingrese ID del empleado a modificar: ");
    scanf("%d", &auxID);
    indice = findEmployeeById(employees, len, auxID);
    if (indice == -1)
    {
        printf("\nEl ID ingresado no existe o no esta activo.");
    }
    else
    {
        modifyMenuOptions(employees, len, auxID);
    }
}

void sortEmployeesProm(Employee employees[], int len)
{
    float promedio;
    float mayor;
    int cantEmployee = 0;
    int counter = 0;
    int acumulador = 0;

    for (int i = 0; i < len; i++)
    {
        if (employees[i].isEmpty == 0)
        {
            cantEmployee++;
        }
    }
    for(int i = 0; i < cantEmployee; i++)
    {
        acumulador += employees[i].salary;
        promedio = acumulador / cantEmployee;
        if(mayor < employees[i].salary && employees[i].isEmpty == 0)
        {
            mayor = employees[i].salary;
        }
    }
    for (int i = 0; i < len; i++)
    {
        if(employees[i].salary > promedio && employees[i].isEmpty == 0)
        {
            counter++;
        }
    }

    printf("***** PROMEDIO DE SALARIOS Y LOS QUE LO SUPERAN *****\n\n");
    printf("Salarios : %d\n", acumulador);
    printf("Promedio de salarios: %.2f\n", promedio);
    printf("Empleados que superan el salario promedio: %d\n\n", counter);
    counter = 0;
    system("pause");
}

void reportEmployees(Employee employees[], int len)
{
    char salir = 'y';
    int option;
    int sort;
    int flag = 0;
    do
    {
        system("cls");
        printf("***** INFORMES EMPLEADOS *****\n\n");
        printf("1) Empleados ordenados por apellido y sector\n");
        printf("2) Total y promedio de los salarios y cuantos empleados superan el salario promedio\n");
        printf("3) Salir\n\n");
        printf("Su opcion: ");
        fflush(stdin);
        scanf("%d", &option);
        while (option != 1 && option != 2 && option != 3)
        {
            printf("Error, reintente: ");
            fflush(stdin);
            scanf("%d", &option);
        }

        switch(option)
        {
        case 1:
            sort = sortEmployees(employees, len);
            if (sort == 1 || flag == 1)
            {
                system("cls");
                printf("***** EMPLEADOS ORDENADOS *****\n");
                printEmployees(employees, len);
                system("pause");
                flag = 1;
            }
            else
            {
                printf("Error, no se pudo ordenar a los empleados.\n");
                system("pause");
            }
            break;

        case 2:
            system("cls");
            sortEmployeesProm(employees, len);
            break;

        case 3:
            salir = 'n';
            break;
        }
    }
    while(salir == 'y');
}
