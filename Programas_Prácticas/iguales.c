//iguales
//Durán Rendón Santiago
//14-10-24
/* Enunciado: Escribir un programa que permita introducir por teclado tres números enteros y responda si los números son iguales.*/
/*Pseudocódigo: INICIO Iguales
	A, B, C: ENTEROS
	IMPRIMIR “Ingrese tres números y diré si son iguales”
	LEER A
	LEER B
	LEER C
	SI (A == B AND A == C AND B == C)
		IMPRIMIR “Los tres números son iguales”
	SINO
		IMPRIMIR “Los números son distintos”
	FIN SI
FIN*/
/*Ejecución: Ingrese tres numeros y dire si son iguales
2
5
6

Los numeros son diferentes 2 5 6
PS C:\Users\santi\OneDrive\Documentos\Santiago\Programación\C\Fi> ./iguales_test.exe
Ingrese tres numeros y dire si son iguales
4
4
4

Los tres numeros son iguales 4 4 4*/

#include <stdio.h>

int main() {
    int A, B, C;
    printf("Ingrese tres numeros y dire si son iguales\n");
    scanf("%d %d %d", &A, &B, &C);

    if (A == B && A == C && B == C) {
        printf("\nLos tres numeros son iguales %d %d %d", A, B, C);
    }/*if*/ else if (A != B || A != C || B != C){
        printf("\nLos numeros son diferentes %d %d %d ", A, B, C);
    }/*else-if 1*/ else {
        printf("Error");
    }//else

    return 0;

}//principal