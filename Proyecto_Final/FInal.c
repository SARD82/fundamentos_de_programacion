// Proyecto_final
//Alumno: Durán Rendón Santiago. 
//08-11-24

//Los comentarios de una línea se usaran para la documentación del programa.
/*Los comentarios de multiple línea seran para explicar información que desconocia*/

//Bibliotecas a usar 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Funcion principal

/*Cuando ejecutas un programa en C desde la terminal, puedes darle información adicional. 
Esta información se llama argumentos de línea de comandos, argc y argv son la manera en que el programa recibe esos datos.

-argc: Representa el número de argumentos que se le pasan al programa.

    Ejemplo: Si ejecutas ./programa 1 imagen.bmp, argc tendrá el valor 3 porque hay tres partes en el comando: ./programa, 1, y imagen.bmp.

-argv: Es un arreglo de cadenas de texto (o strings) donde cada posición almacena uno de los argumentos pasados.

    En el mismo ejemplo (./programa 1 imagen.bmp):
        argv[0] sería ./programa (el nombre del programa).
        argv[1] sería 1 (la opción).
        argv[2] sería imagen.bmp (el nombre del archivo de imagen).
/*Cuando ejecutas un programa en C desde la terminal, puedes darle información adicional. 
Esta información se llama argumentos de línea de comandos, argc y argv son la manera en que el programa recibe esos datos.

-argc: Representa el número de argumentos que se le pasan al programa.

    Ejemplo: Si ejecutas ./programa 1 imagen.bmp, argc tendrá el valor 3 porque hay tres partes en el comando: ./programa, 1, y imagen.bmp.

-argv: Es un arreglo de cadenas de texto (o strings) donde cada posición almacena uno de los argumentos pasados.

    En el mismo ejemplo (./programa 1 imagen.bmp):
        argv[0] sería ./programa (el nombre del programa).
        argv[1] sería 1 (la opción).
        argv[2] sería imagen.bmp (el nombre del archivo de imagen).*/

//Por la explicación anterior es necesaria la biblioteca <stlib.h>*/

