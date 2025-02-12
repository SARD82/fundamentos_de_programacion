// variables 2.0
//Brigada 01
//24-09-24
// Descripción: Programa que ve el tamaño de los tipos de datos en C.

#include <stdio.h>
int main(){
    printf("\n Tamano de int: %lu bytes", sizeof(int));
    printf("\n Tamano de float: %lu bytes", sizeof(float));
    printf("\n Tamano de char: %lu bytes", sizeof(char));
    printf("\n Tamano de double: %lu bytes", sizeof(double));

    return 0;

}//principal