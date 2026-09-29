#include <iostream>

class Nodo {
public:
    int dato;
    Nodo* siguiente;

    explicit Nodo(int valor): dato(valor), siguiente(nullptr){}
};

class ListaCircular {
private:
    Nodo* cabeza;
    Nodo* cola;

public:
    ListaCircular(): cabeza(nullptr), cola(nullptr){}

    void insertarFinal(int valor){
        if(cabeza == nullptr){
            Nodo *nuevo = new Nodo(valor);
            cabeza = nuevo;
            cola = nuevo;
            nuevo->siguiente = cabeza;
        }else if(cabeza->siguiente == cabeza){
            Nodo *nuevo = new Nodo(valor);
            cabeza->siguiente = nuevo;
            cola = nuevo;
            nuevo->siguiente = cabeza;

        }else{
            Nodo* ultimo = cola;
            Nodo* nuevo = new Nodo(valor);
            ultimo->siguiente = nuevo;
            nuevo->siguiente = cabeza;
            cola = nuevo;
        }
    }
    
    void insertarInicio(int valor){
        if(cabeza == nullptr){
            Nodo *nuevo = new Nodo(valor);
            cabeza = nuevo;
            cola = nuevo;
            nuevo->siguiente = cabeza;

        }else if(cabeza->siguiente == cabeza){
            Nodo* nuevo = new Nodo(valor);
            nuevo->siguiente = cabeza;
            cabeza->siguiente = nuevo;
            cabeza = nuevo;
        }else{
            Nodo* ultimo = cola;
            Nodo* nuevo = new Nodo(valor);
            ultimo->siguiente = nuevo;
            nuevo->siguiente = cabeza;
            cabeza = nuevo; 
        }
    }
    bool buscar(int valor) const{
        if(cabeza == nullptr){
            return false;
        }else if(cabeza->dato == valor){
            return true;
        }
        Nodo *actual = cabeza;
        do{
            actual = actual->siguiente;
        }while(actual != cabeza && actual->dato != valor);
        if(actual->dato == valor){
            return true;
        }else if(actual == cabeza){
            return false;
        }
        return false;
    }

    bool eliminar(int valor){
        if(cabeza == nullptr){
            return false;
        }
        if(cabeza->dato == valor){
            // Si el único nodo se apunta a sí mismo, al borrarlo la lista queda vacía.
            if(cabeza->siguiente == cabeza){
                delete cabeza;
                cabeza = nullptr;
                cola = nullptr;
                return true;
            }
            // El último nodo apunta a la cabeza que se va a borrar:
            // hay que desviarlo hacia la nueva cabeza antes de liberar.
            Nodo* ultimo = cabeza;
            while(ultimo->siguiente != cabeza){
                ultimo = ultimo->siguiente;
            }
            Nodo* aBorrar = cabeza;
            cabeza = cabeza->siguiente;
            ultimo->siguiente = cabeza;
            delete aBorrar;
            return true;
        }
        Nodo* anterior = cabeza;
        Nodo* actual = cabeza->siguiente;
        while(actual != cabeza && actual->dato != valor){
            anterior = actual;
            actual = actual->siguiente;
        }
        if(actual == cabeza){
            return false;
        }
        anterior->siguiente = actual->siguiente;
        if(anterior->siguiente == cabeza){
            cola = anterior;
        }
        delete actual;
        return true;
    }
    void imprimir() const{
        if(cabeza == nullptr){
            std::cout << "lista vacia";
            return;
        }
        Nodo* actual = cabeza;
        do{
            std::cout << actual->dato << " -> ";
            actual = actual->siguiente;
        }while(actual != cabeza);
        // Imprimimos la cabeza otra vez para mostrar que el ciclo cerró.
        std::cout << cabeza->dato;
    }

    // Con punteros crudos y destructor manual, una copia duplicaría los punteros
    // y los dos destructores liberarían la misma memoria (doble free).
    ListaCircular(const ListaCircular&) = delete;
    ListaCircular& operator=(const ListaCircular&) = delete;

    ~ListaCircular(){
        if(cabeza == nullptr){
            return;
        }
        // El caminante es una variable local: `cabeza` es la dirección a la que
        // hay que volver, no la variable que avanza.
        Nodo* actual = cabeza;
        do{
            Nodo* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }while(actual != cabeza);
        cabeza = nullptr;
    }
};

int main(){
    ListaCircular lista;

    std::cout << "--- insertarFinal ---\n";
    lista.insertarFinal(1);
    lista.insertarFinal(2);
    lista.insertarFinal(3);
    lista.imprimir();

    std::cout << "\n--- insertarInicio ---\n";
    lista.insertarInicio(0);
    lista.imprimir();

    std::cout << "\n--- buscar ---\n";
    std::cout << "buscar(2): " << (lista.buscar(2) ? "true" : "false") << "\n";
    std::cout << "buscar(9): " << (lista.buscar(9) ? "true" : "false") << "\n";

    std::cout << "\n--- eliminar ---\n";
    std::cout << "eliminar(9) (no existe): " << (lista.eliminar(9) ? "true" : "false") << "\n";
    std::cout << "eliminar(2) (intermedio): " << (lista.eliminar(2) ? "true" : "false") << " | ";
    lista.imprimir();
    std::cout << "\neliminar(0) (cabeza): " << (lista.eliminar(0) ? "true" : "false") << " | ";
    lista.imprimir();
    std::cout << "\neliminar(3) (cola): " << (lista.eliminar(3) ? "true" : "false") << " | ";
    lista.imprimir();
    std::cout << "\n";
    std::cout << "eliminar(1) (ultimo nodo): " << (lista.eliminar(1) ? "true" : "false") << " | ";
    lista.imprimir();
    std::cout << "\neliminar(1) de nuevo: " << (lista.eliminar(1) ? "true" : "false") << "\n";

    std::cout << "\n--- lista vacia ---\n";
    {
        ListaCircular vacia;
        vacia.imprimir();
        std::cout << "\neliminar(1) en vacia: " << (vacia.eliminar(1) ? "true" : "false") << "\n";
        vacia.insertarFinal(7);
        vacia.imprimir();
        std::cout << "\n";
        vacia.eliminar(7);
        std::cout << "quedo: ";
        vacia.imprimir();
        std::cout << "\n(se destruyo una lista vacia sin crashear)\n";
    }

    return 0;
}