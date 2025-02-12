// Sueldo de empleado
//Brigada 01: Durán Rendón Santiago, Noriega Chiu Santiago, Ramírez Reyes José de Jesús
//02-10-24
/* Enunciado:  Calcular el sueldo de un empleado: El usuario deberá ingresar el número de 
horas trabajadas y el valor por cada hora. Considere en los cálculos el descuento de seguridad 
social del 9.35% sobre el total de ingresos y una bonificación del 2% del sueldo inicial a percibir*/
/*Ejecución:  Ingrese el valor por hora: 56

 Sueldo bruto: 560.00
 Descuento de seguridad social (9.35%): 52.360001.2
 Bonificacion (2%): 0.00
 Sueldo neto: 507.64 */
/* Psudocódigo:
INICIO sueldo_empleado
    REAL thrs, vhrs, sueldo_b, sueldo_n, descuento, bonificacion
    thrs = 0
    vhrs = 0
    sueldo_b = 0
    sueldo_n = 0
    descuento = 0
    bonificacion = 0
    IMPRIMIR "Ingrese el número de horas trabajadas"
    LEER hrs
    IMPRIMIR "Ingrese el valor de cada hora trabajada"
    LEER vhrs
    sueldo_b = thrs * vhrs
    descuento = sueldo_b * 9.35 / 100
    bonificacion = sueldo_b * 2 / 100
    sueldo_n = sueldo_b - descuento + bonificacion
    IMPRIMIR "El sueldo bruto es: ", sueldo_b
    IMPRIMIR "El descuento es: ", descuento
    IMPRIMIR "La bonificación es: ", bonificacion
    IMPRIMIR "El sueldo neto es: ", sueldo_n
FIN */

#include <stdio.h>

int main() {
    float thrs, vhrs, sueldo_b, sueldo_n, descuento, bonificacion;
    const float descuento_ss = 9.35 / 100; // Descuento de seguridad social
    const float bonificacion1 = 2 / 100; // Bonificación

    // Ingresar los datos del usuario empleado
    printf("\n Ingrese el numero de horas trabajadas: ");
    scanf("%f", &thrs);
    printf("\n Ingrese el valor por hora: ");
    scanf("%f", &vhrs);

    //calculo sueldo bruto
    sueldo_b = thrs * vhrs;

    //calculo descuento seguridad social
    descuento = sueldo_b * descuento_ss;

    //calculo bonificación
    bonificacion = sueldo_b * bonificacion1;

    //calculo sueldo neto
    sueldo_n = sueldo_b - descuento + bonificacion;

    //resultados
    printf("\n Sueldo bruto: %.2f", sueldo_b);
    printf("\n Descuento de seguridad social (9.35%%): %f.2", descuento); // se pone doble % para que se imprima solo uno
    printf("\n Bonificacion (2%%): %.2f", bonificacion);
    printf("\n Sueldo neto: %.2f", sueldo_n);

    return 0;
}