/*
    BFS Y DFS sobre el grafo A-E.

      A --- B
      |     |
      C --- D --- E

    BFS = cola  -> visita por NIVELES  (ancho)
    DFS = pila  -> baja por una RAMA hasta el fondo (profundidad)

    OJO: aqui NO hay pesos. BFS/DFS solo necesitan saber a quien es
    vecino cada uno. Los pesos son para Dijkstra, Prim y Kruskal.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int V = 5;                  // vertices A..E = 0..4
vector<int> ady[V];               // ady[v] = vecinos de v

void agregarArista(int a, int b) {
    ady[a].push_back(b);
    ady[b].push_back(a);         // sin esta linea el grafo es dirigido
}

char nombre(int v) { return 'A' + v; }

// ---------- BFS: anchura, usa cola ----------
void bfs(int inicio) {
    vector<bool> visitado(V, false);   // todos empiezan en false
    queue<int> cola;

    visitado[inicio] = true;           // se marca ANTES de encolar
    cola.push(inicio);

    while (!cola.empty()) {
        int u = cola.front();
        cola.pop();
        cout << nombre(u) << " ";

        for (int v : ady[u]) {
            if (!visitado[v]) {        // el filtro que corta el ciclo
                visitado[v] = true;    // se marca al ENCOLAR, no al sacar
                cola.push(v);
            }
        }
    }
    cout << endl;
}

// ---------- DFS: profundidad, usa pila ----------
void dfsPila(int inicio) {
    vector<bool> visitado(V, false);
    stack<int> pila;
    pila.push(inicio);

    while (!pila.empty()) {
        int u = pila.top();
        pila.pop();
        if (visitado[u]) continue;     // ya lo vi: lo tiro, estaba duplicado
        cout << nombre(u) << " ";
        visitado[u] = true;

        for (int v : ady[u])
            pila.push(v);              // aqui NO se filtra: se llena de repetidos
    }
    cout << endl;
}

// ---------- DFS recursivo: la pila la pone la maquina sola ----------
void dfsRec(int u, vector<bool>& visitado) {
    if (visitado[u]) return;
    cout << nombre(u) << " ";
    visitado[u] = true;
    for (int v : ady[u]) dfsRec(v, visitado);
}

void mostrarGrafo() {
    for (int v = 0; v < V; v++) {
        cout << "  " << nombre(v) << ": ";
        for (int w : ady[v]) cout << nombre(w) << " ";
        cout << endl;
    }
}

int main() {
    agregarArista(0, 1);   // A-B
    agregarArista(0, 2);   // A-C
    agregarArista(1, 3);   // B-D
    agregarArista(2, 3);   // C-D
    agregarArista(3, 4);   // D-E

    cout << "Grafo:" << endl;
    mostrarGrafo();

    cout << "\nBFS desde A:  ";  bfs(0);
    cout << "DFS desde A:  ";  dfsPila(0);
    cout << "DFS recursivo: ";
    vector<bool> vis(V, false);
    dfsRec(0, vis);

    // --- con ciclo: A-E cierra el anillo ---
    cout << "\n--- Agrego la arista E-A (crea un ciclo) ---" << endl;
    ady[4].push_back(0);
    ady[0].push_back(4);

    cout << "BFS desde A:  ";  bfs(0);
    cout << "DFS desde A:  ";  dfsPila(0);

    return 0;
}
