#ifndef EMPLEO_H_INCLUDED
#define EMPLEO_H_INCLUDED
#include "Empleado.h"


struct Empleo {
    char nombre[100];
    EmpleadoPtr empleados[5];


};



typedef struct Empleo* EmpleoPtr;

EmpleoPtr cargarEmpleo(char n[]);
void mostrarEmpleo(EmpleoPtr e);
int buscarVacio(EmpleoPtr e);
void agregarEmpleado(EmpleoPtr e, int id, char n[]);
void ordenarSalario(EmpleoPtr e);
int mayorSalario (EmpleoPtr e);
void eliminarEmpleado(EmpleoPtr e);
float calcularPromedio(EmpleoPtr e);
void cargarArreglo(float v[], EmpleoPtr e, float prom);
void mostrarArreglo(float v[]);
int buscarSalario(float v[], float prom);
void ordenarSalario2(float v[]);
int buscarEmpleado(EmpleoPtr e, float v[], float prom);


#endif // EMPLEO_H_INCLUDED
