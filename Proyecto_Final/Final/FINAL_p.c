//Proyecto_final
//Alumnos: Durán Rendón Santiago.
//20-11-24

//Los comentarios de una línea se usaran para la documentación del programa.
/*Los comentarios de multiple línea seran para explicar información que desconocia.*/

/*No se usaran acentos dentro de lo que se imprimira en la terminal ya que luego da caracteres extraños.*/

//BIBLIOTECAS A USAR 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//DEFINIR máximo para alto y ancho de la imagen
#define MAX_ANCHO 512//Define un límite máximo para el ancho de la imagen
#define MAX_ALTO 512//Define un límite máximo para el alto de la imagen

//Matrices estáticas para almacenar los canales y declaración de variables.
int alto, ancho, umbral;
int alto_frente, ancho_frente, alto_fondo, ancho_fondo;
unsigned char matriz[MAX_ALTO][MAX_ANCHO][3];
unsigned char canal_rojo[MAX_ALTO][MAX_ANCHO][3];
unsigned char canal_verde[MAX_ALTO][MAX_ANCHO][3];
unsigned char canal_azul[MAX_ALTO][MAX_ANCHO][3];
unsigned char grises[MAX_ALTO][MAX_ANCHO][3];
unsigned char bn[MAX_ALTO][MAX_ANCHO][3];
int histR[256], histG[256], histB[256], histGris[256];
unsigned char frente[MAX_ALTO][MAX_ANCHO][3];
unsigned char fondo[MAX_ALTO][MAX_ANCHO][3];
unsigned char mezcla[MAX_ALTO][MAX_ANCHO][3];

/*prototipos = Si los prototipos no estuvieran presentes y las funciones estuvieran definidas después del main, el compilador generaría un error o advertencia de que las funciones no están definidas en el momento en que son llamadas.*/
//PROTOTIPOS
void mostrar_ayuda();
void leer_cabecera_bmp(const char *nombreArchivo);
void leer_cabecera_pnm(const char *nombreArchivo);
void leer_imagen_bmp(char *nombre_archivo, unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], int *alto, int *ancho);
void escribir_imagen_bmp(char *nombre_archivo, unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], int alto, int ancho);
void separar_canal_rojo_bmp(unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], unsigned char rojo[MAX_ALTO][MAX_ANCHO][3], int alto, int ancho);
void separar_canal_verde_bmp(unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], unsigned char verde[MAX_ALTO][MAX_ANCHO][3], int alto, int ancho);
void separar_canal_azul_bmp(unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], unsigned char azul[MAX_ALTO][MAX_ANCHO][3], int alto, int ancho);
void leer_imagen_pnm(char *nombre_archivo, unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], int *alto, int *ancho);
void escribir_imagen_pnm(char *nombre_archivo, unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], int alto, int ancho);
void separar_canal_rojo_pnm(unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], unsigned char rojo[MAX_ALTO][MAX_ANCHO][3], int alto, int ancho);
void separar_canal_verde_pnm(unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], unsigned char verde[MAX_ALTO][MAX_ANCHO][3], int alto, int ancho);
void separar_canal_azul_pnm(unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], unsigned char azul[MAX_ALTO][MAX_ANCHO][3], int alto, int ancho);
void convertir_a_grises(unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], unsigned char grises[MAX_ALTO][MAX_ANCHO][3], int alto, int ancho);
void convertir_a_bn(unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], unsigned char bn[MAX_ALTO][MAX_ANCHO][3], int alto, int ancho, int umbral);
void calcular_histograma_color(unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], int alto, int ancho, int histR[256], int histG[256], int histB[256]);
void calcular_histograma_grises(unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], int alto, int ancho, int hist[256]);
void escribir_histograma(const char *nombre_archivo, int histograma[256]);
void mezclar_imagenes(unsigned char frente[MAX_ALTO][MAX_ANCHO][3], unsigned char fondo[MAX_ALTO][MAX_ANCHO][3], unsigned char mezcla[MAX_ALTO][MAX_ANCHO][3],int alto, int ancho, int alpha);

//FUNCIÓN PRINCIPAL

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
        argv[2] sería imagen.bmp (el nombre del archivo de imagen).

Por la explicación anterior es necesaria la biblioteca <stlib.h>*/

