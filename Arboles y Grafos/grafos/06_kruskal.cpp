/*
=====================================================================
  06 - KRUSKAL: ARBOL DE EXPANSION MINIMA
---------------------------------------------------------------------
  Mismo problema que Prim, otra idea:

   1. Ordenar TODAS las aristas de menor a mayor peso.
   2. Ir tomando las aristas en ese orden.
   3. Una arista se acepta solo si NO forma ciclo, es decir,
      si une dos vertices que todavia estan en grupos distintos.
   4. Parar cuando se tengan n-1 aristas.

  Para saber si dos vertices estan en el mismo grupo se usa
  "UNION-FIND": cada vertice apunta a un "jefe" de su grupo.
   - buscarJefe(v): sube hasta encontrar el jefe del grupo
   - unir(a, b):    el jefe de uno pasa a depender del otro

  Compilar:  g++ 06_kruskal.cpp -o kruskal
=====================================================================
*/
#include <iostream>
using namespace std;

const int MAX_V = 10;
const int MAX_A = 50;

struct Arista {
    int origen;
    int destino;
    int peso;
};

Arista aristas[MAX_A];
int numAristas = 0;
int numVertices = 6;

int jefe[MAX_V];

char nombre(int v) { return 'A' + v; }

void agregarArista(int a, int b, int p) {
    aristas[numAristas].origen = a;
    aristas[numAristas].destino = b;
    aristas[numAristas].peso = p;
    numAristas++;
}

// Ordenamiento por insercion (de menor a mayor peso)
void ordenarAristas() {
    for (int i = 1; i < numAristas; i++) {
        Arista actual = aristas[i];
        int j = i - 1;
        while (j >= 0 && aristas[j].peso > actual.peso) {
            aristas[j + 1] = aristas[j];
            j--;
        }
        aristas[j + 1] = actual;
    }
}

// ----- Union-Find -----
int buscarJefe(int v) {
    while (jefe[v] != v) v = jefe[v];     // subir hasta el jefe
    return v;
}

void unir(int a, int b) {
    int jefeA = buscarJefe(a);
    int jefeB = buscarJefe(b);
    jefe[jefeA] = jefeB;
}

void kruskal() {
    // Al principio cada vertice es su propio jefe (grupos separados)
    for (int i = 0; i < numVertices; i++) jefe[i] = i;

    ordenarAristas();

    int total = 0;
    int aceptadas = 0;

    cout << "Revisando aristas de menor a mayor:" << endl;
    for (int i = 0; i < numAristas && aceptadas < numVertices - 1; i++) {
        int a = aristas[i].origen;
        int b = aristas[i].destino;

        cout << "  " << nombre(a) << " - " << nombre(b)
             << " (" << aristas[i].peso << "): ";

        if (buscarJefe(a) != buscarJefe(b)) {     // grupos distintos -> no hay ciclo
            unir(a, b);
            total += aristas[i].peso;
            aceptadas++;
            cout << "SE ACEPTA" << endl;
        } else {
            cout << "se descarta (formaria ciclo)" << endl;
        }
    }

    cout << "Costo total: " << total << endl;
}

int main() {
    agregarArista(0, 1, 4);    // A-B
    agregarArista(0, 2, 2);    // A-C
    agregarArista(1, 2, 1);    // B-C
    agregarArista(1, 3, 5);    // B-D
    agregarArista(2, 3, 8);    // C-D
    agregarArista(2, 4, 10);   // C-E
    agregarArista(3, 4, 2);    // D-E
    agregarArista(3, 5, 6);    // D-F
    agregarArista(4, 5, 3);    // E-F

    kruskal();
    return 0;
}
