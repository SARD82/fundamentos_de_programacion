// Area de figuras
//Brigada 01: Durán Rendón Santiago, Noriega Chiu Santiago, Ramírez Reyes José de Jesús
//02-10-24
/* Enunciado:  Se requiere calcular el área de diferentes formas geométricas: cuadrado, círculo, triángulo y rectángulo. El usuario debe escoger de un menú de opciones la figura a calcular.*/
/*Ejecución: 
 Seleccione la figura geometrica para calcular el area: 
 1. cuadrado
 2. circulo
 3. triangulo
 4. rectanguloIngrese su opcion: 1

 Ingrese el lado del cuadrado: 90

 El area del cuadrado es 8100.00*/
/* Psudocódigo:
INICIO area_figuras
    caracter figura
    IMPRIMIR "Ingrese la figura de la cual desea calcular el área (C: cuadrado, Cir: círculo, T: triángulo, R: rectángulo)"
    LEER (figura)
    En caso que figura Sea
        Caso C
            REAL lado
            lado = 0
            IMPRIMIR ("Ingrese cuanto mide el lado del cuadrado")
            LEER lado
            area = lado * lado
            IMPRIMIR (area)
        Caso Cir
            Real radio
            radio = 0
            IMPRIMIR ("Ingrese cuanto mide el radio del círculo")
            LEER radio
            area = 3.1416 * radioo ^ 2 
            IMPRIMIR (area)
        Caso T
            REAL base, altura
            base = 0
            altura = 0
            IMPRIMIR ("Ingrese cuanto mide la base del triángulo")
            LEER base
            IMPRIMIR ("Ingrese cuanto mide la altura del triángulo")
            LEER altura
            area = (base * altura) / 2
            IMPRIMIR (area)
        Caso R
            REAL lado, base
            lado = 0
            base = 0 
            IMPRIMIR ("Ingrese cuanto mide la base del rectángulo")
            LEER base
            IMPRIMIR ("Ingrese cuanto mide el lado del rectángulo")
            LEER lado
            area = base * lado
            IMPRIMIR (area)
        SiNo
            IMPRIMIR ("Valor no valido") 
    Fin Caso
FIN */

#include <stdio.h>
#include <math.h> // biblioteca para el pow y el valor de pi

int main() {
    int opcion;
    float area, lado, radio, base, altura;
    const float PI = 3.1416;

    //Menú de las opciones
    printf("\n Seleccione la figura geometrica para calcular el area: ");
    printf("\n 1. cuadrado");
    printf("\n 2. circulo");
    printf("\n 3. triangulo");
    printf("\n 4. rectangulo");
    printf("Ingrese su opcion: ");
    scanf("%d", &opcion);

    //Estructura del switch
    switch(opcion) {
        case 1: //cuadrado
            printf("\n Ingrese el lado del cuadrado: ");
            scanf("%f", &lado);
            area = lado * lado;
            printf("\n El area del cuadrado es %.2f", area);
            break;
        case 2: //círculo
            printf("\n ingrese el radio del circulo: ");
            scanf("%f", radio);
            area = PI * pow(radio, 2);
            printf("\n El area del circulo es: %.2f", area);
            break;
        case 3: // Triángulo
            printf("\n Ingrese la base y la altura del triangulo: ");
            scanf("%f %f", &base, &altura);
            area = (base * altura) / 2;
            printf("\n El area del triangulo es: %.2f", area);
            break;
        case 4: // Rectángulo
            printf("\n Ingrese la base y la altura del rectangulo: ");
            scanf("%f %f", &base, &altura);
            area = base * altura;
            printf("\n El area del rectangulo es: %.2f", area);
            break;
        default:
            printf("\n Opcion no valida.");
            break;
    }

    return 0;
}
