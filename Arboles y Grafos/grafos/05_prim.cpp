/*
=====================================================================
  05 - PRIM: ARBOL DE EXPANSION MINIMA
---------------------------------------------------------------------
  Problema: conectar TODOS los vertices usando aristas cuya
  suma de pesos sea la menor posible (sin ciclos).
  Ejemplo real: tender cable/fibra entre sitios gastando lo minimo.

  El resultado es un ARBOL (n vertices, n-1 aristas).

  Idea de Prim (parecida a Dijkstra):
   1. Empezar en cualquier vertice.
   2. De todas las aristas que salen de lo que ya esta en el
      arbol hacia afuera, tomar la mas barata.
   3. Repetir hasta que todos esten dentro.

  costo[v]  = arista mas barata para meter v al arbol
  padre[v]  = desde que vertice se conecta

  La otra forma de hacerlo es Kruskal (06_kruskal.cpp).

  Compilar:  g++ 05_prim.cpp -o prim
=====================================================================
*/
#include <iostream>
using namespace std;

const int MAX = 10;
const int INF = 1000000000;

int peso[MAX][MAX];     // 0 = no hay arista
int numVertices;

char nombre(int v) { return 'A' + v; }

void agregarArista(int a, int b, int p) {
    peso[a][b] = p;
    peso[b][a] = p;
}

void prim() {
    int costo[MAX];
    int padre[MAX];
    bool enArbol[MAX];

    for (int i = 0; i < numVertices; i++) {
        costo[i] = INF;
        padre[i] = -1;
        enArbol[i] = false;
    }
    costo[0] = 0;       // empezamos por A

    for (int paso = 0; paso < numVertices; paso++) {
        // Escoger el vertice fuera del arbol mas barato de conectar
        int u = -1;
        for (int i = 0; i < numVertices; i++) {
            if (!enArbol[i] && (u == -1 || costo[i] < costo[u]))
                u = i;
        }
        if (costo[u] == INF) {
            cout << "El grafo no es conexo" << endl;
            return;
        }

        enArbol[u] = true;

        // Actualizar el costo de sus vecinos que aun estan afuera
        for (int v = 0; v < numVertices; v++) {
            if (peso[u][v] != 0 && !enArbol[v] && peso[u][v] < costo[v]) {
                costo[v] = peso[u][v];
                padre[v] = u;
            }
        }
    }

    // Mostrar resultado
    int total = 0;
    cout << "Aristas del arbol de expansion minima:" << endl;
    for (int v = 1; v < numVertices; v++) {
        cout << "  " << nombre(padre[v]) << " - " << nombre(v)
             << "  (peso " << peso[padre[v]][v] << ")" << endl;
        total += peso[padre[v]][v];
    }
    cout << "Costo total: " << total << endl;
}

int main() {
    numVertices = 6;
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            peso[i][j] = 0;

    agregarArista(0, 1, 4);    // A-B
    agregarArista(0, 2, 2);    // A-C
    agregarArista(1, 2, 1);    // B-C
    agregarArista(1, 3, 5);    // B-D
    agregarArista(2, 3, 8);    // C-D
    agregarArista(2, 4, 10);   // C-E
    agregarArista(3, 4, 2);    // D-E
    agregarArista(3, 5, 6);    // D-F
    agregarArista(4, 5, 3);    // E-F

    prim();
    return 0;
}
