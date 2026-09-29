/*
=====================================================================
  01 - GRAFO CON MATRIZ DE ADYACENCIA
---------------------------------------------------------------------
  Un grafo son VERTICES (nodos) unidos por ARISTAS.
  A diferencia de un arbol, puede tener ciclos y un nodo
  puede tener varios "padres".

  Matriz de adyacencia: una tabla de n x n
     matriz[i][j] = 1  -> hay arista de i a j
     matriz[i][j] = 0  -> no hay arista
  (En un grafo con PESOS se guarda el peso en vez de 1)

  Grafo del ejemplo (no dirigido):

      A --- B
      |     |
      C --- D --- E

  Ventaja:    saber si i y j estan conectados es inmediato.
  Desventaja: gasta n*n espacio aunque haya pocas aristas.

  Compilar:  g++ 01_grafo_matriz_adyacencia.cpp -o matriz
=====================================================================
*/
#include <iostream>
using namespace std;

const int MAX = 10;

int matriz[MAX][MAX];
int numVertices;

// Nombre de cada vertice: 0 -> 'A', 1 -> 'B', ...
char nombre(int v) {
    return 'A' + v;
}

void inicializar(int n) {
    numVertices = n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matriz[i][j] = 0;
}

// No dirigido: la arista va en los dos sentidos
void agregarArista(int origen, int destino) {
    matriz[origen][destino] = 1;
    matriz[destino][origen] = 1;
}

// Dirigido: la arista va solo de origen a destino
void agregarAristaDirigida(int origen, int destino) {
    matriz[origen][destino] = 1;
}

void eliminarArista(int origen, int destino) {
    matriz[origen][destino] = 0;
    matriz[destino][origen] = 0;
}

bool hayArista(int origen, int destino) {
    return matriz[origen][destino] != 0;
}

void mostrarMatriz() {
    cout << "   ";
    for (int j = 0; j < numVertices; j++) cout << nombre(j) << " ";
    cout << endl;

    for (int i = 0; i < numVertices; i++) {
        cout << nombre(i) << "  ";
        for (int j = 0; j < numVertices; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }
}

// Vecinos: recorrer la fila del vertice
void mostrarVecinos(int v) {
    cout << "Vecinos de " << nombre(v) << ": ";
    for (int j = 0; j < numVertices; j++)
        if (matriz[v][j] != 0) cout << nombre(j) << " ";
    cout << endl;
}

// Grado = cantidad de aristas que tocan al vertice
int grado(int v) {
    int total = 0;
    for (int j = 0; j < numVertices; j++)
        if (matriz[v][j] != 0) total++;
    return total;
}

// ------------------------------------------------------------
int main() {
    inicializar(5);          // A B C D E

    agregarArista(0, 1);     // A - B
    agregarArista(0, 2);     // A - C
    agregarArista(1, 3);     // B - D
    agregarArista(2, 3);     // C - D
    agregarArista(3, 4);     // D - E

    mostrarMatriz();
    cout << endl;

    for (int v = 0; v < numVertices; v++) {
        mostrarVecinos(v);
    }
    cout << endl;

    cout << "Grado de D: " << grado(3) << endl;
    cout << "A y D conectados? " << (hayArista(0, 3) ? "SI" : "NO") << endl;
    cout << "A y B conectados? " << (hayArista(0, 1) ? "SI" : "NO") << endl;

    return 0;
}
