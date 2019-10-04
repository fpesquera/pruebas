#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "empleado.h"
#include "input.h"
#include "sector.h"
/*
FALTA AGREGAR:
-TIENE PROBLEMAS CON EN AGREGAR SEXO EN LA FUNCION "ALTA"
-VERIFICAR FUNCION "MENU"
-VERIFICAR FUNCION "ORDENAR"
-ARREGLAR COMO MOSTRAR LOS RESULTADOS
-VERIFICAR LA FUNCION "BAJA"
-VERIFICAR MODIFICACION
-HACER FUNCION DE "BORRAR" EMPLEADO
-TIENE UN WARNING DE LA FUNCION "ORDENAR" DE LO QUE DEVUELVE
-FECHA DE NACIMIENTO
-APELLIDO
-TELEFONO
-IMAIL
-CODIGO POSTAL
-SECTORES
-PROVEEDORES
-FUNCIONES DE MAXIMOS Y MINIMOS PARA ORDENAR
-FUNCION PARA ORDENAR Y PEDIR SECTORES CON EMPLEADOS
-FUNCION PARA ORDENAR Y PEDIR PROVEEDORES
-SI ES POSIBLE INCLUIR EMPRESAS CON SUS EMPLEADOS, SECTORES, PROVEEDORES.
-AGREGAR ESTRUCTURAS NECESARIAS PARA HACER PROVEEDORES Y EMPRESAS.
*/

/** \brief
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \return void
 *
 */
void inicializarEmpleados(eEmpleado vec[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

/** \brief
 *
 * \return int
 *
 */
int menu()   //FALTA VALIDAR QUE NO INGRESE LETRAS
{
    int opcion;

    system("cls");
    printf("  *** ABM Empleados ***\n\n");
    printf("\n\n\n1 - ALTA \n2 - BAJA \n3 - MODIFICACION\n4 - ORDENAR\n5 - LISTAR\n6 - SALIR\n\n\n");
    printf("seleccione una opcion\n");
    scanf("%d",&opcion);

    return opcion;
}

/** \brief
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \return int
 *
 */
int buscarLibre(eEmpleado vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \param legajo int
 * \return int
 *
 */
int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].legajo == legajo && vec[i].ocupado == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief
 *
 * \param emp eEmpleado
 * \return void
 *
 */
void mostrarEmpleado(eEmpleado emp)
{
    printf("\n\tLEGAJO \t\tNOMBRE \tSEXO \t\tSUELDO\n");
    printf("  %10d   %10s   %5c    %10.2f\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo);

}

/** \brief
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \return void
 *
 */
void mostrarEmpleados(eEmpleado vec[], int tam)
{
    int cont = 0;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarEmpleado(vec[i]);
            cont++;
        }
    }
    if(cont == 0)
    {
        printf("No hay empleados que mostrar\n\n");
    }
}

/** \brief
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \return void
 *
 */
void altaEmpleado(eEmpleado vec[], int tam)
{
    int indice;
    int legajo;
    char auxLegajo[256];
    char nombre[20];
    char sexo;
    float sueldo;
    char auxSueldo[256];
    int esta;

    indice = buscarLibre(vec, tam);

    if(indice == -1)
    {
        printf("No hay lugar");
    }
    else
    {
        while(!getStringNumeros("Ingrese legajo: ",auxLegajo))
        {
            printf("El legajo debe ser numerico\n");
        }
        legajo = atoi(auxLegajo);

        esta = buscarEmpleado(vec, tam, legajo);

        if( esta == -1)
        {
            vec[indice].legajo = legajo;

            while(!getStringLetras("Ingrese nombre: ",nombre))
            {
                printf ("El nombre debe estar compuesto solo por letras\n");
            }
            strcpy(vec[indice].nombre,nombre);

            do
            {
                sexo = toupper(getChar("ingrese sexo: "));
            }
            while(!(sexo == 'M' || sexo == 'F'));  //TIENE ERRORES

            vec[indice].sexo = sexo;

            while(!getStringNumeros("Ingrese el sueldo: ",auxSueldo))
            {
                printf("El sueldo debe ser numerico\n");
            }
            sueldo = atof(auxSueldo);
            vec[indice].sueldo = sueldo;

            vec[indice].ocupado = 1;

            printf("\nEl empleado ha sido registrado con exito!!!\n\n");
        }
        else
        {
            printf("Ya existe un empleado con el legajo %d\n", legajo);

            mostrarEmpleado(vec[esta]);
        }
    }
}

/** \brief
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \return void
 *
 */
void bajaEmpleado(eEmpleado vec[], int tam)
{
    int legajo;
    char auxLegajo[256];
    char confirma;
    int esta;

    while(!getStringNumeros("Ingrese legajo: ",auxLegajo))
    {
        printf("El legajo debe ser numerico\n");
    }
    legajo = atoi(auxLegajo);

    esta = buscarEmpleado(vec, tam, legajo);

    if( esta == -1)
    {

        printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
    }
    else
    {
        mostrarEmpleado(vec[esta]);

        printf("\nConfirma la baja? s/n");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's')
        {
            vec[esta].ocupado = 0;
        }
        else
        {
            printf("\nSe ha dado de baja\n");
        }
    }
}

