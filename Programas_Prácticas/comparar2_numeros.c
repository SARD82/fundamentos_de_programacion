// variables 2.0
//Brigada 01
//24-09-24
// Descripción: Programa que compara dos números

#include <stdio.h>

int main(){
    int num1, num2;
    printf("\n Introduce el primer numero: ");
    scanf("%d", &num1);
    printf("\n Introduce el segundo numero: ");
    scanf("%d", &num2);

    if (num1 > num2) {
        printf("\n %d es mayor que %d", num1, num2);

    }//if principal
    else if (num1 < num2) {
        printf("\n %d es menor que %d", num1, num2);

    }//else if principal
    else {
        printf("/n Ambos numeros son iguales");
    }//else principal

    return 0;

}//principal