int main(int argc, char *argv[]){
    //VERIFICAR si se proporcionaron los argumentos necesarios en la línea de comandos.
    //argc representa la cantidad de argumentos ingresados, incluyendo el nombre del programa.
    //argv es un arreglo de cadenas que contiene los argumentos como texto.
    if (argc < 2 || argc > 6){
        printf("Error: No se proporcionaron los argumentos correctos.\n");
        printf("Use el comando -help para obtener mas informacion.\n");
        return 1;/*return 1 significa que no se ejecuto el código como se esperaba.*/
    }//if

    //VERIFICAR si el primer argumento es -help
    /*strcmp = string comparation, los compara por el código ASCCI y devuelve 0 si son iguales, un valor negativo si la primera es menor y un valor positivo si la primera es mayor.*/
    if (strcmp(argv[1], "-help") == 0){/*Comillas dobles "" para comparar char.*/
        mostrar_ayuda();
        return 0;/*Return 0 significa que se ejecuto el código como se esperaba.*/
    }//if

    //LEER cabeceras según el formato
    if (strcmp(argv[1], "1b") == 0 || strcmp(argv[1], "2b") == 0 || strcmp(argv[1], "3b") == 0 || strcmp(argv[1], "4b") == 0 || strcmp(argv[1], "5b") == 0 || strcmp(argv[1], "6b") == 0 || strcmp(argv[1], "7b") == 0 || strcmp(argv[1], "8b") == 0 || strcmp(argv[1], "9b") == 0){
        leer_cabecera_bmp(argv[2]);
    }else if (strcmp(argv[1], "1p") == 0 || strcmp(argv[1], "2p") == 0 || strcmp(argv[1], "3p") == 0 || strcmp(argv[1], "4p") == 0 || strcmp(argv[1], "5p") == 0 || strcmp(argv[1], "6p") == 0 || strcmp(argv[1], "7p") == 0 || strcmp(argv[1], "8p") == 0 || strcmp(argv[1], "9p") == 0){
        leer_cabecera_pnm(argv[2]);
    }//else if

    //VERIFICAR comandos para lectura de separación de canales bmp
    if (strcmp(argv[1], "1b") == 0) {
        //SEPARAR todos los canales
        leer_imagen_bmp(argv[2], matriz, &alto, &ancho);
        
        separar_canal_rojo_bmp(matriz, canal_rojo, alto, ancho);
        separar_canal_verde_bmp(matriz, canal_verde, alto, ancho);
        separar_canal_azul_bmp(matriz, canal_azul, alto, ancho);
        
        escribir_imagen_bmp("rojo.bmp", canal_rojo, alto, ancho);
        escribir_imagen_bmp("verde.bmp", canal_verde, alto, ancho);
        escribir_imagen_bmp("azul.bmp", canal_azul, alto, ancho);
        printf("\nSe han creado los archivos rojo.bmp, verde.bmp y azul.bmp.\n");
        printf("\n------------------------------------------------------------------------\n");
    } else if (strcmp(argv[1], "2b") == 0) {
        //SOLO canal rojo
        leer_imagen_bmp(argv[2], matriz, &alto, &ancho);
        separar_canal_rojo_bmp(matriz, canal_rojo, alto, ancho);
        escribir_imagen_bmp("rojo.bmp", canal_rojo, alto, ancho);
        printf("\nSe ha creado el archivo rojo.bmp.\n");
        printf("\n------------------------------------------------------------------------\n");
    } else if (strcmp(argv[1], "3b") == 0) {
        //SOLO canal verde
        leer_imagen_bmp(argv[2], matriz, &alto, &ancho);
        separar_canal_verde_bmp(matriz, canal_verde, alto, ancho);
        escribir_imagen_bmp("verde.bmp", canal_verde, alto, ancho);
        printf("\nSe ha creado el archivo verde.bmp.\n");
        printf("\n------------------------------------------------------------------------\n");
    } else if (strcmp(argv[1], "4b") == 0) {
        //SOLO canal azul
        leer_imagen_bmp(argv[2], matriz, &alto, &ancho);
        separar_canal_azul_bmp(matriz, canal_azul, alto, ancho);
        escribir_imagen_bmp("azul.bmp", canal_azul, alto, ancho);
        printf("\nSe ha creado el archivo azul.bmp.\n");
        printf("\n------------------------------------------------------------------------\n");
    } else if (strcmp(argv[1], "5b") == 0) {
        //CONVERTIR a grises
        leer_imagen_bmp(argv[2], matriz, &alto, &ancho);
        convertir_a_grises(matriz, grises, alto, ancho);
        escribir_imagen_bmp("grises.bmp", grises, alto, ancho);
        printf("\nSe ha creado el archivo grises.bmp.\n");
        printf("\n------------------------------------------------------------------------\n");
    } else if (strcmp(argv[1], "6b") == 0) {
        //CONVERTIR a blanco y negro
        //CONVERTIR el umbral de string a entero
        umbral = atoi(argv[3]);/*atoi = convertir una serie de caracteres en un valor entero.*/
        leer_imagen_bmp(argv[2], matriz, &alto, &ancho);
        convertir_a_bn(matriz, bn, alto, ancho, umbral);
        escribir_imagen_bmp("bn.bmp", bn, alto, ancho); 
        printf("\nSe ha creado el archivo bn.bmp.\n");
        printf("\n------------------------------------------------------------------------\n");
    } else if (strcmp(argv[1], "7b") == 0) {
        leer_imagen_bmp(argv[2], matriz, &alto, &ancho);

        //CALCULAR histogramas
        calcular_histograma_color(matriz, alto, ancho, histR, histG, histB);
        calcular_histograma_grises(matriz, alto, ancho, histGris);
        
        //ESCRIBIR archivos
        escribir_histograma("histR.txt", histR);
        escribir_histograma("histG.txt", histG);
        escribir_histograma("histB.txt", histB);
        escribir_histograma("histGris.txt", histGris);
        
        printf("Histogramas generados exitosamente\n");
        printf("\n------------------------------------------------------------------------\n");
    } else if (strcmp(argv[1], "8b") == 0) {
        //VERIFICAR número de argumentos
        if (argc != 5) {
            printf("Error: Uso correcto: %s 8b frente.bmp fondo.bmp alpha\n", argv[0]);
            return 1;
        }//if
        
        //CONVERTIR alpha a entero
        int alpha = atoi(argv[4]);
        
        //LEER ambas imágenes
        leer_imagen_bmp(argv[2], frente, &alto_frente, &ancho_frente);
        leer_imagen_bmp(argv[3], fondo, &alto_fondo, &ancho_fondo);
        
        //VERIFICAR que las imágenes tengan el mismo tamaño
        if (alto_frente != alto_fondo || ancho_frente != ancho_fondo) {
            printf("Error: Las imagenes deben tener el mismo tamano\n");
            return 1;
        }//if
        
        //REALIZAR la mezcla
        mezclar_imagenes(frente, fondo, mezcla, alto_frente, ancho_frente, alpha);
        
        //GUARDAR resultado
        escribir_imagen_bmp("mezcla.bmp", mezcla, alto_frente, ancho_frente);
        printf("\nMezcla realizada con exito. Resultado guardado en 'mezcla.bmp'\n");
        printf("\n------------------------------------------------------------------------\n");
    } else if (strcmp(argv[1], "9b") == 0) {
        //REALIZAR todos los comandos
        //VERIFICAR argumentos
        if (argc != 6) {
            printf("Error: Uso correcto: %s 9b imagen.bmp fondo.bmp umbral alpha\n", argv[0]);
            return 1;
        }//if

        int umbral = atoi(argv[4]);
        int alpha = atoi(argv[5]);

        //VERIFICAR rangos
        if (umbral < 0 || umbral > 255 || alpha < 0 || alpha > 255) {
            printf("Error: umbral y alpha deben estar entre 0 y 255\n");
            return 1;
        }//if

        printf("\n=== Procesando todos los comandos para BMP ===\n");

        //1. LEER imágenes y separar canales RGB
        printf("\n1. Separando canales RGB...\n");
        leer_imagen_bmp(argv[2], matriz, &alto, &ancho);
        separar_canal_rojo_bmp(matriz, canal_rojo, alto, ancho);
        separar_canal_verde_bmp(matriz, canal_verde, alto, ancho);
        separar_canal_azul_bmp(matriz, canal_azul, alto, ancho);
        escribir_imagen_bmp("rojo.bmp", canal_rojo, alto, ancho);
        escribir_imagen_bmp("verde.bmp", canal_verde, alto, ancho);
        escribir_imagen_bmp("azul.bmp", canal_azul, alto, ancho);

        //2. ESCALA de grises
        printf("\n2. Generando imagen en escala de grises...\n");
        convertir_a_grises(matriz, grises, alto, ancho);
        escribir_imagen_bmp("grises.bmp", grises, alto, ancho);

        //3. BLANCO y negro
        printf("\n3. Generando imagen en blanco y negro...\n");
        convertir_a_bn(matriz, bn, alto, ancho, umbral);
        escribir_imagen_bmp("bn.bmp", bn, alto, ancho);

        //4. HISTOGRAMAS
        printf("\n4. Calculando histogramas...\n");
        calcular_histograma_color(matriz, alto, ancho, histR, histG, histB);
        calcular_histograma_grises(matriz, alto, ancho, histGris);
        escribir_histograma("histR.txt", histR);
        escribir_histograma("histG.txt", histG);
        escribir_histograma("histB.txt", histB);
        escribir_histograma("histGris.txt", histGris);

        //5. MEZCLA de imágenes
        printf("\n5. Mezclando imagenes...\n");
        leer_imagen_bmp(argv[3], fondo, &alto_fondo, &ancho_fondo);
        if (alto != alto_fondo || ancho != ancho_fondo) {
            printf("Error: Las imagenes deben tener el mismo tamano\n");
            return 1;
        }//if 
        mezclar_imagenes(matriz, fondo, mezcla, alto, ancho, alpha);
        escribir_imagen_bmp("mezcla.bmp", mezcla, alto, ancho);

        printf("\n=== Procesamiento completado ===\n");
        printf("Archivos generados:\n");
        printf("- rojo.bmp, verde.bmp, azul.bmp\n");
        printf("- grises.bmp\n");
        printf("- bn.bmp\n");
        printf("- histR.txt, histG.txt, histB.txt, histGris.txt\n");
        printf("- mezcla.bmp\n");
        printf("\n===============================================================================\n");
    //VERIFICAR comandos para lectura de separación de canales pnm
    } else if (strcmp(argv[1], "1p") == 0) {
        //SEPARAR todos los canales
        leer_imagen_pnm(argv[2], matriz, &alto, &ancho);
        
        separar_canal_rojo_pnm(matriz, canal_rojo, alto, ancho);
        separar_canal_verde_pnm(matriz, canal_verde, alto, ancho);
        separar_canal_azul_pnm(matriz, canal_azul, alto, ancho);
        
        escribir_imagen_pnm("rojo.pnm", canal_rojo, alto, ancho);
        escribir_imagen_pnm("verde.pnm", canal_verde, alto, ancho);
        escribir_imagen_pnm("azul.pnm", canal_azul, alto, ancho);
        printf("\nSe han creado los archivos rojo.pnm, verde.pnm y azul.pnm.\n");
        printf("\n------------------------------------------------------------------------\n");
    } else if (strcmp(argv[1], "2p") == 0) {
        //SOLO canal rojo
        leer_imagen_pnm(argv[2], matriz, &alto, &ancho);
        separar_canal_rojo_pnm(matriz, canal_rojo, alto, ancho);
        escribir_imagen_pnm("rojo.pnm", canal_rojo, alto, ancho);
        printf("\nSe ha creado el archivo rojo.pnm.\n");
        printf("\n------------------------------------------------------------------------\n");
    } else if (strcmp(argv[1], "3p") == 0) {
        //SOLO canal verde
        leer_imagen_pnm(argv[2], matriz, &alto, &ancho);
        separar_canal_verde_pnm(matriz, canal_verde, alto, ancho);
        escribir_imagen_pnm("verde.pnm", canal_verde, alto, ancho);
        printf("\nSe ha creado el archivo verde.pnm.\n");
        printf("\n------------------------------------------------------------------------\n");
    } else if (strcmp(argv[1], "4p") == 0) {
        //SOLO canal azul
        leer_imagen_pnm(argv[2], matriz, &alto, &ancho);
        separar_canal_azul_pnm(matriz, canal_azul, alto, ancho);
        escribir_imagen_pnm("azul.pnm", canal_azul, alto, ancho);
        printf("\nSe ha creado el archivo azul.pnm.\n");
        printf("\n------------------------------------------------------------------------\n");
    } else if (strcmp(argv[1], "5p") == 0) {
        //CONVERTIR a grises
        leer_imagen_pnm(argv[2], matriz, &alto, &ancho);
        convertir_a_grises(matriz, grises, alto, ancho);
        escribir_imagen_pnm("grises.pnm", grises, alto, ancho);
        printf("\nSe ha creado el archivo grises.pnm.\n");
        printf("\n------------------------------------------------------------------------\n"); 
    } else if (strcmp(argv[1], "6p") == 0) {
        //CONVERTIR a blanco y negro
        //CONVERTIR el umbral de string a entero
        umbral = atoi(argv[3]);/*atoi = convertir una serie de caracteres en un valor entero.*/
        leer_imagen_pnm(argv[2], matriz, &alto, &ancho);
        convertir_a_bn(matriz, bn, alto, ancho, umbral);
        escribir_imagen_pnm("bn.pnm", bn, alto, ancho);
        printf("\nSe ha creado el archivo bn.pnm.\n");
        printf("\n------------------------------------------------------------------------\n");
    }  else if (strcmp(argv[1], "7p") == 0) {
        //SIMILAR al 7b pero usando funciones PNM
        leer_imagen_pnm(argv[2], matriz, &alto, &ancho);
        
        //CALCULAR histogramas
        calcular_histograma_color(matriz, alto, ancho, histR, histG, histB);
        calcular_histograma_grises(matriz, alto, ancho, histGris);
        
        //ESCRIBIR archivos
        escribir_histograma("histR.txt", histR);
        escribir_histograma("histG.txt", histG);
        escribir_histograma("histB.txt", histB);
        escribir_histograma("histGris.txt", histGris);
        
        printf("Histogramas generados exitosamente\n");
        printf("\n------------------------------------------------------------------------\n");
    } else if (strcmp(argv[1], "8p") == 0) {
        //SIMILAR al 8b pero usando funciones PNM
        if (argc != 5) {
            printf("Error: Uso correcto: %s 8p frente.pnm fondo.pnm alpha\n", argv[0]);
            return 1;
        }//if
        
        int alpha = atoi(argv[4]);
        
        leer_imagen_pnm(argv[2], frente, &alto_frente, &ancho_frente);
        leer_imagen_pnm(argv[3], fondo, &alto_fondo, &ancho_fondo);
        
        if (alto_frente != alto_fondo || ancho_frente != ancho_fondo) {
            printf("Error: Las imagenes deben tener el mismo tamano\n");
            return 1;
        }//if
        
        mezclar_imagenes(frente, fondo, mezcla, alto_frente, ancho_frente, alpha);
        escribir_imagen_pnm("mezcla.pnm", mezcla, alto_frente, ancho_frente);
        printf("\nMezcla realizada con exito. Resultado guardado en 'mezcla.pnm'\n");
        printf("\n------------------------------------------------------------------------\n");
    } else if (strcmp(argv[1], "9p") == 0) {
        //REALIZAR todos los comandos
        //SIMILAR al 9b pero usando funciones PNM
        if (argc != 6) {
            printf("Error: Uso correcto: %s 9p imagen.pnm fondo.pnm umbral alpha\n", argv[0]);
            return 1;
        }//if

        int umbral = atoi(argv[4]);
        int alpha = atoi(argv[5]);

        // Verificar dimensiones
        if (alto > MAX_ALTO || ancho > MAX_ANCHO || 
            alto_fondo > MAX_ALTO || ancho_fondo > MAX_ANCHO) {
            printf("Error: Las dimensiones exceden los límites permitidos (%dx%d)\n", 
            MAX_ALTO, MAX_ANCHO);
            return 1;
        }//if

        if (umbral < 0 || umbral > 255 || alpha < 0 || alpha > 255) {
            printf("Error: umbral y alpha deben estar entre 0 y 255\n");
            return 1;
        }//if

        printf("\n=== Procesando todos los comandos para PNM ===\n");

        //MISMO proceso que 9b pero con funciones PNM
        //1. LEER imágenes y separar canales RGB
        printf("\n1. Separando canales RGB...\n");
        leer_imagen_pnm(argv[2], matriz, &alto, &ancho);
        separar_canal_rojo_pnm(matriz, canal_rojo, alto, ancho);
        separar_canal_verde_pnm(matriz, canal_verde, alto, ancho);
        separar_canal_azul_pnm(matriz, canal_azul, alto, ancho);
        escribir_imagen_pnm("rojo.pnm", canal_rojo, alto, ancho);
        escribir_imagen_pnm("verde.pnm", canal_verde, alto, ancho);
        escribir_imagen_pnm("azul.pnm", canal_azul, alto, ancho);

        //2. ESCALA de grises
        printf("\n2. Generando imagen en escala de grises...\n");
        convertir_a_grises(matriz, grises, alto, ancho);
        escribir_imagen_bmp("grises.pnm", grises, alto, ancho);

        //3. BLANCO y negro
        printf("\n3. Generando imagen en blanco y negro...\n");
        convertir_a_bn(matriz, bn, alto, ancho, umbral);
        escribir_imagen_bmp("bn.pnm", bn, alto, ancho);

        //4. HISTOGRAMAS
        printf("\n4. Calculando histogramas...\n");
        calcular_histograma_color(matriz, alto, ancho, histR, histG, histB);
        calcular_histograma_grises(matriz, alto, ancho, histGris);
        escribir_histograma("histR.txt", histR);
        escribir_histograma("histG.txt", histG);
        escribir_histograma("histB.txt", histB);
        escribir_histograma("histGris.txt", histGris);

        //5. MEZCLA de imágenes
        printf("\n5. Mezclando imagenes...\n");
        leer_imagen_pnm(argv[3], fondo, &alto_fondo, &ancho_fondo);
        if (alto != alto_fondo || ancho != ancho_fondo) {
            printf("Error: Las imagenes deben tener el mismo tamano\n");
            return 1;
        }//if 
        mezclar_imagenes(matriz, fondo, mezcla, alto, ancho, alpha);
        escribir_imagen_pnm("mezcla.pnm", mezcla, alto, ancho);
        //... resto del proceso similar a 9b pero con extensión .pnm ...

        printf("\n=== Procesamiento completado ===\n");
        printf("Archivos generados:\n");
        printf("- rojo.pnm, verde.pnm, azul.pnm\n");
        printf("- grises.pnm\n");
        printf("- bn.pnm\n");
        printf("- histR.txt, histG.txt, histB.txt, histGris.txt\n");
        printf("- mezcla.pnm\n");
        printf("\n===============================================================================\n");
    } else {
        //SI NO se conoce el argumento, mostrar error.
        printf("Error: Comando no reconocido.\n");
        printf("Use el comando -help para obtener mas informacion.\n");
        return 1;
    }//else

    return 0;
}//int main
    
