/*
    PRIM y KRUSKAL - los dos hacen lo MISMO con dos ideas distintas.

    Problema: conectar TODOS los vertices con aristas cuya suma de
    pesos sea la menor posible. El resultado es un ARBOL (n-1 aristas).

    PRIM:    crece desde UN vertice, como si fuera una mancha de tinta.
             "De todo lo que toco por fuera, agarro la arista mas barata."
             Usa priority_queue (igual que Dijkstra).

    KRUSKAL: mira las aristas de una en una, de menor a mayor peso.
             Acepta la que NO forme ciclo. No usa heap para nodos:
             ordena las aristas, que ya es un dato de entrada.
             Usa UNION-FIND para saber si dos vertices ya estan unidos.

    Los dos dan el MISMO costo total (es un teorema), pero el camino
    para llegar ahi es completamente distinto.

    Los dos funcionan con pesos negativos. NO son Dijkstra: no acumulan
    distancias, asi que no hay nada que "se congele".
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 10;
const int INF = 1000000000;

struct Arista {
    int destino;
    int peso;
};

vector<Arista> conexiones[MAX];
int numVertices = 5;      // A B C D E

char nombre(int v) { return 'A' + v; }

void agregarArista(int a, int b, int p) {
    conexiones[a].push_back({b, p});
    conexiones[b].push_back({a, p});
}

void mostrarGrafo() {
    for (int v = 0; v < numVertices; v++) {
        cout << "  " << nombre(v) << ": ";
        for (const Arista& a : conexiones[v])
            cout << nombre(a.destino) << "(" << a.peso << ") ";
        cout << endl;
    }
    cout << endl;
}

// ================= PRIM =================
void prim() {
    int costo[MAX];         // peso de la arista MAS BARATA para meter a v
    int padre[MAX];         // de donde viene esa arista
    bool enArbol[MAX];

    for (int i = 0; i < numVertices; i++) {
        costo[i] = INF;
        padre[i] = -1;
        enArbol[i] = false;
    }
    costo[0] = 0;           // arrancamos en A: costo 0, como si ya estuviera

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> cola;
    cola.push({0, 0});

    cout << "--- PRIM (crece desde A) ---" << endl;
    int total = 0;

    while (!cola.empty()) {
        int peso = cola.top().first;    // el peso de la arista, NO acumulado
        int u = cola.top().second;
        cola.pop();

        if (enArbol[u]) continue;       // ya estaba, esta entrada era vieja
        enArbol[u] = true;
        if (u != 0) {
            cout << "  " << nombre(padre[u]) << " - " << nombre(u)
                 << "  (peso " << peso << ")" << endl;
            total += peso;
        }

        for (const Arista& a : conexiones[u]) {
            int v = a.destino;
            // "relajar": si esta arista es mas barata que la que tenia v, la cambio
            if (!enArbol[v] && a.peso < costo[v]) {
                costo[v] = a.peso;
                padre[v] = u;
                cola.push({a.peso, v});
            }
        }
    }
    cout << "  Costo total: " << total << endl << endl;
}

// ================= KRUSKAL =================
// Kruskal necesita las aristas sueltas (origen, destino, peso), no
// colgadas de un vertice. Es una struct distinta a proposito.
struct AristaG {
    int origen;
    int destino;
    int peso;
};

int jefe[MAX];

int buscarJefe(int v) {
    // compresion de camino: el jefe queda apuntando directo a la raiz
    while (jefe[v] != v) {
        jefe[v] = jefe[jefe[v]];
        v = jefe[v];
    }
    return v;
}

void unir(int a, int b) {
    jefe[buscarJefe(a)] = buscarJefe(b);
}

void kruskal() {
    vector<AristaG> todas;
    for (int u = 0; u < numVertices; u++)
        for (const Arista& a : conexiones[u])
            if (u < a.destino)          // u < v, para no repetir la arista
                todas.push_back({u, a.destino, a.peso});

    sort(todas.begin(), todas.end(),
         [](const AristaG& x, const AristaG& y) { return x.peso < y.peso; });

    for (int i = 0; i < numVertices; i++) jefe[i] = i;   // todos solos

    cout << "--- KRUSKAL (de menor a mayor peso) ---" << endl;
    int total = 0, aceptadas = 0;

    for (const AristaG& a : todas) {
        if (buscarJefe(a.origen) != buscarJefe(a.destino)) {   // no hay ciclo
            unir(a.origen, a.destino);
            cout << "  " << nombre(a.origen) << " - " << nombre(a.destino)
                 << "  (" << a.peso << ")  ACEPTA" << endl;
            total += a.peso;
            if (++aceptadas == numVertices - 1) break;
        } else {
            cout << "  " << nombre(a.origen) << " - " << nombre(a.destino)
                 << "  (" << a.peso << ")  descarta (ciclo)" << endl;
        }
    }
    cout << "  Costo total: " << total << endl << endl;
}

int main() {
    agregarArista(0, 1, 4);    // A-B
    agregarArista(0, 2, 2);    // A-C
    agregarArista(1, 3, 5);    // B-D
    agregarArista(2, 3, 8);    // C-D
    agregarArista(3, 4, 3);    // D-E

    cout << "Grafo:" << endl;
    mostrarGrafo();

    prim();
    kruskal();
    return 0;
}
