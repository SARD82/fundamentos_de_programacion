// Fibonacci
//Brigada 01: Durán Rendón Santiago, Noriega Chiu Santiago, Ramírez Reyes José de Jesús
//08-10-24
/* Enunciado: Elabore un programa para calcular el término 10 de la secuencia de Fibonacci. 
Recuerde que los dos primeros números de la serie son 0 y 1. 
El resto se calcula con la suma de los dos números inmediatos que le preceden.*/
/*Ejecución: El decimo termino de la secuencia de Fibonacci es : 55 */

#include <stdio.h>

int main() {
    int n = 10, t1 = 0, t2 = 1, siguienteTermino, i;

    for (i = 1; i <= n; ++i) {
        siguienteTermino = t1 + t2;
        t1 = t2;
        t2 = siguienteTermino;

    }//for

    printf("El decimo termino de la secuencia de Fibonacci es : %d", t1);
    return 0;

}//principal