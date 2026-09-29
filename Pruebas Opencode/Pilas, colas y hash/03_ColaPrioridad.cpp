/*
=====================================================================
  03 - COLA DE PRIORIDAD (PRIORITY QUEUE)
=====================================================================
  Una cola NORMAL (02_Cola.cpp) saca siempre el primero que entro.

  Una COLA DE PRIORIDAD saca el de MAYOR PRIORIDAD, sin importar
  cuando entro:

     Priority:      [ (prio 3, "pizza") ]     [ (prio 8, "bebe") ]     [ (prio 5, "estudiar") ]
       que sale?          (prio 3, "pizza")           (prio 8, "bebe")         (prio 5, "estudiar")
                           ^ entra ultimo,             ^ entra primero,         ^ entro en medio,
                           pero sale primero           pero sale segundo        y sale tercero

  REGLA: sale el de mayor prioridad (el mas "urgente").
  Se usa cuando la IMPORTANCIA de un elemento no depende del TIEMPO
  en que llego.

  *** POR QUE IMPORTA: ES UN HEAP ***
  Por debajo es EXACTAMENTE el ArbolHeap.cpp de la Sesion 28.
  El heap es la estructura que hace esto en O(log n):
  guardar = "poner al final y subir"    sacar = "sacar la raiz y bajar"
  Esa es la diferencia con la cola normal, que guarda y saca en O(1)
  pero en ORDEN de llegada (y no puede buscar por prioridad).

  Compilar:  g++ -Wall -Wextra -g 03_ColaPrioridad.cpp -o cp
=====================================================================
*/

#include <iostream>
#include <queue>      // std::priority_queue
#include <string>     // std::string
#include <vector>     // std::vector
#include <utility>    // std::pair  (el "make_pair" y "pair" de la STL)
#include <functional> // std::greater  (el comparador invertido)
using namespace std;

// ===========================================================================
//  LA COLA DE PRIORIDAD — la version de la STL, explicada
// ===========================================================================
//
//  std::priority_queue<T> es un HEAP DE MAXIMOS (como el que escribiste
//  en ArbolHeap.cpp). Eso significa:
//
//    - por defecto saca el ELEMENTO MAS GRANDE de todos
//    - se apoya en operator< de T para decidir que es "mas grande"
//
//  La diferencia con la cola normal, lado a lado:
//
//       std::queue               std::priority_queue
//    ----------------          -----------------------
//    push(x)   O(1)            push(x)   O(log n)   (sube por el heap)
//    front()   el primero      top()     el MAYOR   (no el primero)
//    pop()     O(1)            pop()     O(log n)   (baja por el heap)
//    ordena    por LLEGADA     ordena    por VALOR
//
//  *** POR QUE NO ES O(1) COMO LA COLA NORMAL ***
//  Para sacar el mas rapido de todos, el heap tiene que dejar ese valor
//  ARRIBA (en la raiz). Guardar no basta: cada vez que metes algo,
//  puede tener que subirlo. Por eso es O(log n) en vez de O(1).
//  A cambio te da algo que la cola normal no puede: no importa el orden
//  de llegada, el mas urgente sale primero.
// ===========================================================================

// ---------------------------------------------------------------------------
//  Para entender los 4 metodos que usa (los escribiste en ArbolHeap.cpp):
//
//    insertar(x)      -> push(x)    -> "pone al final y sube"
//    extraerMaximo()  -> pop()      -> "saca la raiz y baja"
//    (leer la raiz)   -> top()      -> "mira la raiz sin sacar"
//
//  Y el COMPARADOR, que es lo que hace que sea de MAXIMOS:
//
//    Con el comparador por defecto (operator<), gana el mas grande.
//    Con greater<T>, gana el mas CHICO  (heap de MINIMOS).
//    El functor se llama asi:  mayor_es_gana(a, b).
// ---------------------------------------------------------------------------

