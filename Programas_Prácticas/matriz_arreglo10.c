// matriz_arreglo10
//Brigada 01: Durán Rendón Santiago, Noriega Chiu Santiago, Ramírez Reyes José de Jesús
//30-10-24
/* Enunciado: Realizar un programa con funciones que, para una matriz de hasta 10 renglones por 10 columnas: 
Verifique si la matriz tiene el mismo número de renglones que de columnas, de ser así:
Calcule la suma de los elementos donde i= j de la matriz. 
En caso de no tener el mismo número de renglones que de columnas: 
Copiar la matriz de n renglones por m columnas a otra de m columnas por n renglones. 
La lectura de la matriz, la impresión de los resultados, y cada una de las operaciones realizadas a la matriz debe ser hecha en una función por separado.*/
/*Pseudocódigo: INICIO
  Declarar matriz[10][10] como matriz de Enteros
  Declarar suma[10] como arreglo inicializado en 0

  ESCRIBIR "Ingrese los elementos de la matriz 10x10:"

  PARA i desde 0 HASTA 9 HACER
    PARA j desde 0 HASTA 9 HACER
      ESCRIBIR "Elemento [i][j]:"
      LEER matriz[i][j]
    FIN PARA
  FIN PARA

  PARA i desde 0 HASTA 9 HACER
    PARA j desde 0 HASTA 9 HACER
      suma[i] = suma[i] + matriz[i][j]
    FIN PARA
  FIN PARA

  ESCRIBIR "Suma de cada renglón:"

  PARA i desde 0 HASTA 9 HACER
    ESCRIBIR "Suma del renglón ", i+1, ": ", suma[i]
  FIN PARA

FIN*/
/*Ejecución: Ingrese el numero de renglones y columnas de la matriz: 2
2

Ingrese los elementos de la matriz:
Elemento [0][0]: 1

Elemento [0][1]: 2

Elemento [1][0]: 3

Elemento [1][1]: 4

Suma de la diagonal principal: 5*/

#include <stdio.h>

void leerMatriz(int matriz[10][10], int n, int m) {
    printf("\nIngrese los elementos de la matriz:");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("\nElemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void sumaDiagonal(int matriz[10][10], int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += matriz[i][i];
    }
    printf("\nSuma de la diagonal principal: %d", suma);
}

void transponerMatriz(int matriz[10][10], int transpuesta[10][10], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            transpuesta[j][i] = matriz[i][j];
        }
    }
    printf("\nMatriz transpuesta:");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", transpuesta[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz[10][10], transpuesta[10][10], n, m;

    printf("\nIngrese el numero de renglones y columnas de la matriz: ");
    scanf("%d %d", &n, &m);

    leerMatriz(matriz, n, m);

    if (n == m) {
        sumaDiagonal(matriz, n);
    } else {
        transponerMatriz(matriz, transpuesta, n, m);
    }

    return 0;
}