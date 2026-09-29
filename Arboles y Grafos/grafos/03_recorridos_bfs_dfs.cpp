/*
=====================================================================
  03 - RECORRIDOS DE GRAFOS: BFS y DFS
---------------------------------------------------------------------
  BFS (en anchura): visita por "capas". Primero los vecinos,
       luego los vecinos de los vecinos... Usa una COLA.
       Sirve para el camino mas corto (en numero de aristas).

  DFS (en profundidad): se va lo mas lejos posible por un
       camino y cuando no puede mas, se devuelve.
       VERSION 1: recursiva
       VERSION 2: con una PILA (sin recursion)

  IMPORTANTE: como un grafo puede tener ciclos, hay que llevar
  un arreglo "visitado" para no pasar dos veces por el mismo
  vertice (y no quedar en un bucle infinito).

  Grafo del ejemplo:

      A --- B          F --- G
      |     |
      C --- D --- E

  (F y G estan separados: son otro "componente")

  Compilar:  g++ 03_recorridos_bfs_dfs.cpp -o recorridos
=====================================================================
*/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int MAX = 10;

vector<int> vecinos[MAX];
int numVertices = 7;
bool visitado[MAX];

char nombre(int v) {
    return 'A' + v;
}

void agregarArista(int a, int b) {
    vecinos[a].push_back(b);
    vecinos[b].push_back(a);
}

void limpiarVisitados() {
    for (int i = 0; i < numVertices; i++) visitado[i] = false;
}

// ------------------------------------------------------------
//  BFS - recorrido en anchura
//  Ademas calcula la distancia (en aristas) desde el inicio
//  y el camino mas corto hasta cada vertice.
// ------------------------------------------------------------
void bfs(int inicio) {
    int distancia[MAX];
    int anterior[MAX];                  // de donde vine (para armar el camino)
    for (int i = 0; i < numVertices; i++) {
        distancia[i] = -1;              // -1 = no se alcanza
        anterior[i] = -1;
    }

    queue<int> cola;
    cola.push(inicio);
    distancia[inicio] = 0;

    cout << "BFS desde " << nombre(inicio) << ": ";

    while (!cola.empty()) {
        int actual = cola.front();
        cola.pop();
        cout << nombre(actual) << " ";

        for (int i = 0; i < (int)vecinos[actual].size(); i++) {
            int vecino = vecinos[actual][i];
            if (distancia[vecino] == -1) {             // no visitado
                distancia[vecino] = distancia[actual] + 1;
                anterior[vecino] = actual;
                cola.push(vecino);
            }
        }
    }
    cout << endl;

    cout << "Distancias: ";
    for (int i = 0; i < numVertices; i++)
        cout << nombre(i) << "=" << distancia[i] << " ";
    cout << endl;

    // Camino mas corto hasta E (se arma al reves y se imprime al derecho)
    int destino = 4;
    int camino[MAX];
    int largo = 0;
    for (int v = destino; v != -1; v = anterior[v]) {
        camino[largo] = v;
        largo++;
    }
    cout << "Camino mas corto de " << nombre(inicio) << " a " << nombre(destino) << ": ";
    for (int i = largo - 1; i >= 0; i--) cout << nombre(camino[i]) << " ";
    cout << endl;
}

// ------------------------------------------------------------
//  DFS - VERSION 1: recursiva
// ------------------------------------------------------------
void dfsRecursivo(int actual) {
    visitado[actual] = true;
    cout << nombre(actual) << " ";

    for (int i = 0; i < (int)vecinos[actual].size(); i++) {
        int vecino = vecinos[actual][i];
        if (!visitado[vecino])
            dfsRecursivo(vecino);
    }
}

// ------------------------------------------------------------
//  DFS - VERSION 2: con pila
//  Los vecinos se meten AL REVES para que salgan en el mismo
//  orden que en la version recursiva.
// ------------------------------------------------------------
void dfsConPila(int inicio) {
    stack<int> pila;
    pila.push(inicio);

    while (!pila.empty()) {
        int actual = pila.top();
        pila.pop();

        if (visitado[actual]) continue;     // ya habia pasado por aqui

        visitado[actual] = true;
        cout << nombre(actual) << " ";

        for (int i = (int)vecinos[actual].size() - 1; i >= 0; i--) {
            int vecino = vecinos[actual][i];
            if (!visitado[vecino]) pila.push(vecino);
        }
    }
}

// ------------------------------------------------------------
//  Uso practico del DFS: contar componentes conexos
//  (cuantos "pedazos" separados tiene el grafo)
// ------------------------------------------------------------
int contarComponentes() {
    limpiarVisitados();
    int componentes = 0;

    for (int v = 0; v < numVertices; v++) {
        if (!visitado[v]) {
            componentes++;
            cout << "  Componente " << componentes << ": ";
            dfsRecursivo(v);                // marca todo su pedazo
            cout << endl;
        }
    }
    return componentes;
}

// ------------------------------------------------------------
int main() {
    agregarArista(0, 1);   // A - B
    agregarArista(0, 2);   // A - C
    agregarArista(1, 3);   // B - D
    agregarArista(2, 3);   // C - D
    agregarArista(3, 4);   // D - E
    agregarArista(5, 6);   // F - G

    bfs(0);
    cout << endl;

    limpiarVisitados();
    cout << "DFS recursivo desde A: ";
    dfsRecursivo(0);
    cout << endl;

    limpiarVisitados();
    cout << "DFS con pila desde A:  ";
    dfsConPila(0);
    cout << endl << endl;

    cout << "Componentes conexos:" << endl;
    int total = contarComponentes();
    cout << "Total: " << total << endl;

    return 0;
}
