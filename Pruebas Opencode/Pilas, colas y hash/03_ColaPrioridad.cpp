/*
  03 - COLA DE PRIORIDAD (PRIORITY QUEUE)

  Una cola normal saca el primero que entro. Una cola de prioridad
  saca el de MAYOR PRIORIDAD, sin importar cuando entro.

  Sale el mas urgente, no el mas viejo.

  POR DEBAJO ES UN HEAP: es el ArbolHeap.cpp de la Sesion 28.
  O(log n) en vez de O(1), a cambio de no importar el orden de llegada.

  Compilar: g++ -Wall -Wextra -g 03_ColaPrioridad.cpp -o cp
*/

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <utility>    // std::pair
#include <functional> // std::greater
using namespace std;

int main() {
    // priority_queue<int> es un HEAP DE MAXIMOS: sale el mas grande.
    // Con greater<int> es de MINIMOS: sale el mas chico (el de Dijkstra).
    std::cout << "=== COLA DE PRIORIDAD de int (heap de MAXIMOS) ===\n";
    std::cout << "  sale el mas GRANDE, sin importar cuando entro\n\n";

    priority_queue<int> cp;
    for (int v : {30, 10, 50, 20, 40}) cp.push(v);

    std::cout << "  tras meter 30,10,50,20,40:\n";
    std::cout << "    top() = " << cp.top() << "   <- el 50, que entro de tercero\n";
    std::cout << "    size() = " << cp.size() << "\n";

    std::cout << "\n  sacando (de mayor a menor):\n    ";
    while (!cp.empty()) { std::cout << cp.top() << " "; cp.pop(); }
    std::cout << "\n  empty() al final: " << (cp.empty() ? "true" : "false") << "\n";

    // greater<> invierte la comparacion: gana el mas chico.
    // Esto es lo que usa Dijkstra (el nodo mas CERCA sale primero).
    std::cout << "\n=== la MISMA estructura de MINIMOS (greater<int>) ===\n\n";
    priority_queue<int, vector<int>, greater<int>> cpMin;
    for (int v : {30, 10, 50, 20, 40}) cpMin.push(v);
    std::cout << "    top() = " << cpMin.top() << "   <- el 10, que entro de segundo\n";
    std::cout << "  sacando (de menor a mayor):\n    ";
    while (!cpMin.empty()) { std::cout << cpMin.top() << " "; cpMin.pop(); }
    std::cout << "\n";

    // Mismos 5 datos, misma operacion, resultado OPUESTO.
    std::cout << "\n=== COLA NORMAL vs COLA DE PRIORIDAD ===\n\n";
    queue<int> normal;
    priority_queue<int> prio;
    for (int v : {30, 10, 50, 20, 40}) { normal.push(v); prio.push(v); }

    std::cout << "  COLA NORMAL      : ";
    while (!normal.empty()) { std::cout << normal.front() << " "; normal.pop(); }
    std::cout << "\n  COLA DE PRIORIDAD: ";
    while (!prio.empty())   { std::cout << prio.top()   << " "; prio.pop();   }
    std::cout << "\n\n    - la cola ordena por CUANDO LLEGO (FIFO)\n";
    std::cout << "    - la priorizad por QUE TAN URGENTE ES (heap)\n";

    // priority_queue de PARES (prioridad, descripcion).
    // Si dos tienen la misma prioridad, compara la segunda parte.
    // Es el par que Dijkstra mete en su cola: (distancia, nodo).
    std::cout << "\n=== priority_queue de PARES (prioridad, descripcion) ===\n\n";
    priority_queue<pair<int, string>> tareas;
    tareas.push(make_pair(3, "terminar la guia"));
    tareas.push(make_pair(8, "bebe"));
    tareas.push(make_pair(5, "estudiar para el parcial"));
    tareas.push(make_pair(9, "entrega del taller"));

    std::cout << "  de mayor a menor prioridad:\n";
    while (!tareas.empty()) {
        pair<int, string> t = tareas.top();
        tareas.pop();
        std::cout << "    [" << t.first << "] " << t.second << "\n";
    }

    // El functor solo decide QUIEN GANA. Guardar y subir los hace la
    // estructura igual.
    std::cout << "\n=== comparador PROPIO (string) ===\n\n";
    priority_queue<string, vector<string>, greater<string>> cpStr;
    for (const char* s : {"juan", "ana", "sofia", "brayan"}) cpStr.push(string(s));
    std::cout << "  nombres: juan, ana, sofia, brayan\n  sacando: ";
    while (!cpStr.empty()) { std::cout << cpStr.top() << " "; cpStr.pop(); }
    std::cout << "\n";

    // El puente a Dijkstra (M7):
    //   insertar() == push()   extraerMaximo() == pop()   heap[0] == top()
    std::cout << "\n=== puente a Dijkstra (M7) ===\n";
    std::cout << "  ArbolHeap.cpp (Sesion 28) == std::priority_queue\n";
    std::cout << "  cuando llegue Dijkstra, esto ya no es caja negra.\n";

    return 0;
}
