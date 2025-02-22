#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "empleado.h"


EmpleadoPtr cargarEmpleadoVacio() {
     EmpleadoPtr e = (EmpleadoPtr) malloc (sizeof(struct Empleado));

     e->id = -1;
     strcpy(e->nombre, "VACIO");
     e->salario = -1;

     return e;


}
void mostrarEmpleado(EmpleadoPtr e){
    if (e->id != -1) {
           printf("    --------EMPLEADO-----\n");
           printf("    NOMBRE: %s\n", e->nombre);
           printf("    ID: %d\n", e->id);
           printf("    SALARIO: %.2f\n", e->salario);

    }

}
EmpleadoPtr cargarEmpleado(int id, char n[]){
     EmpleadoPtr e = (EmpleadoPtr) malloc (sizeof(struct Empleado));

     e->id = id;
     strcpy(e->nombre, n);
     e->salario = generarAleatorio()/10;

     return e;



}
float generarAleatorio(){
    float num;
    num = (10000 + rand()% (1000000+1-10000) );
    return num;



}
