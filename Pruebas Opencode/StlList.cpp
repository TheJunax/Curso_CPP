// StlList.cpp — std::list de la STL: lista DOBLEMENTE enlazada ya hecha
#include <iostream>
#include <list>
#include <algorithm>

int main() {
    // std::list internamente es una lista doble: cada nodo tiene
    // puntero al anterior y al siguiente, + cabeza y cola guardadas.
    std::list<int> l;

    // Inserción en AMBOS extremos: O(1) (gracias a que guarda la cola)
    l.push_back(3);
    l.push_back(7);
    l.push_front(1);   // -> 1, 3, 7

    // Recorrido con iteradores (bidireccionales: ++ y --)
    for (auto it = l.begin(); it != l.end(); ++it)
        std::cout << *it << " -> ";
    std::cout << "end\n";

    // Borrar un valor: find + erase (el find es O(n), como tu eliminar)
    auto it = std::find(l.begin(), l.end(), 7);
    if (it != l.end())
        l.erase(it);

    // For-rango también funciona con list
    for (int x : l)
        std::cout << x << " ";
    std::cout << "\n";

    // Y hasta puedes caminar pa'tras: rbegin/rend
    for (auto it = l.rbegin(); it != l.rend(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    return 0;
}