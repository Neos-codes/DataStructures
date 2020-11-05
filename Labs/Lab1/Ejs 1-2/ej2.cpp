#include <iostream>

//----- CODIGO 1 -----

int A[n],sum[n];                                 //------- Estimacion de pasos--------------
for(int i = 0; i < n; i++) scanf("%d",&A[i]);   //    n
for(int i = 0; i < n; i++){                     //   n^2 (2 for anidados recorriendo arreglo)
  int aux = 0;
  for(int j = 0; j <= i; j++){
    aux += a[j];
  }
  sum[i] = aux;                                 // Total n^2 + n
 }                                              // Por lo tanto, el codigo 1 es O(n^2)
                                                
//----- CODIGO 2 -----

int A[n],sum[n];                            
for(int i = 0; i < n; i++) scanf("%d",&A[i]); //    n
sum[0] = A[0];                                //    1
for(int i = 1; i < n; i++){                   //    n
  sum[i] = sum[i-1] + A[i];                    
 }                                            // Total: 2n + 1
                                              // Por lo tanto, el codigo 2 es O(n)

// Esto quiere decir que el Codigo 2 es mas requiere una cantidad menor de pasos para
// hacer la misma tarea que el Codigo 1