//FUNCIÓN PARA MOSTRAR LA AYUDA DEL PROGRAMA (-help)
void mostrar_ayuda(){
    printf("\n--------------------------------------------------------------------------------------------------------------\n");//Para separar y mayor comprención al usuario.
    printf("Uso del programa:\n");
    printf("1p o 1b -> Extrar matrices R, G, B de una imagen.\n");
    printf("2p o 2b -> Extraer unicamente la matriz R.\n");
    printf("3p o 3b -> Extraer unicamente la matriz G.\n");
    printf("4p o 4b -> Extraer unicamente la matriz B.\n");
    printf("5p o 5b -> Generar imagen en escala de grises.\n");
    printf("6p umbral o 6b umbral -> Generar imagen en blanco y negro con umbral (0-255).\n");
    printf("7p o 7b -> Calcular y guardar el histograma.\n");
    printf("8p alpha o 8b alpha -> Mezclar dos imagenes con coeficiente alpha (0-255).\n");
    printf("9p umbral alpha o 9b umbral alpha -> Realizar todos los procesos sobre las imagenes.\n");
    printf("-help -> Mostrar este menu de ayuda.\n");
    printf("\n--------------------------------------------------------------------------------------------------------------\n");//Para separar y mayor comprención al usuario.
    printf("\nUso: <tipo imagen> <nombre archivo> [parametros adicionales]\n");
    printf("Ejemplos de uso:\n");
    printf("programa 1p/1p imagen.pnm\n");
    printf("programa 2p/2p imagen.pnm\n");
    printf("programa 3p/3p imagen.pnm\n");
    printf("programa 4p/4p imagen.pnm\n");
    printf("programa 5b/5p imagen.bmp\n");
    printf("programa 6b/6p imagen.bmp umbral\n");
    printf("programa 7b/7p imagen.bmp\n");
    printf("programa 8b/8p frente.pnm fondo.pnm alpha\n");
    printf("programa 9b/9p imagen1.pnm(Esta primera sera la imagen que haga todos los procesos) imagen2.bmp umbral alpha\n");
    printf("\n--------------------------------------------------------------------------------------------------------------\n");//Para separar y mayor comprención al usuario.
}//void mostrar_ayuda

