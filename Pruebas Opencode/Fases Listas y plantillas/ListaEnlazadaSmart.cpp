#include <iostream>
#include <memory>
#include <string>

// Cada nodo es dueño del siguiente: al liberar la cabeza se libera
// toda la cadena en cascada, sin destructor manual.
template <typename T>
class Nodo {
public:
    T dato;
    std::unique_ptr<Nodo<T>> siguiente;   // el enlace es un dueño, no un puntero

    explicit Nodo(const T& valor) : dato(valor) {}
};

template <typename T>
class ListaEnlazada {
private:
    std::unique_ptr<Nodo<T>> cabeza;

public:
    // No hace falta inicializar: un unique_ptr nace vacío.
    ListaEnlazada() = default;

    void insertarInicio(const T& valor){
        auto nuevo = std::make_unique<Nodo<T>>(valor);
        nuevo->siguiente = std::move(cabeza);  // adopta la cadena actual
        cabeza = std::move(nuevo);             // el nuevo pasa a ser cabeza
    }

    void insertarFinal(const T& valor){
        auto nuevo = std::make_unique<Nodo<T>>(valor);
        if(!cabeza){
            cabeza = std::move(nuevo);
            return;
        }
        Nodo<T>* ultimo = cabeza.get();
        while(ultimo->siguiente){
            ultimo = ultimo->siguiente.get();
        }
        ultimo->siguiente = std::move(nuevo);
    }

    void insertarOrdenado(const T& valor){
        auto nuevo = std::make_unique<Nodo<T>>(valor);
        if(!cabeza || valor < cabeza->dato){
            nuevo->siguiente = std::move(cabeza);
            cabeza = std::move(nuevo);
            return;
        }
        Nodo<T>* actual = cabeza.get();
        while(actual->siguiente && actual->siguiente->dato < valor){
            actual = actual->siguiente.get();
        }
        nuevo->siguiente = std::move(actual->siguiente);
        actual->siguiente = std::move(nuevo);
    }

    bool buscar(const T& valor) const{
        Nodo<T>* actual = cabeza.get();
        while(actual){
            if(actual->dato == valor){
                return true;
            }
            actual = actual->siguiente.get();
        }
        return false;
    }

    bool eliminar(const T& valor){
        if(!cabeza){
            return false;
        }
        if(cabeza->dato == valor){
            cabeza = std::move(cabeza->siguiente);
            return true;
        }
        Nodo<T>* anterior = cabeza.get();
        Nodo<T>* actual = anterior->siguiente.get();
        while(actual && actual->dato != valor){
            anterior = actual;
            actual = actual->siguiente.get();
        }
        if(!actual){
            return false;
        }
        anterior->siguiente = std::move(actual->siguiente);
        return true;
    }

    void imprimir() const{
        Nodo<T>* actual = cabeza.get();
        if(!actual){
            std::cout << "lista vacia";
            return;
        }
        while(actual){
            std::cout << actual->dato << " -> ";
            actual = actual->siguiente.get();
        }
        std::cout << "null";
    }

    // Sin destructor: unique_ptr libera la cadena sola.
    // Sin = delete en copia: unique_ptr no es copiable, asi que el
    // compilador ya borra el constructor de copia y el operator=.
};

int main(){
    ListaEnlazada<int> lista;
    lista.insertarFinal(5);
    lista.insertarFinal(2);
    lista.insertarFinal(8);
    lista.insertarInicio(7);
    std::cout << "insertarFinal + insertarInicio: ";
    lista.imprimir();

    std::cout << "\n\ninsertarOrdenado (3 y 1): ";
    lista.insertarOrdenado(3);
    lista.insertarOrdenado(1);
    lista.imprimir();

    std::cout << "\n\nbuscar(8): " << (lista.buscar(8) ? "true" : "false") << "\n";
    std::cout << "buscar(99): " << (lista.buscar(99) ? "true" : "false") << "\n";

    std::cout << "\neliminar(2) (medio): " << (lista.eliminar(2) ? "true" : "false") << " | ";
    lista.imprimir();
    std::cout << "\neliminar(7) (cabeza): " << (lista.eliminar(7) ? "true" : "false") << " | ";
    lista.imprimir();
    std::cout << "\neliminar(99) (no existe): " << (lista.eliminar(99) ? "true" : "false") << "\n";

    std::cout << "\n--- vaciada por completo ---\n";
    lista.eliminar(1);
    lista.eliminar(5);
    lista.eliminar(3);
    lista.eliminar(8);
    lista.imprimir();
    std::cout << "\neliminar(1) en vacia: " << (lista.eliminar(1) ? "true" : "false") << "\n";

    std::cout << "\n--- misma clase con std::string ---\n";
    ListaEnlazada<std::string> nombres;
    nombres.insertarFinal(std::string("Zoe"));
    nombres.insertarFinal(std::string("Ana"));
    nombres.insertarInicio(std::string("Miguel"));
    nombres.insertarOrdenado(std::string("Bea"));
    nombres.imprimir();
    std::cout << "\nbuscar(\"Bea\"): " << (nombres.buscar(std::string("Bea")) ? "true" : "false") << "\n";
    nombres.eliminar(std::string("Miguel"));
    std::cout << "tras eliminar a Miguel: ";
    nombres.imprimir();
    std::cout << "\n";

    std::cout << "\n--- destructor al salir del main ---\n";
    return 0;
}
