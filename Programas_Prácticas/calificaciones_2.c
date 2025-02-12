// calificaciones_2
//Durán Rendón Santiago
//14-10-24
/* Enunciado: Escribir un programa que lea la calificación de un examen por teclado y devuelva la calificación no numérica correspondiente.
La calificación podrá ser: No aprobado (0-4.99), Aprobado (5-6.99), Notable (7-8.99), Sobresaliente (9-9.99) o Excelente (10).
Realizar este ejercicio utilizando la sentencia if-else.*/
/*Pseudocódigo: INICIO Calificaciones_2
	cal: REAL
	IMPRIMIR “Ingrese la calificación del alumno”
	LEER cal
	SI (cal >= 0 AND cal <= 4.99)
		IMPRIMIR “No aprobada”
	SINO SI (cal >= 5 AND cal <= 6.99)
		IMPRIMIR “Aprobado”
	SINO SI (cal >= 7 AND cal <= 8.99)
		IMPRIMIR “Notable”
	SINO SI (cal >= 9 AND cal <= 9.99)
		IMPRIMIR “Sobresaliente”
	SINO SI (cal == 10)
		IMPRIMIR “Excelente”
	FIN SI
FIN*/
/*Ejecución: Ingrese la calificacion: 7.86

Notable*/

#include <stdio.h>

int main() {
    float calificacion;
    printf("Ingrese la calificacion: ");
    scanf("%f", &calificacion);

    if (calificacion >= 0 && calificacion <= 4.99) {
       printf("\nNo aprobada"); 
    }/*if 1*/ else if (calificacion >= 5 && calificacion <= 6.99) {
        printf("\nAprobado");
    }/*else-if 1*/ else if (calificacion >= 7 && calificacion <= 8.99) {
        printf("\nNotable");
    }/*else-if 2*/ else if (calificacion >= 9 && calificacion <= 9.99) {
        printf("Sobresaliente");
    }/*else-if 3*/ else if (calificacion == 10) {
        printf("Excelente");
    }/*else-if 4*/ else {
        printf("\nError en la calificacion");
    }//else

    return 0;

}//principal