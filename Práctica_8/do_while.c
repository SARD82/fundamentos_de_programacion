// do_while
//Brigada 01: Durán Rendón Santiago, Noriega Chiu Santiago, Ramírez Reyes José de Jesús
//08-10-24
/* Enunciado: Elaborar un programa que requiera el uso de la estructura do-while para resolver un problema.*/
/*Ejecución: Ingrese el numero (negativo para terminar): 7 
Ingrese el numero (negativo para terminar): 7
Ingrese el numero (negativo para terminar): 7
Ingrese el numero (negativo para terminar): 7
Ingrese el numero (negativo para terminar): -9

 La suma de los numeros ingresados es : 28 */

#include <stdio.h>
int main () {
    int num, suma = 0;

    do {
        printf("Ingrese el numero (negativo para terminar): ");
        scanf("%d", &num);

        if (num >=0) {
            suma += num;
        }// if
    }/* do */ while (num >= 0);

    printf("\n La suma de los numeros ingresados es : %d", suma);
    return 0;
}//princial