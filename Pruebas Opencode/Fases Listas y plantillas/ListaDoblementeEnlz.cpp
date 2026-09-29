#include <iostream>

class NodoDoble {
public:
    int dato;
    NodoDoble* anterior;
    NodoDoble* siguiente;

    NodoDoble(int valor)
        : dato(valor),
          anterior(nullptr),
          siguiente(nullptr) {}
};

class ListaDoble {
private:
    NodoDoble* cabeza;
    NodoDoble* cola;

public:
    ListaDoble(): cabeza(nullptr),cola(nullptr) {}

    void insertarInicio(int valor){
        NodoDoble* nuevo = new NodoDoble(valor);
        nuevo->siguiente = cabeza;
        if(cabeza != nullptr){
            cabeza->anterior = nuevo;
        }
        cabeza = nuevo;
        if(nuevo->siguiente == nullptr){
            cola = nuevo;
        }
    }
    void insertarFinal(int valor){
        if(cabeza == nullptr){
            NodoDoble* nuevo = new NodoDoble(valor);
            cola = nuevo;
            if(nuevo->anterior == nullptr){
                cabeza = nuevo;
            }
        }else{
            NodoDoble* nuevo = new NodoDoble(valor);
            nuevo->anterior = cola;
            cola->siguiente = nuevo;
            cola = nuevo;
        }
    }


    void imprimir() const {
        NodoDoble *actual = cabeza;
        while(actual != nullptr){
            std::cout << actual->dato << "-> " ;
            actual = actual->siguiente;
        }
        if(actual == nullptr){
            std::cout << "null";
        }
    }

    void imprimirAtras() const {
        if(cola == nullptr){
            std::cout << "null";
            return;
        }
        NodoDoble* primero = cola;
        while(primero != nullptr){
            std::cout << primero->dato << " <-> ";
            primero = primero->anterior;
        }
        if(primero == nullptr){
            std::cout << "null";
        }
    }
    bool eliminarInicio() {
        if (cabeza == nullptr) {
            return false;
        }

        NodoDoble* temp = cabeza;
        cabeza = cabeza->siguiente;

        if (cabeza == nullptr) {
            cola = nullptr;
        } else {
            cabeza->anterior = nullptr;
        }

        delete temp;
        return true;
    }

    bool eliminarFinal() {
        if (cola == nullptr) {
            return false;
        }

        NodoDoble* temp = cola;
        cola = cola->anterior;

        if (cola == nullptr) {
            cabeza = nullptr;
        } else {
            cola->siguiente = nullptr;
        }

        delete temp;
        return true;
    }

    // RAII: la lista libera sus nodos automáticamente al destruirse.
    ~ListaDoble() {
        while (cabeza != nullptr) {
            NodoDoble* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
        cola = nullptr;
    }

    // La propiedad de los nodos es exclusiva: no se pueden copiar dos veces.
    ListaDoble(const ListaDoble&) = delete;
    ListaDoble& operator=(const ListaDoble&) = delete;
};

int main() {
    ListaDoble lista;

    std::cout << "Lista vacia: ";
    lista.imprimir();
    std::cout << "\n";

    std::cout << "Lista vacia al reves: ";
    lista.imprimirAtras();
    std::cout << "\n";

    std::cout << "Eliminar inicio en lista vacia: "
              << lista.eliminarInicio() << "\n";
    std::cout << "Eliminar final en lista vacia: "
              << lista.eliminarFinal() << "\n";

    // El primer nodo debe quedar como cabeza y cola al mismo tiempo.
    lista.insertarFinal(20);
    std::cout << "Lista con un nodo: ";
    lista.imprimir();
    std::cout << "\n";

    // Inserción por los dos extremos.
    lista.insertarInicio(10);
    lista.insertarFinal(30);
    lista.insertarInicio(5);
    lista.insertarFinal(40);

    std::cout << "Lista llena: ";
    lista.imprimir();
    std::cout << "\n";
    std::cout << "Lista al reves: ";
    lista.imprimirAtras();
    std::cout << "\n";

    std::cout << "Eliminar inicio: " << lista.eliminarInicio() << "\n";
    std::cout << "Lista: ";
    lista.imprimir();
    std::cout << "\n";
    std::cout << "Lista al reves: ";
    lista.imprimirAtras();
    std::cout << "\n";

    std::cout << "Eliminar final: " << lista.eliminarFinal() << "\n";
    std::cout << "Lista: ";
    lista.imprimir();
    std::cout << "\n";
    std::cout << "Lista al reves: ";
    lista.imprimirAtras();
    std::cout << "\n";

    // Probamos los casos en que queda un solo nodo.
    std::cout << "Eliminar final: " << lista.eliminarFinal() << "\n";
    std::cout << "Lista: ";
    lista.imprimir();
    std::cout << "\n";
    std::cout << "Lista al reves: ";
    lista.imprimirAtras();
    std::cout << "\n";

    std::cout << "Eliminar inicio: " << lista.eliminarInicio() << "\n";
    std::cout << "Lista con un nodo: ";
    lista.imprimir();
    std::cout << "\n";
    std::cout << "Lista con un nodo al reves: ";
    lista.imprimirAtras();
    std::cout << "\n";

    std::cout << "Eliminar final: " << lista.eliminarFinal() << "\n";
    std::cout << "Lista final: ";
    lista.imprimir();
    std::cout << "\n";
    std::cout << "Lista final al reves: ";
    lista.imprimirAtras();
    std::cout << "\n";

    std::cout << "Eliminar inicio en lista vacia: "
              << lista.eliminarInicio() << "\n";
    std::cout << "Eliminar final en lista vacia: "
              << lista.eliminarFinal() << "\n";

    return 0;
}
