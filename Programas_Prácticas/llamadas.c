#include <stdio.h>

int main(){
    char tipo;
    int cantidadlocal = 0;
    float total = 0, costo = 0, duracion = 0;
    printf ("\n Ingrese el tipo de llamada (I: Internacional, L: Local, N: Nacional): ");
    scanf (" %c", &tipo);

    printf("\n Ingrese la duracion de la llamada ");
    scanf("%f", &duracion);
    switch(tipo){
    case 'I':
        if (duracion > 3){
            costo = 7.59 + ((duracion - 3) * 3.03);
        }//fin if 1
        else{
            costo = 7.59;
        }//fin else 1
        break;
    case 'L':
        cantidadlocal ++;
        if (cantidadlocal > 50){
            costo = 0.60;
        }//fin if 2
        else{
            costo = 0;
        }//fin else 2
        break;
    case 'N':
        if (duracion > 3){
            costo = 1.20 + ((duracion - 3) * 0.48);
        }//fin if 3
        else{
            costo = 1.20;
        }//fin else 3
        break;
    default:
        printf("\n Valores no validos");
    }
    total += costo;
    printf("\n El total es: %f", total);
    return 0;
}//fin main