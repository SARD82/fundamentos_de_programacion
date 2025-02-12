// Proyecto_final
//Alumno: Durán Rendón Santiago, Noriega Chiu Santiago, Ramírez Reyes Jesús. 
//19-11-24

//Los comentarios de una línea se usaran para la documentación del programa.
/*Los comentarios de multiple línea seran para explicar información que desconocia.*/

/*No se usaran acentos dentro de lo que se imprimira en la terminal ya que luego da caracteres extraños.*/

//BIBLIOTECAS A USAR 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//DEFINIR máximo para alto y ancho de la imagen
#define MAX_ANCHO 1920// Define un límite máximo para el ancho de la imagen
#define MAX_ALTO 1080// Define un límite máximo para el alto de la imagen

//Matrices estáticas para almacenar los canales
unsigned char canal_R[MAX_ALTO][MAX_ANCHO];
unsigned char canal_G[MAX_ALTO][MAX_ANCHO];
unsigned char canal_B[MAX_ALTO][MAX_ANCHO];

/*prototipos = Si los prototipos no estuvieran presentes y las funciones estuvieran definidas después del main, el compilador generaría un error o advertencia de que las funciones no están definidas en el momento en que son llamadas.*/
//PROTOTIPOS
void mostrar_ayuda();
void leer_cabecera_bmp(const char *nombreArchivo);
void leer_cabecera_pnm(const char *nombreArchivo);
void separar_canales_bmp(const char *nombreArchivo, int *ancho, int *alto);
void mostrar_matriz(unsigned char matriz[MAX_ALTO][MAX_ANCHO], int ancho, int alto);
void escribir_canal(const char *nombre_archivo, unsigned char canal[MAX_ALTO][MAX_ANCHO], int ancho, int alto);

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
    if (argc < 2){
        printf("Error: No se proporcionaron argumentos necesarios.\n");
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
    if (strcmp(argv[1], "1b") == 0){
        leer_cabecera_bmp(argv[2]);
    }else if (strcmp(argv[1], "1p") == 0){
        leer_cabecera_pnm(argv[2]);
    }//else if

    //VERIFICAR comandos para lectura de separación de canales
    if (strcmp(argv[1], "1b") == 0 || strcmp(argv[1], "2b") == 0 || strcmp(argv[1], "3b") == 0 || strcmp(argv[1], "4b") == 0) {
        int ancho = 0, alto = 0;

        //SEPARAR canales RGB para BMP
        separar_canales_bmp(argv[2], &ancho, &alto);

        // Mostrar matrices según el comando
        if (strcmp(argv[1], "1b") == 0) {
            // Escribir cada canal en un archivo
            escribir_canal("canal_R.bmp", canal_R, ancho, alto);
            escribir_canal("canal_G.bmp", canal_G, ancho, alto);
            escribir_canal("canal_B.bmp", canal_B, ancho, alto);
           /* printf("Canal R:\n");
            mostrar_matriz(canal_R, ancho, alto);
            printf("Canal G:\n");
            mostrar_matriz(canal_G, ancho, alto);
            printf("Canal B:\n");
            mostrar_matriz(canal_B, ancho, alto);*/
        } else if (strcmp(argv[1], "2b") == 0) {
            printf("Matriz R:\n");
            mostrar_matriz(canal_R, ancho, alto);
        } else if (strcmp(argv[1], "3b") == 0) {
            printf("Matriz G:\n");
            mostrar_matriz(canal_G, ancho, alto);
        } else if (strcmp(argv[1], "4b") == 0) {
            printf("Matriz B:\n");
            mostrar_matriz(canal_B, ancho, alto);
        }//else if
    } else{
        //SI NO se conoce el argumento, mostrar error.
        printf("Error: Comando no reconocido.\n");
        printf("Use el comando -help para obtener mas informacion.\n");
        return 1;
    }//else

    return 0;
}//int main
    
//FUNCIÓN PARA MOSTRAR LA AYUDA DEL PROGRAMA (-help)
void mostrar_ayuda(){
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
    printf("programa 1p imagen.pnm\n");
    printf("programa 5b imagen.bmp\n");
    printf("programa 9b 127 100 imagen1.pnm imagen2.bmp\n");
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
    printf("Informacion de la cabecera pnm:\n");
    printf("Numero magico: %s.\n", numero_magico);
    printf("Dimensiones: %dx%d pixeles.\n", ancho, alto);
    printf("Valor maximo: %d.\n", maxval);
    printf("\n---------------------------------------------------------------\n");

    fclose(archivo);
}//leer_cabecera_pnm

