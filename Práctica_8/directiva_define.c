// directiva define
//Brigada 01: Durán Rendón Santiago, Noriega Chiu Santiago, Ramírez Reyes José de Jesús
//08-10-24
/* Enunciado: Usar la directiva #define para elaboración de código versátil.*/
/*Ejecución: Ingrese el radio del circulo: 8
El area del circulo es: 201.06 */

#include <stdio.h>
#include <math.h>
#define PI 3.1416

int main() {
    float radio, area;

    printf("Ingrese el radio del circulo: ");
    scanf("\n%f", &radio);

    area = PI * pow(radio, 2);

    printf("El area del circulo es: %.2f",area);
    return 0;
}//principal