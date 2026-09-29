/*
=====================================================================
  08 - ORDEN TOPOLOGICO (grafos DIRIGIDOS sin ciclos)
---------------------------------------------------------------------
  Da un orden en el que cada vertice aparece ANTES de los que
  dependen de el. Ejemplo: en que orden ver las materias
  respetando los prerrequisitos.

  Algoritmo de Kahn:
   1. Contar cuantas flechas LLEGAN a cada vertice (grado de entrada).
   2. Meter en una cola los que tienen 0 (no dependen de nadie).
   3. Sacar uno, ponerlo en el orden, y "quitar" sus flechas:
      a cada vecino se le resta 1. Si llega a 0, entra a la cola.
   4. Si al final no salieron todos, el grafo TIENE UN CICLO
      (no hay orden posible).

  Compilar:  g++ 08_orden_topologico.cpp -o topologico
=====================================================================
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 10;

vector<int> dependientes[MAX];   // dependientes[a] = los que necesitan a "a"
string nombre[MAX];
int numVertices = 0;

int agregarMateria(string n) {
    nombre[numVertices] = n;
    numVertices++;
    return numVertices - 1;
}

// "antes" es prerrequisito de "despues"  (flecha antes -> despues)
void agregarPrerrequisito(int antes, int despues) {
    dependientes[antes].push_back(despues);
}

void ordenTopologico() {
    // 1. Grado de entrada
    int gradoEntrada[MAX];
    for (int i = 0; i < numVertices; i++) gradoEntrada[i] = 0;
    for (int i = 0; i < numVertices; i++)
        for (int j = 0; j < (int)dependientes[i].size(); j++)
            gradoEntrada[dependientes[i][j]]++;

    // 2. Los que no tienen prerrequisitos
    queue<int> cola;
    for (int i = 0; i < numVertices; i++)
        if (gradoEntrada[i] == 0) cola.push(i);

    // 3. Sacar y "quitar flechas"
    int cuantos = 0;
    cout << "Orden sugerido:" << endl;
    while (!cola.empty()) {
        int actual = cola.front();
        cola.pop();
        cuantos++;
        cout << "  " << cuantos << ". " << nombre[actual] << endl;

        for (int j = 0; j < (int)dependientes[actual].size(); j++) {
            int v = dependientes[actual][j];
            gradoEntrada[v]--;
            if (gradoEntrada[v] == 0) cola.push(v);
        }
    }

    // 4. Detectar ciclo
    if (cuantos < numVertices)
        cout << "ERROR: hay un ciclo, no existe orden posible" << endl;
}

int main() {
    int calc1  = agregarMateria("Calculo I");
    int calc2  = agregarMateria("Calculo II");
    int fisica = agregarMateria("Fisica I");
    int info1  = agregarMateria("Informatica I");
    int info2  = agregarMateria("Informatica II");
    int ecuac  = agregarMateria("Ecuaciones Diferenciales");
    int senal  = agregarMateria("Senales y Sistemas");

    agregarPrerrequisito(calc1, calc2);
    agregarPrerrequisito(calc1, fisica);
    agregarPrerrequisito(info1, info2);
    agregarPrerrequisito(calc2, ecuac);
    agregarPrerrequisito(ecuac, senal);
    agregarPrerrequisito(info2, senal);

    ordenTopologico();
    return 0;
}
