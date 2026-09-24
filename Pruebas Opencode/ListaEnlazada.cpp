#include <iostream>

class Nodo {
public:
    int dato;
    Nodo* siguiente;
    Nodo(int d) : dato(d), siguiente(nullptr) {}
};

class Lista {
private:
    Nodo* cabeza;

public:
    Lista() : cabeza(nullptr) {}

    // Inserta un nodo al inicio de la lista.
    void insertarInicio(int valor) {
        Nodo* nuevo = new Nodo(valor);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
        // TODO: crea un Nodo nuevo, haz que su 'siguiente' apunte a la cabeza actual
        //       y luego mueve la cabeza al nuevo nodo.
    }

    void insertarFinal(int valor){
        if(cabeza == nullptr){
            Nodo *nuevo = new Nodo(valor);
            cabeza = nuevo;
            
        }else{
            Nodo* ultimo = cabeza;
            while(ultimo->siguiente != nullptr){
                ultimo = ultimo->siguiente;
            }
            ultimo->siguiente = new Nodo(valor);
        }
    }

    void insertarOrdenado(int valor){
        if(cabeza == nullptr || valor <= cabeza->dato){
            Nodo *nuevo = new Nodo(valor);
            nuevo->siguiente = cabeza;
            cabeza = nuevo;
        }else{
        Nodo* anterior = cabeza;
        Nodo* actual = cabeza->siguiente;
        while(actual != nullptr && actual->dato < valor ){
            anterior = actual;
            actual = actual->siguiente;
        }
        Nodo *nuevo = new Nodo(valor);
        nuevo->siguiente = actual;
        anterior->siguiente = nuevo;
        }
    }

    // Recorre e imprime los elementos.
    void imprimir() const {
        Nodo *actual = cabeza;
        while(actual != nullptr){
            std::cout << actual->dato << "-> " ;
            actual = actual->siguiente;
        }
        if(actual == nullptr){
            std::cout << "null";
        }
    }

    bool buscar(int valor)const {
        Nodo *actual = cabeza;
            while(actual != nullptr){
                if(valor == actual->dato){
                    return true;
               }
               actual = actual->siguiente;
            }
            if(actual == nullptr){
                return false;
            }
        return false;
    }

    bool eliminar(int valor){
        if(cabeza == nullptr){
            return false;
        }
        if(cabeza->dato == valor){
            Nodo *borrar = cabeza;
            cabeza = cabeza->siguiente;
            delete borrar;
            return true;
        }
        Nodo* anterior = cabeza;
        Nodo* actual = cabeza->siguiente;
        while(actual != nullptr && actual->dato != valor ){
            anterior = actual;
            actual = actual->siguiente;
        }
        if(actual == nullptr){
            return false;
        }else{
            anterior->siguiente = actual->siguiente;
        }
        delete actual;
        return true;
    }

    // RAII: libera todos los nodos al destruir la lista.
    ~Lista() {
        while(cabeza != nullptr){
            Nodo*temp = cabeza->siguiente;
                delete cabeza;
                cabeza = temp;
        }
        
        // TODO: recorre la lista liberando cada nodo (sin perder el siguiente).
    }
};

int main() {
    Lista l;
    l.insertarOrdenado(5);
    l.insertarOrdenado(2);
    l.insertarOrdenado(8);
    l.insertarOrdenado(3);
    l.imprimir();    // esperado: 2 -> 3 -> 5 -> 8 -> null    
    return 0;
}