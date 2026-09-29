/*
=====================================================================
  04 - DIJKSTRA: camino mas corto con PESOS  (version simple)
---------------------------------------------------------------------
  Encuentra la distancia minima desde un vertice origen a
  todos los demas. Los pesos NO pueden ser negativos.

  Idea:
   1. Todas las distancias empiezan en "infinito", la del origen en 0.
   2. Se escoge el vertice NO visitado con menor distancia.
   3. Se marca como visitado (su distancia ya es definitiva).
   4. Se revisan sus vecinos: si pasando por el se llega mas
      barato, se actualiza la distancia ("relajar").
   5. Repetir hasta visitar todos.

  VERSION 1 (este archivo): matriz + buscar el minimo con un for.
            Facil de entender. Tiempo O(n^2).
  VERSION 2: 04b_dijkstra_cola_prioridad.cpp (mas rapida)

  Grafo del ejemplo (no dirigido, 6 vertices A..F):
      A-B 4    A-C 2    B-C 1    B-D 5    C-D 8
      C-E 10   D-E 2    D-F 6    E-F 3
  Es el mismo grafo que usan Prim, Kruskal y Floyd.

  Compilar:  g++ 04_dijkstra.cpp -o dijkstra
=====================================================================
*/
#include <iostream>
using namespace std;

const int MAX = 10;
const int INF = 1000000000;     // "infinito"

int peso[MAX][MAX];     // 0 = no hay arista
int numVertices;

char nombre(int v) { return 'A' + v; }

void agregarArista(int a, int b, int p) {
    peso[a][b] = p;
    peso[b][a] = p;             // no dirigido
}

// Imprime el camino usando el arreglo "anterior" (recursivo)
void mostrarCamino(int anterior[], int v) {
    if (anterior[v] != -1) {
        mostrarCamino(anterior, anterior[v]);
        cout << " -> ";
    }
    cout << nombre(v);
}

void dijkstra(int origen) {
    int distancia[MAX];
    bool visitado[MAX];
    int anterior[MAX];

    // 1. Inicializar
    for (int i = 0; i < numVertices; i++) {
        distancia[i] = INF;
        visitado[i] = false;
        anterior[i] = -1;
    }
    distancia[origen] = 0;

    for (int paso = 0; paso < numVertices; paso++) {
        // 2. Buscar el no visitado con menor distancia
        int u = -1;
        for (int i = 0; i < numVertices; i++) {
            if (!visitado[i] && (u == -1 || distancia[i] < distancia[u]))
                u = i;
        }
        if (distancia[u] == INF) break;     // los que quedan no se alcanzan

        // 3. Marcarlo
        visitado[u] = true;

        // 4. Relajar sus vecinos
        for (int v = 0; v < numVertices; v++) {
            if (peso[u][v] != 0 && !visitado[v]) {
                int nuevaDistancia = distancia[u] + peso[u][v];
                if (nuevaDistancia < distancia[v]) {
                    distancia[v] = nuevaDistancia;
                    anterior[v] = u;
                }
            }
        }
    }

    // Resultados
    cout << "Distancias desde " << nombre(origen) << ":" << endl;
    for (int i = 0; i < numVertices; i++) {
        cout << "  " << nombre(i) << ": ";
        if (distancia[i] == INF) {
            cout << "no se puede llegar" << endl;
        } else {
            cout << distancia[i] << "   camino: ";
            mostrarCamino(anterior, i);
            cout << endl;
        }
    }
}

// ------------------------------------------------------------
int main() {
    numVertices = 6;    // A B C D E F
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

    dijkstra(0);
    return 0;
}