//LEER CABECERA BMP
void leer_cabecera_bmp(const char *nombre_archivo){/*const =  especifica que el valor de una variable es constante e indica al compilador que evite que el programador lo modifique.*/
    FILE *archivo = fopen(nombre_archivo, "rb");/*rb = read binary, abrir un archivo binario existente para lectura.*/
    if (!archivo){/*! = NOT, por tanto si no es el archivo, se ejecuta el error.*/
        printf("Error: No se pudo abrir el archivo %s.\n", nombre_archivo);
        return;/*fuerza una salida inmediata de la función en que se encuentra.*/
    }//if

    //VARIABLES para los campos de la cabecera bmp
    unsigned short tipo, planos, bpp;/*unsigned = sin signo, short =  entero de complemento a dos con signo de 16 bits . Tiene un valor mínimo de -32.768 y un valor máximo de 32.767, bpp = bits por pixel.*/
    unsigned int tamano, reservado, offset, tamanoDIB;//tamano = tamaño.
    int ancho, alto;

    //LEER los campos de la cabecera
    fread(&tipo, sizeof(unsigned short), 1, archivo);/*sizeof = Se utiliza para saber el tamaño de una variable, tipo de dato, objeto de clases, entre otros.*/
    fread(&tamano, sizeof(unsigned int), 1, archivo);
    fread(&reservado, sizeof(unsigned int), 1, archivo);
    fread(&offset, sizeof(unsigned int), 1, archivo);
    fread(&tamanoDIB, sizeof(unsigned int), 1, archivo);
    fread(&ancho, sizeof(unsigned int), 1, archivo);
    fread(&alto, sizeof(unsigned int), 1, archivo);
    fread(&planos, sizeof(unsigned int), 1, archivo);
    fread(&bpp, sizeof(unsigned int), 1, archivo);

    //MOSTRAR la información de la cabecera bmp
    printf("\n--------------------------------------------------------------------------------------------------------------\n");//Para separar y mayor comprención al usuario.
    printf("Informacion de la cabecera bmp:\n");
    printf("Tamano del archivo: %u bytes.\n", tamano);/*%u = se usa pra indicar un entero sin signo.*/
    printf("Dimensiones: %dx%d pixeles.\n", ancho, alto);
    printf("Bits por pixel: %u.\n", bpp);
    printf("Offset de datos: %u bytes.\n", offset);
    printf("\n------------------------------------------------------------------------\n");

    fclose(archivo);
}//void leer_cabecera_bmp

