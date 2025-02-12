// Proyecto_final
//Alumno: Durán Rendón Santiago. 
//08-11-24

//Los comentarios de una línea se usaran para la documentación del programa.
/*Los comentarios de multiple línea seran para explicar información que desconocia*/

//Bibliotecas a usar.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> /*Para poder usar strcmp*/

//$programa 1p imagen.pnm -> para ejecutar el programa en la terminal

//Prototipos de las funciones /* Los prototipos son declaraciones de las funciones que le dicen al compilador qué funciones existen y cómo llamarlas (nombre, parámetros y tipo de retorno)*/
void leerCabeceraBMP(const char *archivo); /*const especifica que el valor de una variable es constante e indica al compilador que evite que el programador lo modifique.*/
void leerCabeceraPNM(const char *archivo);
void separarCanalesRGB(const char *archivo, const char *formato);
void convertirEscalaDeGrises(const char *archivo, const char *formato);
void convertirBlancoNegro(const char *archivo, const char *formato, int umbral);
void calcularHistograma(const char *archivo, const char *formato);
void mezclarImagenes(const char *archivoFrente, const char *archivoFondo, float alpha, const char *salidaPNM)

/*Cuando ejecutas un programa en C desde la terminal, puedes darle información adicional. 
Esta información se llama argumentos de línea de comandos, argc y argv son la manera en que el programa recibe esos datos.

-argc: Representa el número de argumentos que se le pasan al programa.

    Ejemplo: Si ejecutas ./programa 1 imagen.bmp, argc tendrá el valor 3 porque hay tres partes en el comando: ./programa, 1, y imagen.bmp.

-argv: Es un arreglo de cadenas de texto (o strings) donde cada posición almacena uno de los argumentos pasados.

    En el mismo ejemplo (./programa 1 imagen.bmp):
        argv[0] sería ./programa (el nombre del programa).
        argv[1] sería 1 (la opción).
        argv[2] sería imagen.bmp (el nombre del archivo de imagen).*/

//Por la explicación anterior es necesaria la biblioteca <stlib.h>

int main(int argc, char *argv[]){ //declaramos argc como entero para saber el número de argumentos y comparar posteriormente, tambien declaramos un apuntador tipo char de argv para saber que escribio el usuario en la terminal.

   //verificando si la entradad en la terminal es menor a lo necesario para ejecutar
   if (argc < 3){
        printf("Uso incorrecto: %s <comando> <archivo> [Parametros adicionales]\n", argv[0]); // %s para los strings
        printf("Usa '-help' para obtener una lista de los comandos disponibles.\n");
        return 1; /*return 1 significa que no se ejecuto el codigo como se esperaba*/

   }//if verificando si la entrada a la terminal es menor a lo necesario para ejecutar

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

    //variables para el procesamiebto de imagenes
    const char *archivo = argv[2]; 
    int umbral = 0;
    float alpha = 0.0;

    //Indicando el proceso que se va a realizar
    if (strcmp(argv[1], "1p") == 0 || strcmp(argv[1], "1b") == 0){
        printf("Procesando matrices R, G, B...\n");
    } else if (strcmp(argv[1], "2p") == 0 || strcmp(argv[1], "2b") == 0){
        printf("Procesando matriz R...\n");
    } else if (strcmp(argv[1], "3p") == 0 || strcmp(argv[1], "3b") == 0){
        printf("Procesando matriz G...\n");
    } else if (strcmp(argv[1], "4p") == 0 || strcmp(argv[1], "4b") == 0){
        printf("Procesando matriz B...\n");
    } else if (strcmp(argv[1], "5p") == 0 || strcmp(argv[1], "5b") == 0){
        printf("Procesando imagen en escala de grises...\n");
    } else if (strcmp(argv[1], "6p") == 0 || strcmp(argv[1], "6b") == 0){
        //verificando si la entrada a la terminal es menor a lo necesario para ejecutar con umbral
        if (argc < 4){
            printf("Error: Se requiere un valor de umbral para el comando 6p o 6b.\n");
            return 1;
        }//if verificando si la entrada a la terminal es menor a lo necesario para ejecutar con umbral
        umbral = atoi(argv[3]); /*atoi para char a int*/
        //verificando que el umbral este dentro del umbral definido
        if (umbral < 0 || umbral > 255){
            printf("Error: El umbral debe de estar entre 0 y 255.\n");
            return 1;
        }//if verificando que el umbral este dentro del umbral definido
        printf("Procesando imagen en blanco y negro con umbral %d...\n", umbral);
    } else if (strcmp(argv[1], "7p") == 0 || strcmp(argv[1], "7b") == 0){
        printf("Calculando histograma...\n");
    } else if (strcmp(argv[1], "8p") == 0 || strcmp(argv[1], "8b") == 0){
        //verificando si la entrada a la terminal es menor a lo necesario para ejecutar con alpha
        if (argc < 4){
            printf("Error: Se requiere un valor de alpha para el comando 8p o 8b.\n");
            return 1;
        }//if verificando si la entrada a la terminal es menor a lo necesario para ejecutar con alpha
        alpha = atof(argv[3]); /*atoi para char a float*/
        printf("Mezclando imagenes con alpha %f...\n", alpha);
    } else if (strcmp(argv[1], "9p") == 0 || strcmp(argv[1], "9b") == 0){
         //verificando si la entrada a la terminal es menor a lo necesario para ejecutar con umbral y alpha
        if (argc < 5){
            printf("Error: Se requiere valores de umbral y alpha para el comando 9p o 9b.\n");
            return 1;
        }//if verificando si la entrada a la terminal es menor a lo necesario para ejecutar con umbral y alpha
        umbral = atoi(argv[3]);
        alpha = atof(argv[4]);
         if (umbral < 0 || umbral > 255){
            printf("Error: El umbral debe de estar entre 0 y 255.\n");
            return 1;
        }//if verificando que el umbral este dentro del umbral definido
        printf("Ejecutando todos los procesos con umbral %d y alpha %f...\n", umbral, alpha);
    } else{
        printf("Comando no reconocido. Usa '-help' para ver los comandos disponibles.\n");
        return 1;
    }//if indicando el proceso que se va a realizar

    return 0;

}//int main

