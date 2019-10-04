#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{

    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int ocupado;
    eFecha fechaNac;
    int idSector;

} eEmpleado;

int menu();

void inicializarEmpleados(eEmpleado vec[], int tam);

int buscarLibre(eEmpleado vec[], int tam);

int buscarEmpleado(eEmpleado vec[], int tam, int legajo);

void mostrarEmpleado(eEmpleado emp);

void mostrarEmpleados(eEmpleado vec[], int tam);

void altaEmpleado(eEmpleado vec[], int tam);

void bajaEmpleado(eEmpleado vec[], int tam);

void ModificacionEmpleado(eEmpleado vec[], int tam);

void Ordenar(eEmpleado vec[], int tam);

#endif // EMPLEADO_H_INCLUDED


