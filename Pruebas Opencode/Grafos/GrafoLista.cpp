/*
    GRAFO CON LISTA DE ADYACENCIA (con pesos) - version limpia.

    Cada vertice guarda una lista con SUS vecinos y el peso de cada arista.

      A --- B
      |     |
      C --- D --- E

    Se guarda asi:
      A: B(4) C(2)
      B: A(4) D(5)
      C: A(2) D(8)
      D: B(5) C(8) E(3)
      E: D(3)

    Ventaja:    solo gasta memoria en las aristas que existen (O(V+E)).
    Desventaja: para saber si i y j estan unidos hay que recorrer la lista
                de i. En un grafo con muchas aristas, la matriz gana.

    Esta es la version CON PESOS, que es la que necesitan Dijkstra, Prim
    y Kruskal. Todo lo demas se deduce de aqui.
*/

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10;

struct Arista {
    int destino;
    int peso;
};

vector<Arista> conexiones[MAX];   // conexiones[v] = vecinos de v con su peso
int numVertices = 5;

char nombre(int v) {
    return 'A' + v;
}

void agregarArista(int origen, int destino, int peso) {
    conexiones[origen].push_back({destino, peso});
    conexiones[destino].push_back({origen, peso});   // quitar si es dirigido
}

bool hayArista(int origen, int destino) {
    for (const Arista& a : conexiones[origen])
        if (a.destino == destino) return true;
    return false;
}

// El grado en un grafo NO dirigido es el tamano de la lista: cada
// arista toca al vertice una vez. En un dirigido seria la mitad.
int grado(int v) {
    return (int)conexiones[v].size();
}

int pesoDe(int origen, int destino) {
    for (const Arista& a : conexiones[origen])
        if (a.destino == destino) return a.peso;
    return -1;      // -1 = no hay arista (los pesos son >= 0)
}

void mostrarGrafo() {
    for (int v = 0; v < numVertices; v++) {
        cout << "  " << nombre(v) << ": ";
        for (const Arista& a : conexiones[v])
            cout << nombre(a.destino) << "(" << a.peso << ") ";
        cout << endl;
    }
}

void mostrarMatriz() {
    cout << "   ";
    for (int j = 0; j < numVertices; j++) cout << nombre(j) << "  ";
    cout << endl;

    for (int i = 0; i < numVertices; i++) {
        cout << " " << nombre(i) << " ";
        for (int j = 0; j < numVertices; j++) {
            int p = pesoDe(i, j);
            cout << (p == -1 ? " ." : to_string(p)) << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "=== Sin pesos: el grafo del profe ===" << endl;
    agregarArista(0, 1, 1);
    agregarArista(0, 2, 1);
    agregarArista(1, 3, 1);
    agregarArista(2, 3, 1);
    agregarArista(3, 4, 1);
    mostrarGrafo();

    cout << "\nGrado de D: " << grado(3) << endl;
    cout << "A y D unidos? " << (hayArista(0, 3) ? "SI" : "NO") << endl;

    cout << "\n=== Con pesos (km) ===" << endl;
    conexiones[0].clear(); conexiones[1].clear();
    conexiones[2].clear(); conexiones[3].clear();
    conexiones[4].clear();

    agregarArista(0, 1, 4);
    agregarArista(0, 2, 2);
    agregarArista(1, 3, 5);
    agregarArista(2, 3, 8);
    agregarArista(3, 4, 3);
    mostrarGrafo();

    cout << "\nLa misma info como matriz (reconstruida con pesoDe):" << endl;
    mostrarMatriz();

    return 0;
}
