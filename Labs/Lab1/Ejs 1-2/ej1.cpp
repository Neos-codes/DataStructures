#include <iostream>

//----- CODIGO 1 -----

int A[n],sum[n];
for(int i = 0; i < n; i++) scanf("%d",&A[i]);  //Escanea n enteros y los guarda en A
for(int i = 0; i < n; i++){       // desde la posicion i, suma todos los valores de A
  int aux = 0;                    // que estan por antes de la posicion i usando 2 for
  for(int j = 0; j <= i; j++){    // la suma desde 0 hasta i la guarda en aux
    aux += a[j];                  // luego la suma hasta la posicion i la guarda en la
  }                               // posicion i del arreglo sum. (Osea en sum[i])
  sum[i] = aux;
 }

//----- CODIGO 2 -----

int A[n],sum[n];
for(int i = 0; i < n; i++) scanf("%d",&A[i]); //Escanea n enteros y los guarda en A
sum[0] = A[0];                                // la primera posicion de sum guarda
for(int i = 1; i < n; i++){                   // la primera posicion del arreglo A
  sum[i] = sum[i-1] + A[i];                   // y luego con un for, la suma en la posicion
 }                                            // i se calcula como la suma anterior más el valor
                                              // en A[i]

// En resumen, el codigo 2 cumple la misma tarea de sumar los valores de A hasta la posicion i
// solo que lo hace en una cantidad mucho menor de pasos.
