// positivoN
//Brigada 01: Durán Rendón Santiago, Noriega Chiu Santiago, Ramírez Reyes José de Jesús
//08-10-24
/* Enunciado: Un número positivo N es un número primo si los únicos enteros positivos que lo dividen son exactamente 1 y N. 
Realice un programa que dado un número M, se obtenga y cuente todos los números primos menores a M. */
/*Ejecución: Ingrese el valor de M: 5

2 es primo
3 es primo
4 es primo
Total de primos menores a 5: 3*/

#include <stdio.h>
#include <math.h>

int main() {
    int M, n, i, es_primo, contador_primos = 0;

    printf("Ingrese el valor de M: ");
    scanf("%d", &M);

    //primos menores a M
    for (n = 2; n < M; n++) {
        es_primo = 1;
        for (i = 2; i < sqrt(n); i++) {
            if (n % i == 0) {
                es_primo = 0;
                break;

            }//if

        }//for1

        if (es_primo) {
            printf("\n%d es primo", n);
            contador_primos++;

        }//if1

    }//for

    printf("\nTotal de primos menores a %d: %d", M, contador_primos);
    return 0;

}//principal