// datos_gen
//Brigada 01: Durán Rendón Santiago, Noriega Chiu Santiago, Ramírez Reyes José de Jesús
//06-11-24
/* Enunciado: Realizar un programa que lea de un archivo de texto un conjunto de datos compuestos de la siguiente manera: 

Nombre | Apellido | N. de cuenta | Generación | Clave facultad
Juan   | Perez    | 3302283941   | 2000       | 400

Los datos se encuentran en un archivo de texto plano, separados por un espacio entre cada dato. Escribir en archivos de texto plano: 
    1) Los números de cuenta que sean de la generación 2000. 
    2) Los Nombres y Apellidos que sean de la Clave Facultad 400.*/
/*Ejecución: ./datos_test.exe

Procesamiento completado.*/

#include <stdio.h>

int main() {
    FILE *entrada, *salidaGeneracion, *salidaFacultad;
    char nombre[50], apellido[50];
    long numeroCuenta;
    int generacion, claveFacultad;

    entrada = fopen("datos.txt", "r");
    if (entrada == NULL) {
        printf("\nError al abrir el archivo de entrada.");
        return 1;
    }

    salidaGeneracion = fopen("cuentas_generacion2000.txt", "w");
    salidaFacultad = fopen("nombres_facultad400.txt", "w");

    while (fscanf(entrada, "%s %s %ld %d %d", nombre, apellido, &numeroCuenta, &generacion, &claveFacultad) != EOF) {
        if (generacion == 2000) {
            fprintf(salidaGeneracion, "\n%ld", numeroCuenta);
        }
        if (claveFacultad == 400) {
            fprintf(salidaFacultad, "\n%s %s", nombre, apellido);
        }
    }

    fclose(entrada);
    fclose(salidaGeneracion);
    fclose(salidaFacultad);

    printf("\nProcesamiento completado.");
    return 0;
}