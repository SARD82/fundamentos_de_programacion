// calificaciones_1
//Durán Rendón Santiago
//14-10-24
/* Enunciado: Escribir un programa que lea la calificación de un examen por teclado y devuelva la calificación no numérica correspondiente.
La calificación podrá ser: No aprobado (0-4.99), Aprobado (5-6.99), Notable (7-8.99), Sobresaliente (9-9.99) o Excelente (10).
Realizar este ejercicio utilizando la sentencia de control switch.*/
/*Pseudocódigo: INICIO Calificaciones_1
	Cal: REAL
	IMPRIMIR “Ingrese la calificación del alumno”
	LEER cal
En Caso que cal Sea
	CASO cal > 0 AND cal < 4.99
		IMPRIMIR “No aprobada”
	CASO cal > 5 AND cal < 6.99
		IMPRIMIR “Aprobado”
	CASO cal > 7 AND cal < 8.99
		IMPRIMIR “Notable”
	CASO cal > 9 AND cal < 9.99
		IMPRIMIR “Sobresaliente”
	CASO cal == 10
		IMPRIMIR “Excelente”

FIN*/
/*Ejecución: Calificaciones posibles del alumnado
 1) 0-4.99
 2) 5-6.99
 3) 7-8.99
 4) 9-9.99
 5) 10
Seleccione una calificacion: 3

Notable*/

#include <stdio.h>

int main() {
    int calificacion;
    printf("Calificaciones posibles del alumnado\n 1) 0-4.99\n 2) 5-6.99\n 3) 7-8.99\n 4) 9-9.99\n 5) 10\n");
    printf("Seleccione una calificacion: ");
    scanf("%d", &calificacion);

    switch (calificacion) {
    case 1:
        printf("\nNo aprobado");
        break;
    case 2:
        printf("\nAprobado");
        break;
    case 3:
        printf("\nNotable");
        break;
    case 4:
        printf("\nSobresaliente");
        break;
    case 5:
        printf("\nExcelente");
        break;
    default:
        printf("\nError en la calificacion");
        break;
    }//switch

}//principal