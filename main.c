#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "empleo.h"

int main()
{

   printf("        -----ALUMNA: LAMAS MARTINA LUJAN------    \n");
   printf("\n");
   srand(time(0));
   printf("\n---------PUNTO 1-------\n");
   EmpleoPtr e= cargarEmpleo("Banco Nacion");
   agregarEmpleado(e, 6, "Tomas");
   agregarEmpleado(e, 1, "Rocio");
   agregarEmpleado(e, 11, "Alberto");
   agregarEmpleado(e, 59, "Karina");
   mostrarEmpleo(e);
   printf("\n------PUNTO 2------\n");
   ordenarSalario(e);
   mostrarEmpleo(e);
   printf("\n------PUNTO 3-----\n");
   eliminarEmpleado(e);
   mostrarEmpleo(e);
   printf("\n-----PUNTO 4------\n");
   float prom = calcularPromedio(e);
   printf("EL PROMEDIO DE LOS SALARIOS DE LOS EMPLEADOS ES DE: %.2f\n", prom);
   printf("\n-------ARREGLO DE SALARIOS-----\n");
   float arregloSalarios[4];
   cargarArreglo(arregloSalarios, e, prom);
   ordenarSalario2(arregloSalarios);
   mostrarArreglo(arregloSalarios);
   int pos = buscarSalario(arregloSalarios, prom);
   printf("\nEL SALARIO MAS CERCANO AL PROMEDIO ES EL DE LA POSICION: %d\n", pos);
   int posEmpleado = buscarEmpleado(e,arregloSalarios,prom);
   printf("\nEL EMPLEADO QUE TIENE EL SALARIO MAS CERCANO ES EL DE LA POSICION: %d\n", posEmpleado);

    return 0;
}