//LEER CABECERA BMP
void leer_cabecera_pnm(const char *nombre_archivo){
    FILE *archivo = fopen(nombre_archivo, "r");/*r = read*/
    if (!archivo){//! = NOT, por tanto si no es el archivo, se ejecuta el error
        printf("Error: No se pudo abrir el archivo %s.\n", nombre_archivo);
        return;
    }//if

    //VARIABLES para los campos de la cabecera pnm
    char numero_magico[3];
    int ancho, alto, maxval;

    //LEER el número mágico
    fscanf(archivo, "%2s", numero_magico);/*%s = para indicar una cadena de caracteres, numero mágico = los primeros dos caracteres del archivo PNM.*/

    //SALTAR comentarios, si es que hay claro.
    char c = fgetc(archivo);/*lee un único carácter sin signo de la ruta de entrada en la posición actual y aumenta el puntero de archivo asociado, si lo hay, para que apunte al siguiente carácter.*/
    while (c == '#'){/*Si dentro de la imagen esta el caracter "#", se usan comillas simples para caracteres y cadenas literales.*/
        while (fgetc(archivo) != '\n');//Leer hasta el final de la línea.
        c = fgetc(archivo);
    }//while
    ungetc(c, archivo);//Regresar el caracter que no era un comentario.

    //LEER dimensiones y maxval
    fscanf(archivo, "%d %d %d", &ancho, &alto, &maxval);

    //MOSTRAR la información de la cabecera
    printf("\n--------------------------------------------------------------------------------------------------------------\n");//Para separar y mayor comprención al usuario.
    printf("Informacion de la cabecera pnm:\n");
    printf("Numero magico: %s.\n", numero_magico);
    printf("Dimensiones: %dx%d pixeles.\n", ancho, alto);
    printf("Valor maximo: %d.\n", maxval);
    printf("\n--------------------------------------------------------------------------------------------------------------\n");//Para separar y mayor comprención al usuario.

    fclose(archivo);
}//leer_cabecera_pnm