int main(int argc, char *argv[]){
    //Verificación de los argumentos de línea de comandos
    //argc representa la cantidad de argumentos ingresados, incluyendo el nombre del programa
    //argv es un arreglo de cadenas que contiene los argumentos como texto

    if (argc < 3){
        printf("\nUso: %s <tipo imagen> <nombre archivo> [parametros adicionales]\n", argv[0]);

        //comando ayuda
        if (strcmp(argv[1], "-help") == 0){ /*strcmp = string comparation, los compara por el código ASCCI y devuelve 0 si son iguales, un valor negativo si la primera es menor y un valor positivo si la primera es mayor*/
            printf("Comandos disponibles: \n");
            printf("1p o 1b -> Matrices R, G, B.\n");
            printf("2p o 2b -> Matriz R.\n");
            printf("3p o 3b -> Matriz G.\n");
            printf("4p o 4b -> Matriz B.\n");
            printf("5p o 5b -> Imagen en escala de grises.\n");
            printf("6p umbral o 6b umbral -> Imagen en blanco y negro.\n");
            printf("7p o 7b -> Calculo del histograma.\n");
            printf("8p alpha o 8b alpha -> Mezcla de imagenes.\n");
            printf("9p umbral alpha o 9b umbral alpha -> Todos los procesos.\n");
            return 0;
        }//if comando de ayuda
        return 1;/*return 1 significa que no se ejecuto el codigo como se esperaba*/
    }//if

    //variables para almacenar la cabecera de la imagen
    char *operacion = argv[1];//operacion
    char tipo_imagen = argv[1][0];//primer caracterpara saber el tipo de imagen ya sea "p" o "b"
    char *nombre_archivo = argv[2];//nombre del archivo de la imagen xd
    FILE *archivo;//Puntero al archivo para leer la imagen

    //Apertura del archivo en forma binaria
    archivo = fopen(nombre_archivo, "rb");
    if (archivo == NULL){//si es null no se puede abrir
        printf("Error: No se pudo abrir el archivo %s\n", nombre_archivo);
        return 1;//Retorno de error
    }//if

    //Estructura de control para leer cabeceras segun el tipo de imagen

    //CABECERA BMP
    if (tipo_imagen == 'b'){ //usar comilla simple para comparar si no marca error
        //Lectura de la cabecera BMP
        //Cabecera tiene 54 bytes para los archivos BMP
        unsigned char BMP_cabecera[54];/*unsigned = sin signo*/
        fread(BMP_cabecera, sizeof(unsigned char), 54, archivo);

        //Sacando los datos de la cabecera. Los valores específicos de cada campo están en posiciones fijas en el arreglo BMP_cabecera
        //Validando el tipo de archivo (los primeros 2 bytes deben de ser "BM")
        if (BMP_cabecera[0] != 'B' || BMP_cabecera[1] != 'M'){/*!= es diferente*/
            printf("Error: El archivo no es un BMP valido\n");
            fclose(archivo);
            return 1;
        }//if

        //tamaño del archivo en bytes (4 bytes en BMP_cabecera[2] hasta BMP_cabecera[5])
        int tamano_archivo = *(int*)&BMP_cabecera[2];//Obteniendo la dirección de memoria de esos bytes y pasandolos a enteros

        //Sacando los valores de la cabecera
        //Dimensiones de la imagen (ancho y alto en pixeles)
        int ancho = *(int*)&BMP_cabecera[18];
        int alto = *(int*)&BMP_cabecera[22];

        //Profundidad de color en bits por pixel (2 bytes en BMP_cabecera[28] hasta BMP_cabecera[29])
        short profundidad_color = *(short*)&BMP_cabecera[28];/*es como in int pero para valores mas pequeños*/

        //Imprimiendo la informacion de la cabecera
        printf("Informacion de la cabecera de la imagen BMP:\n");//no usare acentos y la letra ñ ya que al imprimir en la terminal luego salen caracteres raros en lugar de los esperados
        printf("Tamano del archivo: %d bytes\n", tamano_archivo);
        printf("Dimensiones: &d x %d pixeles\n", ancho, alto);
        printf("Profundidad de color; %d bits\n", profundidad_color);
        
        //SEPARAR RGB BMP
        if (strcmp(operacion, "1b") == 0){
        
            //Verificar si la imagen es de 24 bits(RGB)
            if (profundidad_color != 24){
                printf("Error: Solo se soportan imagenes BMP a color de 24 bits\n");
                fclose(archivo);
                return 1;
            }//if

            //Crear archivos para cada canal (R, G y B)
            FILE *archivo_rojo = fopen("canal_rojo.bmp", "wb");/*wb = abierto escritura modo binario*/
            FILE *archivo_verde = fopen("canal_verde.bmp", "wb");
            FILE *archivo_azul = fopen("canal_azul.bmp", "wb");

            if (!archivo_rojo || !archivo_verde || !archivo_azul){
                printf("Error: No se pudieron crear los archivos de los canales RGB\n");
                fclose(archivo);
                return 1;
            }//if

            //Escribir la cabecera en los archivos de cada canal (especificar las cabecera no sobra)
            fwrite(BMP_cabecera, sizeof(unsigned char), 54, archivo_rojo);
            fwrite(BMP_cabecera, sizeof(unsigned char), 54, archivo_verde);
            fwrite(BMP_cabecera, sizeof(unsigned char), 54, archivo_azul);

            //Ajustar la cabecera para representar un solo canal en cada archivo
            BMP_cabecera[28] = 8;//Cambiar la profundidad de color a 8 bits para escala de grises
            fwrite(BMP_cabecera, sizeof(unsigned char), 54, archivo_rojo);
            fwrite(BMP_cabecera, sizeof(unsigned char), 54, archivo_verde);
            fwrite(BMP_cabecera, sizeof(unsigned char), 54, archivo_azul);

            //procesamiento de cada pixel de la imagen
            //Alinear a 4 bytes
            int padding = (4 - (ancho * 3) % 4) % 4;/*padding = Rellenar y alinear los miembros de una estructura*/
            for (int i = 0; i < alto; i++){
                for (int j = 0; j < ancho; j++){
                    unsigned char colores[3];//Declarando arreglo para RGB
                    fread(colores, sizeof(unsigned char), 3, archivo);//Leer RGB

                    //Escribir el valor del canal rojo en archivo_rojo
                    fwrite(&colores[2], sizeof(unsigned char), 1, archivo_rojo);
                    //Escribir el valor del canal rojo en archivo_verde
                    fwrite(&colores[2], sizeof(unsigned char), 1, archivo_verde);
                    //Escribir el valor del canal rojo en archivo_azul
                    fwrite(&colores[2], sizeof(unsigned char), 1, archivo_azul);
                }//for

                // Saltar el relleno en el archivo original y agregar el relleno a los archivos de salida
                fseek(archivo, padding, SEEK_CUR);
                for (int p = 0; p < padding; p++) {
                    fputc(0, archivo_rojo);
                    fputc(0, archivo_verde);
                    fputc(0, archivo_azul);
                }//for
            }//for

            //Cerrar los archivos de cada canal
            fclose(archivo_rojo);
            fclose(archivo_verde);
            fclose(archivo_azul);
            printf("Los canales RGB se han separado en archivos individuales\n");
        }//if
        else{
            printf("Operacion no soportada o archivo no valido\n");
        }//else

        //CONVERSION A ESCALA DE GRISES BMP
        if (strcmp(operacion, "5b") == 0){

            //Verificar si la imagen es de 24 bits(RGB)
            if (profundidad_color != 24){
                printf("Error: Solo se soportan imagenes BMP a color de 24 bits\n");
                fclose(archivo);
                return 1;
            }//if

            //Crear archivo para l aimagen en escala de grises
            FILE *archivo_gris = fopen("escala_grises.bmp", "wb");
            if (!archivo_gris){
                printf("Error: No se pudo crear el archivo de escala de grises\n");
                fclose(archivo);
                return 1;
            }//if

            //Escribir la cabecera en el archivo de escala de grises (especificar las cabecera no sobra)
            fwrite(BMP_cabecera, sizeof(unsigned char), 54, archivo_gris);

            //Proceso de cada pixel para convertir a escala de grises
            int padding = (4 -(ancho * 3) % 4) %4;
            for (int i = 0; i < alto; i++) {
                for (int j = 0; j < ancho; j++) {
                    unsigned char colores[3];
                    fread(colores, sizeof(unsigned char), 3, archivo); // Leer RGB

                    // Calcular el valor de gris como el promedio de R, G, B
                    unsigned char gris = (colores[0] + colores[1] + colores[2]) / 3;

                    // Escribir el valor de gris en los tres canales para BMP
                    fwrite(&gris, sizeof(unsigned char), 1, archivo_gris);
                    fwrite(&gris, sizeof(unsigned char), 1, archivo_gris);
                    fwrite(&gris, sizeof(unsigned char), 1, archivo_gris);
                }//for
                fseek(archivo, padding, SEEK_CUR); // Saltar el relleno en el archivo original
                for (int p = 0; p < padding; p++) {
                    fputc(0, archivo_gris); // Agregar el relleno en el archivo de salida
                }//for
            }//for

            //Cerrar el archivo de escala de grises
            fclose(archivo_gris);
            printf("La imagen se ha convertido a escala de grises en escala_grises.bmp\n");
        }//if
        else {
            printf("Operacion no soportada o archivo no valido\n");
        }//else
    }//if

    //CABECERA PNM
    else if (tipo_imagen == 'p'){
        //Lectura de la cabecera PNM
        char numero_magico[3];//Los primeros dos caracteres del archivo PNM
        fscanf(archivo, "%2s", numero_magico);

        //Validando el tipo de archivo PNM
        if (strcmp(numero_magico, "P3") != 0 && strcmp(numero_magico, "P6") != 0){
            printf("Error: El archivo no es un PNM valido (solo P3 y P6 son permitidos)\n");
            fclose(archivo);
            return 1;
        }//if

        //Lectura de comentarios y las dimensiones de la imagen
        int ancho, alto, max_valor;
        char comentario[100];

        //Ignorando los comentarios presentes en la imagen
        fscanf(archivo, "#%[^\n]\n", comentario);//Escane si dentro de la imagen esta el caracter "#" que es como se scribe un comentario en las imagenes y se salta la linea completa

        //Leer las dimensiones y el valor maximo de los pixeles
        fscanf(archivo, "%d %d %d", &ancho, &alto, &max_valor);

        //Imprimiendo la informacion de la cabecera
        printf("Informacion de la imagen PNM:\n");
        printf("Numero magico: %s\n", numero_magico);
        printf("Dimensiones: %d x %d pixeles\n", ancho, alto);
        printf("Valor maximo: %d\n", max_valor);

        //SEPARAR RGB PNM
        if (strcmp(operacion, "1p") == 0){
            // Crear archivos para cada canal
            FILE *archivo_rojo = fopen("canal_rojo.pnm", "wb");
            FILE *archivo_verde = fopen("canal_verde.pnm", "wb");
            FILE *archivo_azul = fopen("canal_azul.pnm", "wb");

            if (!archivo_rojo || !archivo_verde || !archivo_azul) {
                printf("Error: No se pudieron crear los archivos de canales RGB.\n");
                fclose(archivo);
                return 1;
            }//if

            // Escribir las cabeceras en cada archivo PNM (especificar las cabecera no sobra)
            fprintf(archivo_rojo, "%s\n%d %d\n%d\n", numero_magico, ancho, alto, max_valor);
            fprintf(archivo_verde, "%s\n%d %d\n%d\n", numero_magico, ancho, alto, max_valor);
            fprintf(archivo_azul, "%s\n%d %d\n%d\n", numero_magico, ancho, alto, max_valor);

            // Procesamiento de cada píxel
            if (strcmp(numero_magico, "P6") == 0) {
                fgetc(archivo); // Leer el salto de línea después del valor máximo en P6
                unsigned char colores[3];
                for (int i = 0; i < ancho * alto; i++) {
                    fread(colores, sizeof(unsigned char), 3, archivo);
                    fwrite(&colores[0], sizeof(unsigned char), 1, archivo_rojo); // Escribir canal rojo
                    fwrite(&colores[1], sizeof(unsigned char), 1, archivo_verde); // Escribir canal verde
                    fwrite(&colores[2], sizeof(unsigned char), 1, archivo_azul);  // Escribir canal azul
                }//for
            }//if
            else if (strcmp(numero_magico, "P3") == 0) {
                int r, g, b;
                for (int i = 0; i < ancho * alto; i++) {
                    fscanf(archivo, "%d %d %d", &r, &g, &b);
                    fprintf(archivo_rojo, "%d\n", r);
                    fprintf(archivo_verde, "%d\n", g);
                    fprintf(archivo_azul, "%d\n", b);
                }//for
            }//else if

            // Cierre de archivos de canal
            fclose(archivo_rojo);
            fclose(archivo_verde);
            fclose(archivo_azul);
            printf("Los canales RGB se han separado en archivos individuales.\n");
        }//if
        else {
            printf("Operación no soportada o tipo de archivo no válido.\n");
        }//else
    
        //CONVERSION A ESCALA DE GRISES PNM
        if (strcmp(operacion, "5p") == 0){//Comillas dobles para comparar

            //Crear archivo para la imagen escala de grises
            FILE *archivo_gris = fopen("escala_grises.pnm", "wb");
            if (!archivo_gris){
                printf("Error: No se pudo crear el archivo de escala de grises\n");
                fclose(archivo);
                return 1;
            }//if

            //Escribir la cabecera en el archivo de escala de grises (especificar las cabecera no sobra)
            fprintf(archivo_gris, "%s\n%d %d\n%d\n", numero_magico, ancho, alto, max_valor);

            //Procesamiento de cada pixel para convertir a escala de grises
            if (strcmp(numero_magico, "P6") == 0) {
                fgetc(archivo); // Leer el salto de línea después del valor máximo en P6
                unsigned char colores[3];
                for (int i = 0; i < ancho * alto; i++) {
                    fread(colores, sizeof(unsigned char), 3, archivo);
                    unsigned char gris = (colores[0] + colores[1] + colores[2]) / 3;
                    fwrite(&gris, sizeof(unsigned char), 1, archivo_gris);
                }//for
            }//if
            else if (strcmp(numero_magico, "P3") == 0){
                int r, g, b;
                for (int i = 0; i < ancho * alto; i++) {
                    fscanf(archivo, "%d %d %d", &r, &g, &b);//Los valores de RGB para el promedio
                    int gris = (r + g + b) / 3;
                    fprintf(archivo_gris, "%d\n", gris);
                }//for
            }//else if

            //Cerrar el archivo de escala de grises
            fclose(archivo_gris);
            printf("La imagen se ha convertido a escala de grises en escala_grises.pnm\n");
        }//if
        else {
            printf("Operación no soportada o tipo de archivo no válido.\n");
        }//else

    
    }//else if
    else {
        printf("Error: Tipo de imagen no reconocido\n");
        fclose(archivo);
        return 1;
    }//else

    //cierre del archivo
    fclose(archivo);
    return 0;//Fin programa
}//main
//NOTA: La impementación de estas conversiones se vio un dia de clase antes del examen del segubndo parcial