// boletos_1
//Brigada 01: Durán Rendón Santiago, Noriega Chiu Santiago, Ramírez Reyes José de Jesús
//08-10-24
/* Enunciado: En un estadio se tienen 5 tipos diferentes de localidades, 
las cuales se identifican por una clave numérica que es un valor comprendido entre 1 y 5. 
Los precios de cada localidad y los datos referentes a las ventas de boletos para el próximo juego son: 
(precios en el archivo .pdf)
Desarrolle el programa que: 
Lea los precios. 
Lea los datos de las ventas de boletos. 
Imprima para cada venta, la clave, la cantidad y el importe de los boletos vendidos en esta venta. 
Calcule e imprima la cantidad de boletos vendidos de cada tipo. 
Calcule e imprima la recaudación total del estadio.
En cada venta se venden los boletos de un solo tipo. El programa debe solicitar si se ha terminado la venta de boletos o se quiere realizar otra operación más. */
/*Ejecución: Ingrese la clave del boleto (1-5): 2

Ingrese la cantidad de boletos vendidos: 45

Desea realizar otra venta? (s/n): s
Ingrese la clave del boleto (1-5): 2

Ingrese la cantidad de boletos vendidos: 4

Desea realizar otra venta? (s/n): s
Ingrese la clave del boleto (1-5): 3

Ingrese la cantidad de boletos vendidos: s

Desea realizar otra venta? (s/n):
Recaudacion total: 1550.00
Total de boletos vendidos por clave: 0, 49, 4, 0, 5*/

#include <stdio.h>

int main() {
    int clave, cantidad, total_boletos1 = 0, total_boletos2 = 0, total_boletos3 = 0, total_boletos4 = 0, total_boletos5 = 5;
    float precio1 = 50, precio2 = 30, precio3 = 20, precio4 = 10, precio5 = 5, recaudacion = 0;
    char continuar;

    do {
        //lectura de clave y cantidad vendida
        printf("Ingrese la clave del boleto (1-5): ");
        scanf("%d", &clave);
        printf("\nIngrese la cantidad de boletos vendidos: ");
        scanf("%d", &cantidad);

        //calculo de importe-venta
        switch (clave) {
            case 1:
                recaudacion += precio1 * cantidad;
                total_boletos1 += cantidad;
                break;
            case 2:
                recaudacion += precio2 * cantidad;
                total_boletos2 += cantidad;
                break;
            case 3: 
                recaudacion += precio3 * cantidad;
                total_boletos3 += cantidad;
                break;
            case 4:
                recaudacion += precio4 * cantidad;
                total_boletos4 += cantidad;
                break;
            case 5:
                recaudacion += precio5 * cantidad;
                total_boletos5 += cantidad;
                break;
            default:
                printf("\n Clave no valida.");
                break;

        }//switch

        //no se que hace esto pero no corria correctamente mi codigo y segun yo estaba al 100 :(
        getchar();

        //pregunta si continua
        printf("\nDesea realizar otra venta? (s/n): ");
        scanf("%c", &continuar);
    } while (continuar == 's' || continuar == 'S'); //do-while

    //impresion resultados
    printf("\nRecaudacion total: %.2f", recaudacion);
    printf("\nTotal de boletos vendidos por clave: %d, %d, %d, %d, %d", total_boletos1, total_boletos2, total_boletos3, total_boletos4, total_boletos5);
    
    return 0;

}//principal