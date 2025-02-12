// boletos_1
//Brigada 01: Durán Rendón Santiago, Noriega Chiu Santiago, Ramírez Reyes José de Jesús
//23-10-24
/* Enunciado: Realizar un programa que reciba cuatro puntos en R3 y calcule la distancia que hay del primero a los otros tres puntos. */
/*Pseudocódigo: INICIO Distancias puntos
     REAL punto1[3], punto2[3], punto3[3], punto4[3]
     ditancia = sqrt(pow(punto2[0] - punto1[0], 2) + pow(punto2[1] - punto1[1], 2) + pow(punto2[2] - punto1[2], 2))
     IMPRIMIR “Ingrese las coordenadas del primer punto”
     LEER punto1[0], punto1[1], punto1[2]
     IMPRIMIR “Ingrese las coordenadas del segundo punto”
     LEER punto2[0], punto2[1], punto2[2]
     IMPRIMIR “Ingrese las coordenadas del tercer punto”
     LEER punto3[0], punto3[1], punto3[2]
     IMPRIMIR “Ingrese las coordenadas del cuarto punto”
     LEER punto4[0], punto4[1], punto4[2]
     IMPRIMIR “La distancia es”, distancia
FIN*/
/*Ejecución: Ingrese las coordenadas del primer punto (x1, y1, z1): 1
2
3
Ingrese las coordenadas del segundo punto (x2, y2, z2): 5
6
7
La distancia es: 6.93
Ingrese las coordenadas del tercer punto (x3, y3, z3): 4
3
8
La distancia es: 5.92
Ingrese las coordenadas del cuarto punto (x4, y4, z4): 7
0
1
La distancia es: 6.63*/
#include <stdio.h>
#include <math.h>

void calcularDistancia(float punto1[3], float punto2[3]) {
    float distancia = sqrt(pow(punto2[0] - punto1[0], 2) +
                           pow(punto2[1] - punto1[1], 2) +
                           pow(punto2[2] - punto1[2], 2));
    printf("La distancia es: %.2f\n", distancia);
}

int main() {
    float punto1[3], punto2[3], punto3[3], punto4[3];

    // Leer el primer punto
    printf("Ingrese las coordenadas del primer punto (x1, y1, z1): ");
    scanf("%f %f %f", &punto1[0], &punto1[1], &punto1[2]);

    // Leer y calcular la distancia para el segundo punto
    printf("Ingrese las coordenadas del segundo punto (x2, y2, z2): ");
    scanf("%f %f %f", &punto2[0], &punto2[1], &punto2[2]);
    calcularDistancia(punto1, punto2);

    // Leer y calcular la distancia para el tercer punto
    printf("Ingrese las coordenadas del tercer punto (x3, y3, z3): ");
    scanf("%f %f %f", &punto3[0], &punto3[1], &punto3[2]);
    calcularDistancia(punto1, punto3);

    // Leer y calcular la distancia para el cuarto punto
    printf("Ingrese las coordenadas del cuarto punto (x4, y4, z4): ");
    scanf("%f %f %f", &punto4[0], &punto4[1], &punto4[2]);
    calcularDistancia(punto1, punto4);

    return 0;
}