//Definiendo las funciones para las transformaciones de las imagenes
void leerCabeceraBMP(const char *archivo){
    FILE *f = open(archivo, "rb");
    if (!f){ //si es null(si no se puede abrir)
        printf("No se pudo abrir el archivoBMP\n");
        return 1;
    }//if

    unsigned char cabecera[64]; /*unsigned = sin signo. Arreglo de 54 ya que son los primeros 54 bytes*/
    fread(cabecera, sizeof(unsigned char), 54, f); //Asi se leen los primeros 54 bytes

    //Extraer la información de esos 54 bytes
    int ancho = *(int*)&cabecera[18]; //Obteniendo la dirección de memoria de esos bytes y pasandolos a enteros
    int alto = *(int*)&cabecera[22];
    int tamanoArchivo = *(int*)&cabecera[2];

    //Imprimiendo la información extraida
    printf("Tamano del archivo: %d bytes\n", tamanoArchivo);
    printf("Ancho de la imagen: %d bytes\n", ancho);
    printf("Alto de la imagen: %d bytes\n", alto);

    fclose(f)
}//leerCabeceraBMP

void leerCaabeceraPNM(const char *archivo){

    FILE *f = fopen(archivo, "r");
    if (!f){
        printf("No se pudo abrir el archivo PNM\n");
        return 1;
    }//if

    char tipo[3];
    int ancho, alto, maxcolor;

    //Leer el tipo de archivo (P1, P2, P3,P4, P5, P6)
    if (fsanf(f, "%2s", tipo) != 1){
        printf("Error al leer el archivo\n");
        fclose(f);
        return 1;
    }//if

    //Verificar que el formato sea valido
    if (strcmp(tipo, "P2") != 0 && strcmp(tipo, "P3") != 0){
        printf("Formato PNM no soportado: %s\n", tipo);
        fclose(f);
        return 1;
    }//if

    //Leer ancho, alto, valor maximo de color (P2 o P3) y saltar lineas de comentarios si las hay
    char c;
    while ((c = fgetc(f)) == "#"){ /*fgetc = get charachter, por tanto ve el caracter de la linea y si es un comentario avanza, los comentarios en PNM son con #*/
        while (fgetc(f) != "\n"); //Esto ignora toda la linea del comentario
    }//while

    ungetc(c, f);//Regresar el último carácter leído (no era '#')

    if (fscanf(f, "%d %d", &ancho, &alto) != 2){
        printf("Error al leer las dimensiones de la imagen\n");
        fclose(f);
        return 1;
    }//if

    if (fscanf(f, "%d", &maxcolor) != 1){
        printf("Error al leer el valor maximo del color\n");
        fclose(f);
        return 1;
    }//if

    //Imprimiendo la informcion sacada
    printf("Formato de la imagen: %s\n", tipo);
    printf("Ancho de la imagen: %d\n", ancho);
    printf("Alto de la imagen: %d\n", alto);
    printf("Valor maximo de color: %d\n", maxcolor);

    fclose(f);
}//leerCabeceraPNM

void separarCanalesRGB(const char *archivo, const char *formato){

}//separarCanalesRGB

void convertirEscalaDeGrises(const char *archivo, const char *formato){
    if (strcmp(formato, "bmp") == 0){
        FILE *f = fopen(archivo, "rb+");/*rb+ = r+b, lectura + escritura */
        if (!f){
            printf("No se pudo abrir el archivo BMP\n");
            return 1;
        }//if
    }//if

    unsigned char cabecera[54];
    fread(cabecera, sizeof(unsigned char), 54, f);//Leer la cabecera BMP

    int ancho = *(int*)&cabecera[18];
    int altura = *(int*)&cabecera[22];
    int offset = *(int*)&cabecera[10];
    //Alinear cada fila en multiplos de 4 bytes
    int fila_multi = (ancho * 3 + 3) & (~3)/*~ redondea al siguiente multiplo de 3 que es 4*/

    unsigned char *datos = (unsigned char*)malloc(fila_multi * altura);/*mallo asigna */

}//convertirEscalaDeGrises

void convertirBlancoNegro(const char *archivo, const char *formato, int umbral){

}//convertirBlancoNegro

void calcularHistograma(const char *archivo, const char *formato){

}//calcularHistograma

void mezclarImagenes(const char *archivoFrente, const char *archivoFondo, float alpha, const char *salidaPNM){

}//mezclarImagenes