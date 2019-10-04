#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "empleado.h"
#include "input.h"
#include "sector.h"
#define TAM 2
#define CANT_EMP 5
#define CANT_SECT 5

int main()
{
    char seguir = 's';
    char confirma;
    eEmpleado lista[TAM];
    inicializarEmpleados(lista, TAM); // llamada

    do
    {
        switch(menu())
        {
        case 1:
            printf("\nAlta empleado\n\n");
            altaEmpleado(lista, TAM);
            system("pause");
            break;

        case 2:
            printf("\nBaja empleado\n\n");
            bajaEmpleado(lista, TAM);
            system("pause");
            break;

        case 3:
            printf("\nModificacion empleado\n\n");
            ModificacionEmpleado(lista,TAM);
            system("pause");
            break;

        case 4:
            printf("\nOrdenar empleados\n\n");
            Ordenar(lista,TAM);
            system("pause");
            break;

        case 5:
            printf("\nListar empleados\n\n");
            mostrarEmpleados(lista, TAM);
            system("pause");
            break;

        case 6:
            printf("\nConfirma salida s/n?: ");

            setbuf(stdin,NULL);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            else if(tolower(confirma) == 'n')
            {
                seguir = 's';
            }
            else
            {
                printf("\nERROR, ingrese S para salir o N para quedarse \n");
                system("pause");
            }
            break;

        default:
            printf("Opcion invalida\n\n");
            system("pause");
            system("break");
        }
    }
    while(seguir == 's');

    return 0;
}