//FUNCIÓN PARA LEER Y SEPARAR LOS CANALES RGB BMP (esto se vio en una clase de la materia)

/*Todos los ficheros abiertos tienen un indicador para saber por dónde se va en su lectura o escritura. Es el puntero de acceso al fichero. El tipo de este puntero es off_t, pero en realidad en un número entero. Este número indica cuál es la próxima posición del fichero que se va a leer o escribir. La primera posición del fichero tiene el valor 0, la última posición del fichero tiene un valor igual al tamaño del fichero. Para poder saber o modificar la posición actual de un fichero, se usa la llamada al sistema lseek, cuyo prototipo es:
off_t lseek(int fildes, off_t desplazamiento, int dOnde); 
Si queremos cambiar la posición del puntero de acceso, realizamos la llamada al sistema con el descriptor del fichero cuyo puntero queremos modificar. Para modificar el puntero se indica un desplazamiento (segundo parámetro) tanto positivo como negativo, con respecto a uno de tres puntos de referencia (tercer parámetro):

Tercer parámetro	Punto de referencia
SEEK_SET	        Comienzo del fichero
SEEK_CUR	        Punto actual
SEEK_END	        Fin del fichero*/

void separar_canales_bmp(const char *nombreArchivo, int *ancho, int *alto) {
    FILE *archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL) {/*si es null no se puede abrir osea se utiliza para indicar que un puntero no apunta a ningún objeto o función válidos*/
        perror("Error al abrir el archivo bmp");/*perror =  imprime un mensaje de error en la salida de error estándar (stderr): */
        exit(1);
    }//if

    //LEER cabecera BMP (ignorando valores irrelevantes)
    unsigned char cabeceraBMP[54];
    fread(cabeceraBMP, sizeof(unsigned char), 54, archivo);

    //OBTENER dimensiones de la imagen
    *ancho = *(int *)&cabeceraBMP[18];
    *alto = *(int *)&cabeceraBMP[22];

    //VERIFICAR si las dimensiones exceden los límites establecidos
    if (*ancho > MAX_ANCHO || *alto > MAX_ALTO) {
        printf("Error: La imagen excede los límites permitidos (%dx%d).\n", MAX_ANCHO, MAX_ALTO);
        fclose(archivo);
        exit(1);
    }//if

    //CALCULAR padding (los bytes adicionales por fila para alinear a múltiplos de 4)
    int padding = (*ancho * 3) % 4;
    if (padding != 0) {
        padding = 4 - padding;
    }//if

    //LEER los datos de píxeles
    for (int i = 0; i < *alto; i++) {
        for (int j = 0; j < *ancho; j++) {
            unsigned char colores[3];
            fread(colores, sizeof(unsigned char), 3, archivo);
            canal_B[*alto - i - 1][j] = colores[0]; // Canal B
            canal_G[*alto - i - 1][j] = colores[1]; // Canal G
            canal_R[*alto - i - 1][j] = colores[2]; // Canal R
        }//for
        // Ignorar bytes de padding
        fseek(archivo, padding, SEEK_CUR);
    }//for

    fclose(archivo);
}//void separar_canales_bmp

//FUNCIÓN PARA MOSTRAR UNA MATRIZ
void mostrar_matriz(unsigned char matriz[MAX_ALTO][MAX_ANCHO], int ancho, int alto) {
    for (int i = 0; i < alto; i++) {
        for (int j = 0; j < ancho; j++) {
            printf("%3d ", matriz[i][j]);
        }//for
        printf("\n");
    }//for
}//void mostrar_matriz

void escribir_canal(const char *nombre_archivo, unsigned char canal[MAX_ALTO][MAX_ANCHO], int ancho, int alto) {
    FILE *archivo = fopen(nombre_archivo, "wb");
    if (!archivo) {
        perror("Error al abrir el archivo para escritura");
        return 1;
    }

    // Escribe el encabezado del archivo PGM
    fprintf(archivo, "P5\n%d %d\n255\n", ancho, alto);

    // Escribe los datos del canal en el archivo
    for (int y = 0; y < alto; y++) {
        fwrite(canal[y], sizeof(unsigned char), ancho, archivo);
    }

    fclose(archivo);
    printf("Archivo '%s' creado exitosamente.\n", nombre_archivo);
}