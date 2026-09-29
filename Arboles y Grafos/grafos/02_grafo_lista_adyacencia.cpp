/*
=====================================================================
  02 - GRAFO CON LISTA DE ADYACENCIA
---------------------------------------------------------------------
  Cada vertice guarda una lista con sus vecinos.

      A --- B
      |     |
      C --- D --- E

  Se guarda asi:
      A: B C
      B: A D
      C: A D
      D: B C E
      E: D

  Ventaja:    solo gasta espacio por las aristas que existen.
              Es la forma mas usada.
  Desventaja: para saber si i y j estan conectados hay que
              recorrer la lista de i.

  VERSION 1: sin pesos      (vector<int>)
  VERSION 2: con pesos      (struct Arista con destino y peso)

  Compilar:  g++ 02_grafo_lista_adyacencia.cpp -o lista
=====================================================================
*/
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10;

char nombre(int v) {
    return 'A' + v;
}

// ============ VERSION 1: SIN PESOS ============

vector<int> vecinos[MAX];     // vecinos[v] = lista de vecinos de v
int numVertices = 5;

void agregarArista(int origen, int destino) {
    vecinos[origen].push_back(destino);
    vecinos[destino].push_back(origen);     // quitar esta linea si es dirigido
}

bool hayArista(int origen, int destino) {
    for (int i = 0; i < (int)vecinos[origen].size(); i++)
        if (vecinos[origen][i] == destino) return true;
    return false;
}

void mostrarGrafo() {
    for (int v = 0; v < numVertices; v++) {
        cout << nombre(v) << ": ";
        for (int i = 0; i < (int)vecinos[v].size(); i++)
            cout << nombre(vecinos[v][i]) << " ";
        cout << endl;
    }
}

// ============ VERSION 2: CON PESOS ============

struct Arista {
    int destino;
    int peso;
};

vector<Arista> conexiones[MAX];

void agregarAristaConPeso(int origen, int destino, int peso) {
    Arista a1;
    a1.destino = destino;
    a1.peso = peso;
    conexiones[origen].push_back(a1);

    Arista a2;                              // quitar si es dirigido
    a2.destino = origen;
    a2.peso = peso;
    conexiones[destino].push_back(a2);
}

void mostrarGrafoConPesos() {
    for (int v = 0; v < numVertices; v++) {
        cout << nombre(v) << ": ";
        for (int i = 0; i < (int)conexiones[v].size(); i++)
            cout << nombre(conexiones[v][i].destino)
                 << "(" << conexiones[v][i].peso << ") ";
        cout << endl;
    }
}

// ------------------------------------------------------------
int main() {
    cout << "=== Sin pesos ===" << endl;
    agregarArista(0, 1);   // A - B
    agregarArista(0, 2);   // A - C
    agregarArista(1, 3);   // B - D
    agregarArista(2, 3);   // C - D
    agregarArista(3, 4);   // D - E
    mostrarGrafo();

    cout << "Grado de D: " << vecinos[3].size() << endl;
    cout << "A y D conectados? " << (hayArista(0, 3) ? "SI" : "NO") << endl;

    cout << endl << "=== Con pesos (por ejemplo, km) ===" << endl;
    agregarAristaConPeso(0, 1, 4);
    agregarAristaConPeso(0, 2, 2);
    agregarAristaConPeso(1, 3, 5);
    agregarAristaConPeso(2, 3, 8);
    agregarAristaConPeso(3, 4, 3);
    mostrarGrafoConPesos();

    return 0;
}
