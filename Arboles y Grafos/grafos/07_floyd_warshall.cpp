/*
=====================================================================
  07 - FLOYD-WARSHALL: distancias minimas entre TODOS los pares
---------------------------------------------------------------------
  Dijkstra da las distancias desde UN origen.
  Floyd da la tabla completa: de cualquier vertice a cualquier otro.

  Idea (3 for anidados):
    Para cada vertice k (intermediario):
      Para cada par (i, j):
        si ir de i a j PASANDO por k es mas corto, actualizar:
          dist[i][j] = dist[i][k] + dist[k][j]

  Tiempo O(n^3). Muy corto de programar.
  A diferencia de Dijkstra, acepta pesos negativos
  (pero no ciclos negativos).

  Compilar:  g++ 07_floyd_warshall.cpp -o floyd
=====================================================================
*/
#include <iostream>
using namespace std;

const int MAX = 10;
const int INF = 1000000000;

int dist[MAX][MAX];
int numVertices = 6;

char nombre(int v) { return 'A' + v; }

void agregarArista(int a, int b, int p) {
    dist[a][b] = p;
    dist[b][a] = p;
}

void mostrarTabla() {
    cout << "   ";
    for (int j = 0; j < numVertices; j++) cout << "  " << nombre(j) << "  ";
    cout << endl;

    for (int i = 0; i < numVertices; i++) {
        cout << nombre(i) << "  ";
        for (int j = 0; j < numVertices; j++) {
            if (dist[i][j] == INF) cout << " INF ";
            else {
                if (dist[i][j] < 10) cout << " ";
                cout << " " << dist[i][j] << "  ";
            }
        }
        cout << endl;
    }
}

void floyd() {
    for (int k = 0; k < numVertices; k++)
        for (int i = 0; i < numVertices; i++)
            for (int j = 0; j < numVertices; j++)
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
}

int main() {
    // Al inicio: 0 en la diagonal, INF donde no hay arista
    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < numVertices; j++)
            dist[i][j] = (i == j) ? 0 : INF;

    agregarArista(0, 1, 4);    // A-B
    agregarArista(0, 2, 2);    // A-C
    agregarArista(1, 2, 1);    // B-C
    agregarArista(1, 3, 5);    // B-D
    agregarArista(2, 3, 8);    // C-D
    agregarArista(2, 4, 10);   // C-E
    agregarArista(3, 4, 2);    // D-E
    agregarArista(3, 5, 6);    // D-F
    agregarArista(4, 5, 3);    // E-F

    cout << "Tabla ANTES (solo aristas directas):" << endl;
    mostrarTabla();

    floyd();

    cout << endl << "Tabla DESPUES (distancias minimas):" << endl;
    mostrarTabla();
    return 0;
}
