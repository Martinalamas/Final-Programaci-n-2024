#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "empleo.h"


EmpleoPtr cargarEmpleo(char n[]) {
    EmpleoPtr e= (EmpleoPtr) malloc(sizeof(struct Empleo));

    strcpy(e->nombre, n);

    for (int i=0; i<5; i++) {
        e->empleados[i] = cargarEmpleadoVacio();
    }

    return e;


}
void mostrarEmpleo(EmpleoPtr e){
    printf("------EMPLEO-----\n");
    printf("NOMBRE: %s\n", e->nombre);
    for (int i=0; i<5; i++) {
        mostrarEmpleado(e->empleados[i]);
    }

}

int buscarVacio(EmpleoPtr e){
    int pos = -1;
    for (int i=0; i<5; i++) {
        if (e->empleados[i]->id == -1) {
            pos = i;
            i = 5+1;
        }
    }

    return pos;


}
void agregarEmpleado(EmpleoPtr e, int id, char n[]) {
    int pos = buscarVacio(e);
    if (pos != -1) {
        e->empleados[pos] = cargarEmpleado(id, n);
    }
    else {
        printf("\nNO HAY MAS LUGAR\n");
    }

}

void ordenarSalario(EmpleoPtr e) {
      int posMin;
      EmpleadoPtr temp;
      for (int actual=0; actual<5-1; actual++) {
        posMin = actual;
        for (int i=actual; i<5; i++) {
            if (e->empleados[i]->salario < e->empleados[posMin]->salario) {
                posMin = i;
            }
        }
        temp = e->empleados[actual];
        e->empleados[actual] = e->empleados[posMin];
        e->empleados[posMin] = temp;
      }


}

int mayorSalario (EmpleoPtr e) {
     float mayorSalario = e->empleados[0]->salario;
     int mayorEmpleado = 0;
     for (int i=0; i<5; i++) {
        if (e->empleados[i]->salario > mayorSalario) {
            mayorEmpleado = i;
        }
     }

     return mayorEmpleado;


}

void eliminarEmpleado(EmpleoPtr e) {
    int pos = mayorSalario(e);
    e->empleados[pos] = cargarEmpleadoVacio();

}

float calcularPromedio(EmpleoPtr e) {
     float acum = 0;
     int cont = 0;
     for (int i=0; i<5; i++) {
        if (e->empleados[i]->id != -1) {
            cont = cont +1;
            acum = acum + e->empleados[i]->salario;
        }
     }

     float prom = acum / cont;


     return prom;


}

void cargarArreglo(float v[], EmpleoPtr e, float prom) {
    for (int i=0; i<4; i++) {
        {
            v[i] = e->empleados[i+1]->salario;
        }
    }

    for (int i=3; i<4; i++) {
        v[i] = prom;
    }

}

void mostrarArreglo(float v[]) {
    for (int i=0; i<4; i++) {
        printf("SALARIO EMPLEADO: %.2f\n", v[i]);
    }



}

void ordenarSalario2(float v[]){
    float aux;
    for (int i=0; i<5; i++) {
        for (int j=0; j<4-1; j++) {
            if (v[j] > v[j+1]) {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }

}


int buscarSalario(float v[], float prom) {
   int pos = -1;
   for (int i=0; i<5; i++) {
      if (v[i] == prom) {
        pos = i;
      }
   }
   float s1 = prom - v[pos-1];
   float s2 = v[pos+1] - prom;
   if (s1 > s2) {
      pos = pos+1;
   }
   else {
    pos = pos -1;
   }

   return pos;

}

int buscarEmpleado(EmpleoPtr e, float v[], float prom){
    int pos = buscarSalario(v,prom);
    int posEmpleado = -1;
    for (int i=0; i<5; i++) {
        if (e->empleados[i]->salario == v[pos]) {
            posEmpleado = i;
        }
    }

    return posEmpleado;


}



