// conversion_monedas
//Durán Rendón Santiago
//14-10-24
/* Enunciado: Diseñar un programa que permita realizar diferentes tipos de conversiones de monedas. El usuario debe seleccionar un tipo de conversión desde el menú principal. Por ejemplo: 
a)	Dólares a pesos 
b)	Pesos a dólares 
c)	Pesos a euros 
d)	Euros a pesos 
e)	Dólares a euros 
f)	Euros a dólares*/
/*Pseudocódigo: INICIO Conversión_monedas
a,b,c,d,e,f: CHAR
cantidad: REAL
IMPRIMIR “Seleccione una opción: 
a)	Dólares a pesos 
b)	Pesos a dólares 
c)	Pesos a euros 
d)	Euros a pesos 
e)	Dólares a euros 
f)	Euros a dólares”
En caso que Char Sea:
CASO a
	IMPRIMIR “Ingrese la cantidad de dólares”
	LEER cantidad
	cantidad = cantidad * 19.28
	IMPRIMIR “Son: “, cantidad, “pesos”
CASO b
	IMPRIMIR “Ingrese la cantidad de pesos”
	LEER cantidad
	cantidad = cantidad * 0.052
	IMPRIMIR “Son: “, cantidad, “dolares”
CASO c
	IMPRIMIR “Ingrese la cantidad de pesos”
	LEER cantidad
	cantidad = cantidad * 0.047
	IMPRIMIR “Son: “, cantidad, “euros”
CASO d
	IMPRIMIR “Ingrese la cantidad de euros”
	LEER cantidad
	cantidad = cantidad * 21.11
	IMPRIMIR “Son: “, cantidad, “pesos”
CASO e
	IMPRIMIR “Ingrese la cantidad de dólares”
	LEER cantidad
	cantidad = cantidad * 0.91
	IMPRIMIR “Son: “, cantidad, “euros”
CASO f
	IMPRIMIR “Ingrese la cantidad de euros”
	LEER cantidad
	cantidad = cantidad * 1.09
	IMPRIMIR “Son: “, cantidad, “dolares”
FIN*/
/*Ejecución: Conversiones de las siguientes monedas disponible:
 1) Dolares a pesos
 2) Pesos a dolares
 3) Pesos a euros
 4) Euros a pesos
 5) Dolares a euros
 6) Euros a dolares
Seleccione una opcion: 5

Ingrese la cantidad de dolares: 78*/

#include <stdio.h>

int main() {
    char a, b, c, d, e , f;
	int opcion;
    float cantidad = 0;
    printf("Conversiones de las siguientes monedas disponible:\n 1) Dolares a pesos\n 2) Pesos a dolares\n 3) Pesos a euros\n 4) Euros a pesos\n 5) Dolares a euros\n 6) Euros a dolares");
    printf("\nSeleccione una opcion: ");
	scanf("%d", &opcion);
    switch (opcion){
    case 1:
        printf("\nIngrese la cantidad de dolares: ");
		scanf("%f", &cantidad);
		cantidad = cantidad * 19.28;
		printf("\nSon: %.2f pesos", cantidad);
        break;
    
	case 2:
		printf("\nIngrese la cantidad de pesos: ");
		scanf("%f", &cantidad);
		cantidad = cantidad * 0.052;
		printf("\nSon: %.2f dolares ", cantidad);
		break;

	case 3:
		printf("\nIngrese la cantidad de pesos: ");
		scanf("%f", &cantidad);
		cantidad = cantidad * 0.047;
		printf("\nSon: %.2f euros", cantidad);
		break;

	case 4:
		printf("\nIngrese la cantidad de euros: ");
		scanf("%f", &cantidad);
		cantidad = cantidad * 21.11;
		printf("\nSon: %.2f pesos", cantidad);
		break;
	
	case 5:
		printf("\nIngrese la cantidad de dolares: ");
		scanf("%f", &cantidad);
		cantidad = cantidad * 0.91;
		printf("\nSon: %.2f euros", cantidad);
		break;

	case 6:
		printf("Ingrese la cantidad de euros: ");
		scanf("%f", &cantidad);
		cantidad = cantidad * 1.09;
		printf("\nSon: %.2f dolares", cantidad);
		break;

    default:
		printf("\nConversion no valida");
        break;

    }//switch

}//Principal