// calificaciones_3
//Durán Rendón Santiago
//14-10-24
/* Enunciado: Escribir un programa que lea la calificación de un examen por teclado y devuelva la calificación no numérica correspondiente.
La calificación podrá ser: No aprobado (0-4.99), Aprobado (5-6.99), Notable (7-8.99), Sobresaliente (9-9.99) o Excelente (10).
Realizar este ejercicio utilizando la sentencia if-else.
Mejorar el ejercicio anterior de modo que si el usuario introduce un valor menor que cero o un valor mayor que 10 se muestre por pantalla un mensaje de error.*/
/*Pseudocódigo: INICIO Calificaciones_3
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
	SINO 
		IMPRIMIR “Calificación no valida”
	FIN SI
FIN*/
/*Ejecución: Ingrese la calificacion: -4

Error en la calificacion
PS C:\Users\santi\OneDrive\Documentos\Santiago\Programación\C\Fi> ./cal_3.exe
Ingrese la calificacion: 8587

Error en la calificacion*/

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
    }/*else-if 4*/ else if (calificacion < 0 || calificacion > 10) {
        printf("\nError en la calificacion");
    }/*else-if 5*/ else {
        printf("\nValor no valido");
    }//else

    return 0;

}//principal