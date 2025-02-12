//dos_iguales
//Durán Rendón Santiago
//15-10-24
/* Enunciado: Escribir un programa que permita introducir por teclado tres letras y responda si existen al menos dos letras iguales.*/
/*Pseudocódigo: INICIO Dos_iguales
	A, B, C: CHAR
	IMPRIMIR “Ingrese tres letras y diré si hay dos iguales”
	LEER A
	LEER B
	LEER C
	SI (A == B OR A == C OR B == C)
		IMPRIMIR “Dos letras son iguales”
	SINO
		IMPRIMIR “Las letras son diferentes”
	FIN SI
FIN*/
/*Ejecución: Ingrese tres letras y dire si hay dos iguales
e
r
t
Las letras son diferntes
PS C:\Users\santi\OneDrive\Documentos\Santiago\Programación\C\Fi> ./dos_iguales.exe
Ingrese tres letras y dire si hay dos iguales
r
r
r
Dos letras son iguales r r r*/

#include <stdio.h>

int main() {
    char A, B, C;
    printf("Ingrese tres letras y dire si hay dos iguales\n");
    scanf("%c %c %c", &A, &B, &C);

    if (A == B || A == C || B == C) {
        printf("Dos letras son iguales %c %c %c", A, B, C);
    }/*if*/ else if (A != B || A != C || B != C) {
        printf("Las letras son diferntes");
    }/*else-if*/ else {
        printf("Error");
    }//else

    return 0;

}//principal