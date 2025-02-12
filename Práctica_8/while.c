// while
//Brigada 01: Durán Rendón Santiago, Noriega Chiu Santiago, Ramírez Reyes José de Jesús
//08-10-24
/* Enunciado: Elaborar un programa que utilice la estructura while en la solución de un problema.*/
/*Ejecución: La suma de los numeros del 1 al 10 es: 55*/

#include <stdio.h>
int main() {
    int suma = 0, num = 1;
    while (num <= 10) {
        suma += num;
        num++;
    }//while
    printf("La suma de los numeros del 1 al 10 es: %d", suma);
    return 0;
}//principal