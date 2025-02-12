//menor
//Durán Rendón Santiago
//14-10-24
/* Enunciado: Escribir un programa que lea cuatro números enteros y determine cuál es el menor. 
También debe considerar el caso en el que los números sean iguales.*/
/*Pseudocódigo: INICIO Menor
	A, B, C, D: REALES
	IMPRIMIR “Ingrese los cuatro números a comparar”
	LEER A
	LEER B
	LEER C
	LEER D
	SI A < B AND A < C AND A < D
		IMPRIMIR A, “ es menor”
	SINO SI A == B OR A == C OR A == D
		IMPRIMIR “Números iguales”
	SI B < A AND b < C AND B < D
		IMPRIMIR B, “ es menor”
	SINO SI B == A OR B == C OR B == D
		IMPRIMIR “Números iguales”
	SI C < A AND C < B AND C < D
		IMPRIMIR C, “ es menor”
	SINO SI C == A OR C == B OR C == D
		IMPRIMIR “Números iguales”
	SI D < A AND D < B AND D < C
		IMPRIMIR D, “ es menor”
	SINO SI D == A OR D == B OR D == C
		IMPRIMIR “Números iguales”
	SINO
		IMPRIMIR “Error”
	FIN SI
FIN*/
/*Ejecución: Ingrese los cuatro numeros a comparar
4
56
34
65

El numero menor es: 4*/

#include <stdio.h>

int main() {
    int A, B, C, D;
    printf("Ingrese los cuatro numeros a comparar\n");
    scanf("%d %d %d %d", &A, &B, &C, &D);

    if (A < B && A < C && A < D) {
        printf("\nEl numero menor es: %d", A);
    }/*if*/ else if (A == B || A == C || A == D) {
        printf("\nNumeros iguales");
    }/*else-if 1*/ else if (B < A && B < C && B < D) {
        printf("\nEl numero menor es: %d", B);
    }/*else-if 2*/ else if (B == A || B == C || B == D) {
        printf("\nNumeros iguales");
    }/*else-if 3*/ else if (C < A && C < B && C < D) {
        printf("\nEl numero menor es: %d", C);
    }/*else-if 4*/ else if (C == A || C == B || C == D) {
        printf("\nNumeros iguales");
    }/*else-if 5*/ else if (D < A && D < B && D < C) {
        printf("\nEl numero menor es: %d", D);
    }/*else-if 4*/ else if (D == A || D == B || D == C) {
        printf("\nNumeros iguales");
    }/*else-if 5*/ else {
        printf("\nError");
    }//else

    return 0;

}//principal