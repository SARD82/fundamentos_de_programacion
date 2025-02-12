//orden
//Durán Rendón Santiago
//14-10-24
/* Enunciado: Escribir un programa que lea cinco números cualesquiera y 
emita un mensaje indicando si están o no ordenados en orden creciente.*/
/*Pseudocódigo: INICIO Orden
	A, B, C, D, E: REALES
	IMPRIMIR “Ingrese los números y diré si están en orden creciente” 
	LEER A
	LEER B
	LEER C
	LEER D
	LEER E
	SI (A < B AND B < C AND C < D AND D < E)
		IMPRIMIR “Están en orden creciente”
	SINO
		IMPRIMIR “No están ordenados en orden creciente”
	FIN SI
FIN*/
/*Ejecución: Ingrese los numeros y dire si estan en orden creciente
4
3
4
67
6
No estan en orden creciente
PS C:\Users\santi\OneDrive\Documentos\Santiago\Programación\C\Fi> ./orden_test.exe
Ingrese los numeros y dire si estan en orden creciente
1
2
3
4
5
Estan en orden creciente*/

#include <stdio.h>

int main () {
    int A, B, C, D, E;
    printf("Ingrese los numeros y dire si estan en orden creciente\n");
    scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);
    if (A < B && B < C && C < D && D < E) {
        printf("Estan en orden creciente");
    }/*if*/ else if (A > B) {
        printf("No estan en orden creciente");
    }/*else-if*/ else {
        printf("Error");
    }//else

    return 0;

}//principal