/*
=====================================================================
  04b - DIJKSTRA con COLA DE PRIORIDAD  (version rapida)
---------------------------------------------------------------------
  Misma idea que 04_dijkstra.cpp, pero:
   - El grafo se guarda en LISTA de adyacencia.
   - En vez de buscar el minimo con un for, se usa una
     priority_queue (que por dentro es un HEAP, ver
     arboles/04_arbol_en_arreglo_y_heap.cpp).

  Tiempo: O((n + aristas) log n). Sirve para grafos grandes.

  Sobre la priority_queue:
   - Guarda pares (distancia, vertice).
   - Normalmente saca el MAYOR; con "greater" saca el MENOR.
   - Puede tener un vertice repetido con distancias viejas;
     por eso se revisa si la distancia sacada ya no sirve.

  Compilar:  g++ 04b_dijkstra_cola_prioridad.cpp -o dijkstra2
=====================================================================
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 10;
const int INF = 1000000000;

struct Arista {
    int destino;
    int peso;
};

vector<Arista> conexiones[MAX];
int numVertices = 6;

char nombre(int v) { return 'A' + v; }

void agregarArista(int a, int b, int p) {
    Arista ida;    ida.destino = b;    ida.peso = p;
    Arista vuelta; vuelta.destino = a; vuelta.peso = p;
    conexiones[a].push_back(ida);
    conexiones[b].push_back(vuelta);
}

void dijkstra(int origen) {
    int distancia[MAX];
    for (int i = 0; i < numVertices; i++) distancia[i] = INF;
    distancia[origen] = 0;

    // Cola de prioridad que saca el par con MENOR distancia
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > cola;
    cola.push(make_pair(0, origen));      // (distancia, vertice)

    while (!cola.empty()) {
        int d = cola.top().first;
        int u = cola.top().second;
        cola.pop();

        if (d > distancia[u]) continue;   // dato viejo, ya encontre algo mejor

        for (int i = 0; i < (int)conexiones[u].size(); i++) {
            int v = conexiones[u][i].destino;
            int p = conexiones[u][i].peso;

            if (distancia[u] + p < distancia[v]) {
                distancia[v] = distancia[u] + p;
                cola.push(make_pair(distancia[v], v));
            }
        }
    }

    cout << "Distancias desde " << nombre(origen) << ":" << endl;
    for (int i = 0; i < numVertices; i++) {
        cout << "  " << nombre(i) << ": ";
        if (distancia[i] == INF) cout << "no se puede llegar" << endl;
        else                     cout << distancia[i] << endl;
    }
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

    dijkstra(0);
    return 0;
}