//FUNCIONES PARA LEER Y SEPARAR LOS CANALES RGB BMP (esto se vio en una clase de la materia)

/*Todos los ficheros abiertos tienen un indicador para saber por dónde se va en su lectura o escritura. Es el puntero de acceso al fichero. El tipo de este puntero es off_t, pero en realidad en un número entero. Este número indica cuál es la próxima posición del fichero que se va a leer o escribir. La primera posición del fichero tiene el valor 0, la última posición del fichero tiene un valor igual al tamaño del fichero. Para poder saber o modificar la posición actual de un fichero, se usa la llamada al sistema lseek, cuyo prototipo es:
off_t lseek(int fildes, off_t desplazamiento, int dOnde); 
Si queremos cambiar la posición del puntero de acceso, realizamos la llamada al sistema con el descriptor del fichero cuyo puntero queremos modificar. Para modificar el puntero se indica un desplazamiento (segundo parámetro) tanto positivo como negativo, con respecto a uno de tres puntos de referencia (tercer parámetro):

Tercer parámetro	Punto de referencia
SEEK_SET	        Comienzo del fichero
SEEK_CUR	        Punto actual
SEEK_END	        Fin del fichero*/

//LEER IMAGEN BMP
void leer_imagen_bmp(char *nombre_archivo, unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], int *alto, int *ancho) {
    FILE *archivo = fopen(nombre_archivo, "rb");
    //DECLARAR variables
    int bytes_por_linea, padding, i, j;
    
    //MENSAJE de error
    if (archivo == NULL) {/*si es null no se puede abrir osea se utiliza para indicar que un puntero no apunta a ningún objeto o función válidos*/
        printf("Error al abrir el archivo %s\n", nombre_archivo);//Mensaje de error.
        return;/*Retornar sin valor ya que es un void.*/
    }//if

    //LEER la cabecera BMP (ignorando valores irrelevantes)
    unsigned char cabecera_bmp[54];
    fread(cabecera_bmp, sizeof(unsigned char), 54, archivo);

    //OBTENER dimensiones de la imagen
    *ancho = *(int*)&cabecera_bmp[18];
    *alto = *(int*)&cabecera_bmp[22];

    //VERIFICAR si las dimensiones exceden los límites establecidos
    if (*ancho > MAX_ANCHO || *alto > MAX_ALTO) {
        printf("Error: La imagen excede los limites permitidos (%dx%d).\n", MAX_ANCHO, MAX_ALTO);
        fclose(archivo);
        return;
    }//if

    //CALCULAR el padding = bytes por fila (cada línea debe ser múltiplo de 4 bytes)
    bytes_por_linea = (*ancho) * 3;
    padding = (4 - (bytes_por_linea % 4)) % 4;

    //LEER los datos de la imagen
    for (i = *alto - 1; i >= 0; i--) {
        for (j = 0; j < *ancho; j++) {
            //EN BMP el orden es BGR
            fread(&matriz[i][j][2], 1, 1, archivo);//Azul.
            fread(&matriz[i][j][1], 1, 1, archivo);//Verde.
            fread(&matriz[i][j][0], 1, 1, archivo);//Rojo.
        }//for
        //SALTAR el padding al final de cada línea
        fseek(archivo, padding, SEEK_CUR);
    }//for

    fclose(archivo);
}//void leer_imagen_bmp

//ESCRIBIR IMAGEN BMP
void escribir_imagen_bmp(char *nombre_archivo, unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], int alto, int ancho) {
    FILE *archivo = fopen(nombre_archivo, "wb");
    //DECLARAR variables
    unsigned char cabecera_bmp[54];
    int bytes_por_linea, padding, tamano_archivo, i, j;
    unsigned char byte_padding = 0;

    //MENSAJE de error
    if (archivo == NULL) {
        printf("Error al crear el archivo %s\n", nombre_archivo);
        return;
    }//if

    //CALCULAR padding y tamaño del archivo
    bytes_por_linea = ancho * 3;
    padding = (4 - (bytes_por_linea % 4)) % 4;
    tamano_archivo = 54 + (bytes_por_linea + padding) * alto;

    //PREPARAR cabecera BMP
    memset(cabecera_bmp, 0, 54);/*memset = inicializa los primeros n bytes de la zona de memoria apuntada por s con el valor de c.*/
    cabecera_bmp[0] = 'B';
    cabecera_bmp[1] = 'M';
    *(int*)&cabecera_bmp[2] = tamano_archivo;
    *(int*)&cabecera_bmp[10] = 54;
    *(int*)&cabecera_bmp[14] = 40;
    *(int*)&cabecera_bmp[18] = ancho;
    *(int*)&cabecera_bmp[22] = alto;
    *(short*)&cabecera_bmp[26] = 1;
    *(short*)&cabecera_bmp[28] = 24;
    *(int*)&cabecera_bmp[34] = (bytes_por_linea + padding) * alto;

    //ESCRIBIR cabecera
    fwrite(cabecera_bmp, sizeof(unsigned char), 54, archivo);

    //ESCRIBIR datos de la imagen
    for (i = alto - 1; i >= 0; i--) {
        for (j = 0; j < ancho; j++) {
            //ESCRIBIR en orden BGR
            fwrite(&matriz[i][j][2], 1, 1, archivo);//Azul
            fwrite(&matriz[i][j][1], 1, 1, archivo);//Verde
            fwrite(&matriz[i][j][0], 1, 1, archivo);//Rojo
        }//for
        //ESCRIBIR padding
        for (j = 0; j < padding; j++) {
            fwrite(&byte_padding, 1, 1, archivo);
        }//for
    }//for

    fclose(archivo);
}//void escribir_imagen_bmp