int main() {
    // =======================================================================
    //  PARTE 1 — priority_queue de int (heap de MAXIMOS, el de defecto)
    // =======================================================================
    std::cout << "=== COLA DE PRIORIDAD de int (heap de MAXIMOS) ===\n";
    std::cout << "  (sale el mas GRANDE, sin importar cuando entro)\n\n";

    priority_queue<int> cp;

    // Guardar. OJO: push, no meter. Y cada uno va a su propio lugar.
    for (int v : {30, 10, 50, 20, 40}) {
        cp.push(v);
    }

    std::cout << "  tras meter 30,10,50,20,40:\n";
    std::cout << "    top() = " << cp.top() << "   <- el 50, que entro de tercero\n";
    std::cout << "    size() = " << cp.size() << ", empty() = " << (cp.empty() ? "true" : "false") << "\n";

    // Sacar. Cada pop() saca el mas grande que quede.
    std::cout << "\n  sacando uno por uno (de mayor a menor):\n    ";
    while (!cp.empty()) {
        std::cout << cp.top() << " ";
        cp.pop();     // pop primero, o top() queda libre
    }
    std::cout << "\n  empty() al final: " << (cp.empty() ? "true" : "false") << "\n";

    // =======================================================================
    //  PARTE 2 — heap de MINIMOS (con greater<int>)
    // =======================================================================
    //  El functor greater<> INVIERTE la comparacion. Asi el mas CHICO sale
    //  primero. Es el mismo heap, con el criterio de "mayor" al reves.
    //
    //  ESTO es lo que se usa en Dijkstra (el nodo mas CERCA sale primero).
    std::cout << "\n\n=== la MISMA estructura pero de MINIMOS (con greater<int>) ===\n";
    std::cout << "  (sale el mas CHICO — es lo que necesita Dijkstra)\n\n";

    priority_queue<int, vector<int>, greater<int>> cpMin;

    for (int v : {30, 10, 50, 20, 40}) {
        cpMin.push(v);
    }
    std::cout << "  tras meter 30,10,50,20,40:\n";
    std::cout << "    top() = " << cpMin.top() << "   <- el 10, que entro de segundo\n";

    std::cout << "\n  sacando (de menor a mayor):\n    ";
    while (!cpMin.empty()) {
        std::cout << cpMin.top() << " ";
        cpMin.pop();
    }
    std::cout << "\n";

    // =======================================================================
    //  PARTE 3 — la COLA NORMAL, para comparar lado a lado
    // =======================================================================
    //  mismos 5 numeros, misma operacion "sacar", resultado OPUESTO.
    std::cout << "\n\n=== COLA NORMAL vs COLA DE PRIORIDAD ===\n";
    std::cout << "  (los mismos 5 datos, se saca hasta vaciar)\n\n";

    queue<int> normal;                        // FIFO: el primero que entro
    priority_queue<int> prio;                 // heap: el mas grande

    for (int v : {30, 10, 50, 20, 40}) {
        normal.push(v);
        prio.push(v);
    }

    std::cout << "  COLA NORMAL      : ";
    while (!normal.empty()) { std::cout << normal.front() << " "; normal.pop(); }

    std::cout << "\n  COLA DE PRIORIDAD: ";
    while (!prio.empty())   { std::cout << prio.top()   << " "; prio.pop();   }

    std::cout << "\n\n  Mismos datos, misma cantidad de pops, resultado OPUESTO.\n";
    std::cout << "    - la cola ordena por CUANDO LLEGO  (FIFO)\n";
    std::cout << "    - la priorizad por QUE TAN URGENTE ES (heap)\n";

    // =======================================================================
    //  PARTE 4 — priority_queue de PARES (prioridad + dato)
    // =======================================================================
    //  Esto es lo que se usa de verdad. Cada elemento es un par:
    //  (prioridad, descripcion). La prioridad manda; si dos tienen la
    //  MISMA prioridad, compara la segunda parte (el string).
    //
    //  Es exactamente el par que Dijkstra mete en su cola: (distancia, nodo).
    std::cout << "\n\n=== priority_queue de PARES (prioridad, descripcion) ===\n";
    std::cout << "  (esto es lo que usa Dijkstra: distancia + nodo)\n\n";

    priority_queue<pair<int, string>> tareas;

    // make_pair(prioridad, descripcion)
    tareas.push(make_pair(3,  "terminar la guia"));   // prio baja
    tareas.push(make_pair(8,  "bebe"));                // prio ALTA
    tareas.push(make_pair(5,  "estudiar para el parcial"));
    tareas.push(make_pair(9,  "entrega del taller"));  // la mas urgente

    std::cout << "  Tareas (sacan de mayor a menor prioridad):\n";
    while (!tareas.empty()) {
        pair<int, string> t = tareas.top();   // copia: se lee el par entero
        tareas.pop();
        std::cout << "    [" << t.first << "] " << t.second << "\n";
    }

    // =======================================================================
    //  PARTE 5 — el comparador PROPIO (lo mas potente de todo)
    // =======================================================================
    //  A veces el "mayor" no es el numero mas alto. Se puede definir un
    //  comparador con struct/operator(), o con un lambda.
    //
    //  EJEMPLO: una cola de prioridad donde el "valor" es un string, y
    //  el orden es... el INVERSO del string (Z antes que A). Con
    //  greater<string> sale al reves. Se puede ver que el functor
    //  solo decide QUIEN GANA; lo demas (guardar, subir, bajar) lo
    //  hace la estructura igual.
    std::cout << "\n=== comparador PROPIO: priority_queue de string ===\n";
    std::cout << "  (con greater<string> sale el string MAS GRANDE primero)\n\n";

    priority_queue<string, vector<string>, greater<string>> cpStr;
    for (const char* s : {"juan", "ana", "sofia", "brayan"}) {
        cpStr.push(string(s));
    }
    std::cout << "  nombres: juan, ana, sofia, brayan\n";
    std::cout << "  sacando (mayor string primero):\n    ";
    while (!cpStr.empty()) {
        std::cout << cpStr.top() << " ";
        cpStr.pop();
    }
    std::cout << "\n";

    // =======================================================================
    //  PARTE 6 — el puente a Dijkstra
    // =======================================================================
    //  La razon por la que la cola de prioridad importa en este curso:
    //  en la Sesion 28 escribiste ArbolHeap.cpp. Esta es la MISMA cosa
    //  pero enlatada, con las 3 operaciones ya resueltas:
    //
    //      ArbolHeap.cpp  ->  insertar()   =  push()
    //      ArbolHeap.cpp  ->  extraerMax() =  pop()
    //      ArbolHeap.cpp  ->  heap[0]      =  top()
    //
    //  El nodo de la fila de arriba (ArbolHeap) es UN heap de maximos.
    //  La STL lo tiene listo. En el M7 (grafos), Dijkstra metera pares
    //  (distancia, nodo) en una priority_queue<int, vector, greater<>>
    //  para sacar siempre el nodo mas cercano.
    std::cout << "\n=== puente a Dijkstra (M7) ===\n";
    std::cout << "  ArbolHeap.cpp (Sesion 28)  ==  std::priority_queue\n";
    std::cout << "  insertar()  -> push()        (poner al final y subir)\n";
    std::cout << "  extraer()   -> pop()          (sacar la raiz y bajar)\n";
    std::cout << "  heap[0]     -> top()          (la raiz = el mas grande)\n\n";
    std::cout << "  Cuando llegue Dijkstra, esto ya no es caja negra.\n";

    return 0;
}
