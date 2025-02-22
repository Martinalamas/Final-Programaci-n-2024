#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct Empleado {
    int id;
    char nombre[50];
    float salario;
};

typedef struct Empleado* EmpleadoPtr;

EmpleadoPtr cargarEmpleadoVacio();
void mostrarEmpleado(EmpleadoPtr e);
EmpleadoPtr cargarEmpleado(int id, char n[]);
float generarAleatorio();

#endif // EMPLEADO_H_INCLUDED