//SEPARAR CANAL ROJO
void separar_canal_rojo_bmp(unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], unsigned char rojo[MAX_ALTO][MAX_ANCHO][3], int alto, int ancho) {
    int i, j;
    for (i = 0; i < alto; i++) {
        for (j = 0; j < ancho; j++) {
            rojo[i][j][0] = matriz[i][j][0];//Canal rojo se mantiene.
            rojo[i][j][1] = 0;              //Verde a cero.
            rojo[i][j][2] = 0;              //Azul a cero.
        }//for
    }//for
}//void separar_canal_rojo

//SEPARAR CANAL VERDE
void separar_canal_verde_bmp(unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], unsigned char verde[MAX_ALTO][MAX_ANCHO][3], int alto, int ancho) {
    int i, j;
    for (i = 0; i < alto; i++) {
        for (j = 0; j < ancho; j++) {
            verde[i][j][0] = 0;              //Rojo a cero.
            verde[i][j][1] = matriz[i][j][1];//Canal verde se mantiene.
            verde[i][j][2] = 0;              //Azul a cero.
        }//for
    }//for
}//void separar_canal_verde 

//SEPARAR CANAL AZUL
void separar_canal_azul_bmp(unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], unsigned char azul[MAX_ALTO][MAX_ANCHO][3], int alto, int ancho) {
    int i, j;
    for (i = 0; i < alto; i++) {
        for (j = 0; j < ancho; j++) {
            azul[i][j][0] = 0;              //Rojo a cero
            azul[i][j][1] = 0;              //Verde a cero
            azul[i][j][2] = matriz[i][j][2];//Canal azul se mantiene
        }//for
    }//for
}//void separar_canal_azul_bmp

//FUNCIONES PARA LEER Y SEPARAR LOS CANALES RGB PNM (esto se vio en una clase de la materia)

//LEER IMAGEN PNM
void leer_imagen_pnm(char *nombre_archivo, unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], int *alto, int *ancho) {
    FILE *archivo = fopen(nombre_archivo, "rb");
    //DECLARAR variables
    char linea[100];
    int max_valor;
    int i, j;

    //MENSAJE de error
    if (archivo == NULL) {
        printf("Error al abrir el archivo %s\n", nombre_archivo);
        return;
    }//if

    //LEER el identificador del formato (P6)
    fgets(linea, sizeof(linea), archivo);
    if (linea[0] != 'P' || linea[1] != '6') {
        printf("Formato de archivo incorrecto\n");
        fclose(archivo);
        return;
    }//if

    //SALTAR comentarios si existen
    do {
        fgets(linea, sizeof(linea), archivo);
    } while (linea[0] == '#');

    //LEER dimensiones
    sscanf(linea, "%d %d", ancho, alto);

    //LEER valor máximo
    fgets(linea, sizeof(linea), archivo);
    sscanf(linea, "%d", &max_valor);

    //LEER datos de la imagen
    for (i = 0; i < *alto; i++) {
        for (j = 0; j < *ancho; j++) {
            fread(&matriz[i][j][0], 1, 1, archivo);//Rojo
            fread(&matriz[i][j][1], 1, 1, archivo);//Verde
            fread(&matriz[i][j][2], 1, 1, archivo);//Azul
        }//for
    }//for

    fclose(archivo);
}//void leer_imagen_pnm

//ESCRIBIR IMAGEN PNM   
void escribir_imagen_pnm(char *nombre_archivo, unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], int alto, int ancho) {
    FILE *archivo = fopen(nombre_archivo, "wb");
    //DECLARAR variables
    int i, j;

    //MENSAJE de error
    if (archivo == NULL) {
        printf("Error al crear el archivo %s\n", nombre_archivo);
        return;
    }//if

    //ESCRIBIR cabecera
    fprintf(archivo, "P6\n");                //Identificador del formato
    fprintf(archivo, "%d %d\n", ancho, alto);//Dimensiones
    fprintf(archivo, "255\n");               //Valor máximo

    //ESCRIBIR datos de la imagen
    for (i = 0; i < alto; i++) {
        for (j = 0; j < ancho; j++) {
            fwrite(&matriz[i][j][0], 1, 1, archivo); // Rojo
            fwrite(&matriz[i][j][1], 1, 1, archivo); // Verde
            fwrite(&matriz[i][j][2], 1, 1, archivo); // Azul
        }//for
    }//for

    fclose(archivo);
}//void escribir_imagen_pnm

//SEPARAR CANAL ROJO
void separar_canal_rojo_pnm(unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], unsigned char rojo[MAX_ALTO][MAX_ANCHO][3], int alto, int ancho) {
    int i, j;
    for (i = 0; i < alto; i++) {
        for (j = 0; j < ancho; j++) {
            rojo[i][j][0] = matriz[i][j][0];//Mantener canal rojo
            rojo[i][j][1] = 0;              //Verde a cero
            rojo[i][j][2] = 0;              //Azul a cero
        }//for
    }//for
}//void separar_canal_rojo_pnm

//SEPARAR CANAL VERDE
void separar_canal_verde_pnm(unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], unsigned char verde[MAX_ALTO][MAX_ANCHO][3], int alto, int ancho) {
    int i, j;
    for (i = 0; i < alto; i++) {
        for (j = 0; j < ancho; j++) {
            verde[i][j][0] = 0;              //Rojo a cero
            verde[i][j][1] = matriz[i][j][1];//Mantener canal verde
            verde[i][j][2] = 0;              //Azul a cero
        }//for
    }//for
}//void separar_canal_verde_pnm

//SEPARAR CANAL AZUL
void separar_canal_azul_pnm(unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], unsigned char azul[MAX_ALTO][MAX_ANCHO][3], int alto, int ancho) {
    int i, j;
    for (i = 0; i < alto; i++) {
        for (j = 0; j < ancho; j++) {
            azul[i][j][0] = 0;              //Rojo a cero
            azul[i][j][1] = 0;              // Verde a cero
            azul[i][j][2] = matriz[i][j][2];//Mantener canal azul
        }//for
    }//for
}//void separar_canal_azul_pnm

