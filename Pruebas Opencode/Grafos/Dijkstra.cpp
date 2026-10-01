/*
    DIJKSTRA - version limpia, con priority_queue.

    Camino MAS BARATO (suma de pesos) de UN origen a todos los demas.

    La idea: la cola de prioridad es un HEAP DE MINIMOS (por eso el
    greater<>), y siempre sale el vertice pendiente con menor distancia.
    Cada uno que sale, "relaja" sus aristas: si por ahi se llega mas
    barato a un vecino, se actualiza su distancia y se mete a la cola.

    OJO: la cola puede tener el MISMO vertice varias veces, con
    distancias viejas. Por eso el continue de "dato viejo".

    Regla que lo hace funcionar: cuando un vertice SALE de la cola,
    su distancia ya es definitiva. Antes de salir puede actualizarse
    las veces que haga falta.

    NO funciona con pesos negativos.

    Complexity: O((V + E) log V)
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 10;
const int INF = 1000000000;

struct Arista {
    int destino;
    int peso;
};

vector<Arista> conexiones[MAX];
int numVertices = 6;      // A B C D E F

char nombre(int v) {
    return 'A' + v;
}

void agregarArista(int a, int b, int p) {
    conexiones[a].push_back({b, p});
    conexiones[b].push_back({a, p});   // quitar si es dirigido
}

void dijkstra(int origen) {
    int distancia[MAX];
    int previo[MAX];          // de donde vine, para reconstruir el camino

    for (int i = 0; i < numVertices; i++) {
        distancia[i] = INF;
        previo[i] = -1;
    }
    distancia[origen] = 0;

    // Heap de MINIMOS: greater<> invierte el comparador.
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> cola;

    cola.push({0, origen});     // (distancia, vertice)

    while (!cola.empty()) {
        int d = cola.top().first;
        int u = cola.top().second;
        cola.pop();

        // El vertice puede estar en la cola con una distancia VIEJA
        // (ya se mejoro despues). Este es el unico descarte posible.
        if (d > distancia[u]) continue;

        for (const Arista& a : conexiones[u]) {
            int v = a.destino;
            if (distancia[u] + a.peso < distancia[v]) {
                distancia[v] = distancia[u] + a.peso;
                previo[v] = u;
                cola.push({distancia[v], v});
            }
        }
    }

    cout << "Distancias desde " << nombre(origen) << ":" << endl;
    for (int v = 0; v < numVertices; v++) {
        cout << "  " << nombre(v) << ": ";
        if (distancia[v] == INF) {
            cout << "no se puede llegar" << endl;
        } else {
            // previo[] va del vertice HACIA el origen, asi que el camino
            // se recoge al reves y despues se imprime al derecho.
            vector<int> camino;
            for (int x = v; x != origen && x != -1; x = previo[x])
                camino.push_back(x);

            cout << distancia[v] << "  (";
            cout << nombre(origen);
            for (int i = (int)camino.size() - 1; i >= 0; i--)
                cout << " -> " << nombre(camino[i]);
            cout << ")" << endl;
        }
    }
    cout << "\n";
}

int main() {
    agregarArista(0, 1, 4);    // A-B
    agregarArista(0, 2, 2);    // A-C
    agregarArista(1, 3, 5);    // B-D
    agregarArista(2, 3, 8);    // C-D
    agregarArista(3, 4, 3);    // D-E
    // F queda aislado a proposito, para ver el INF.

    dijkstra(0);
    return 0;
}