/** \brief
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \return void
 *
 */
void ModificacionEmpleado(eEmpleado vec[], int tam)
{
    int legajo;
    char auxLegajo[256];
    int nuevoLegajo;
    char nuevoNombre[20];
    char nuevoSexo;
    char confirma;
    char auxSueldo[256];
    float nuevoSueldo;
    int esta;

    while(!getStringNumeros("Ingrese legajo: ",auxLegajo))
    {
        printf("El legajo debe ser numerico\n");
    }
    legajo = atoi(auxLegajo);

    esta = buscarEmpleado(vec, tam, legajo);

    if( esta == -1)
    {

        printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
    }
    else
    {
        mostrarEmpleado(vec[esta]);

        printf("\nQuiere cambiar el legajo? s/n");
        setbuf(stdin,NULL);
        confirma = tolower(getche());

        if(confirma == 's')
        {
            while(!getStringNumeros("Ingrese legajo: ",auxLegajo))
            {
                printf("El legajo debe ser numerico\n");
            }
            nuevoLegajo = atoi(auxLegajo);
            //valido legajo
            vec[esta].legajo = nuevoLegajo;
        }
        else
        {
            printf("\nNo se ha modificado el legajo\n");
        }

        printf("\nQuiere cambiar el nombre? s/n");
        setbuf(stdin,NULL);
        confirma = tolower(getche());

        if(confirma == 's')
        {
            while(!getStringLetras("Ingrese nombre: ",nuevoNombre))
            {
                printf ("El nombre debe estar compuesto solo por letras\n");
            }
            //valido nombre
            strcpy(vec[esta].nombre,nuevoNombre);
        }
        else
        {
            printf("\nNo se ha modificado el nombre\n");
        }

        printf("\nQuiere cambiar el sexo? s/n");
        setbuf(stdin,NULL);
        confirma = tolower(getche());

        if(confirma == 's')
        {
            do
            {
                nuevoSexo = toupper(getChar("ingrese sexo: "));
            }
            while(!(nuevoSexo == 'M' || nuevoSexo == 'F'));
            //valido sexo
            vec[esta].sexo = nuevoSexo;
        }
        else
        {
            printf("\nNo se ha modificado el sexo\n");
        }

        printf("\nQuiere cambiar el sueldo? s/n");
        setbuf(stdin,NULL);
        confirma = tolower(getche());

        if(confirma == 's')
        {
            while(!getStringNumeros("Ingrese el sueldo: ",auxSueldo))
            {
                printf("El sueldo debe ser numerico\n");
            }
            nuevoSueldo = atof(auxSueldo);
            //valido sueldo
            vec[esta].sueldo = nuevoSueldo;
        }
        else
        {
            printf("\nNo se ha modificado el sueldo\n");
        }
    }
}


void Ordenar(eEmpleado vec[], int tam)
{
    eEmpleado auxVec;
    int i;
    int j;

    for(i = 0;i < tam-1;i++)
    {
        for(j = i+1;j < tam;j++)
        {
            if(strcmp(vec[i].nombre,vec[j].nombre)>0)
            {
                auxVec = vec[i];
                vec[i] = vec[j];
                vec[j] = auxVec;
            }
        }
    }
    return auxVec;
}