//CONVERTIR A GRIS
void convertir_a_grises(unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], unsigned char grises[MAX_ALTO][MAX_ANCHO][3], int alto, int ancho) {
    //DECLARAR variables
    int i, j;
    unsigned char valor_gris;
    
    for (i = 0; i < alto; i++) {
        for (j = 0; j < ancho; j++) {
            //CALCULAR valor de gris usando los pesos estándar
            valor_gris = (unsigned char)(
                (matriz[i][j][0] * 0.299) + //Rojo
                (matriz[i][j][1] * 0.587) + //Verde
                (matriz[i][j][2] * 0.114)   //Azul
            );//Sumar los valores de los canales, para mayor comprensión se usaron distintos renglones.
            
            //ASIGNAR el mismo valor a los tres canales para mantener la imagen en color
            grises[i][j][0] = valor_gris;
            grises[i][j][1] = valor_gris;
            grises[i][j][2] = valor_gris;
        }//for
    }//for
}//void convertir_a_grises

//CONVERTIR A BLANCO Y NEGRO
void convertir_a_bn(unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], unsigned char bn[MAX_ALTO][MAX_ANCHO][3], int alto, int ancho, int umbral) {
    //DECLARAR variables
    int i, j;
    unsigned char valor_gris;
    
    //VERIFICAR que el umbral esté en el rango válido
    if (umbral < 0) {
        umbral = 0;
    }//if
    if (umbral > 255) {
        umbral = 255;
    }//if
    
    for (i = 0; i < alto; i++) {
        for (j = 0; j < ancho; j++) {
            //PRIMERO convertir a escala de grises
            valor_gris = (unsigned char)(
                (matriz[i][j][0] * 0.299) +
                (matriz[i][j][1] * 0.587) +
                (matriz[i][j][2] * 0.114)
            );
            
            //APLICAR el umbral
            if (valor_gris >= umbral) {
                bn[i][j][0] = 255;//Blanco
                bn[i][j][1] = 255;
                bn[i][j][2] = 255;
            } else {
                bn[i][j][0] = 0;  //Negro
                bn[i][j][1] = 0;
                bn[i][j][2] = 0;
            }//else
        }//for
    }//for
}//void convertir_a_bn

//FUNCIONES PARA CALCULAR Y ESCRIBIR HISTOGRAMAS

//CALCULAR HISTOGRAMA DE IMÁGENES EN COLOR
void calcular_histograma_color(unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], int alto, int ancho, int histR[256], int histG[256], int histB[256]) {
    //DECLARAR variables
    int i, j;
    
    //INICIALIZAR contadores a cero
    for (i = 0; i < 256; i++) {
        histR[i] = 0;
        histG[i] = 0;
        histB[i] = 0;
    }//for
    
    //CONTAR ocurrencias
    for (i = 0; i < alto; i++) {
        for (j = 0; j < ancho; j++) {
            histR[matriz[i][j][0]]++;
            histG[matriz[i][j][1]]++;
            histB[matriz[i][j][2]]++;
        }
    }//for
}//void calcular_histograma_color

//CALCULAR HISTOGRAMA DE IMÁGENES EN ESCALA DE GRIS
void calcular_histograma_grises(unsigned char matriz[MAX_ALTO][MAX_ANCHO][3], int alto, int ancho, int hist[256]) {
    //DECLARAR variables
    int i, j;
    unsigned char valor_gris;
    
    //INICIALIZAR contadores
    for (i = 0; i < 256; i++) {
        hist[i] = 0;
    }
    
    //CONTAR ocurrencias
    for (i = 0; i < alto; i++) {
        for (j = 0; j < ancho; j++) {
            valor_gris = (unsigned char)(
                (matriz[i][j][0] * 0.299) +
                (matriz[i][j][1] * 0.587) +
                (matriz[i][j][2] * 0.114)
            );
            hist[valor_gris]++;
        }//for
    }//for
}//void calcular_histograma_grises

//ESCRIBIR HISTOGRAMA
void escribir_histograma(const char *nombre_archivo, int histograma[256]) {
    FILE *archivo = fopen(nombre_archivo, "w");
    //DECLARAR variables
    int i, j;

    //MENSAJE de error
    if (archivo == NULL) {
        printf("Error al crear archivo %s\n", nombre_archivo);
        return;
    }
    
    fprintf(archivo, "Tono\tValor\tHistograma\n");/*\t = tabulador*/
    
    for (i = 0; i < 256; i++) {
        if (histograma[i] > 0) {//Solo escribir valores que aparecen
            fprintf(archivo, "%d\t%d\t", i, histograma[i]);
            //ESCRIBIR asteriscos
            for (j = 0; j < histograma[i] / 100; j++) { //ESCALAR para mejor visualización
                fprintf(archivo, "*");
            }
            fprintf(archivo, "\n");
        }//if
    }//for
    
    fclose(archivo);
}//void escribir_histograma

//FUNCIONES PARA MEZCLAR IMÁGENES

void mezclar_imagenes(unsigned char frente[MAX_ALTO][MAX_ANCHO][3], unsigned char fondo[MAX_ALTO][MAX_ANCHO][3], unsigned char mezcla[MAX_ALTO][MAX_ANCHO][3],int alto, int ancho, int alpha) {
    //DECLARAR variables
    int i, j, k;
    int valor_mezcla;
    
    //VERIFICAR que alpha esté en el rango válido
    if (alpha < 0) {
        alpha = 0;
    }//if
    if (alpha > 255) {
        alpha = 255;
    }//if
    
    for (i = 0; i < alto; i++) {
        for (j = 0; j < ancho; j++) {
            for (k = 0; k < 3; k++) {//Para cada canal RGB
                //APLICAR la fórmula: MEZCLAi = (FRENTEi × alpha) ÷ 256 + (FONDOi × (255 − alpha)) ÷ 256
                valor_mezcla = ((frente[i][j][k] * alpha) + (fondo[i][j][k] * (255 - alpha))) / 256;
                
                // Asegurar que el valor esté en el rango 0-255
                if (valor_mezcla > 255) {
                    valor_mezcla = 255;
                }//if
                if (valor_mezcla < 0) {
                    valor_mezcla = 0;
                }//if
                
                mezcla[i][j][k] = (unsigned char)valor_mezcla;
            }//for
        }//for
    }//for
}//void mezclar_imagenes
