//menor_mayor
//Durán Rendón Santiago
//14-10-24
/* Enunciado: Escribir un programa que lea tres números diferentes cualesquiera y muestre por pantalla el mayor y el menor.*/
/*Pseudocódigo: INICIO Mayor_menor
	A, B, C: REAL
	IMPRIMIR “Ingrese los tres números a comparar”
	LEER A
	LEER B
	LEER C
	SI A > B AND A > C AND B < C
		IMPRIMIR A, “ es mayor y “, B, “ menor”
	SINO SI A > B AND A > C AND C < B
		IMPRIMIR A, “ es mayor y “, C, “menor”
	SINO SI B > A AND B > C AND A < C
		IMPRIMIR B, “ es mayor y “, A, “ menor”
	SINO SI B > A AND B > C AND C < A
		IMPRIMIR B, “ es mayor y “, C, “menor”
	SINO SI C > A AND C > B AND A < B
		IMPRIMIR C, “ es mayor y “, A, “ menor”
	SINO SI C > A AND C > B AND B < A
		IMPRIMIR C, “ es mayor y “, B, “menor”
	SINO
		IMPRIMIR “Error”
	FIN SI
FIN*/
/*Ejecución: Ingrese los tres numeros a comparar
45
5
6

45 es mayor y 5 es menor*/

#include <stdio.h>

int main(){
    int A, B, C;
    printf("Ingrese los tres numeros a comparar\n");
    scanf("%d %d %d", &A, &B, &C);

    if (A > B && A > C && B < C) {
        printf("\n%d es mayor y %d es menor", A, B);
    }/*if*/ else if (A > B && A > C && C < B) {
        printf("\n%d es mayor y %d es menor", A, C);
    }/*else-if 1*/ else if (B > A && B > C && A < C){
        printf("\n%d es mayor y %d es menor", B, A);
    }/*else-if 2*/ else if (B > A && B > C && C < A) {
        printf("\n%d es mayor y %d es menor", B, C);
    }/*else-if 3*/ else if (C > A && C > B && A < B) {
        printf("\n%d es mayor y %d es menor", C, A);
    }/*else-if 4*/else if (C > A && C > B && B < A) {
        printf("\n%d es mayor y %d es menor", C, B);
    }/*else-if 5*/ else {
        printf("\nError");
    }//else

    return 0;

}//principal