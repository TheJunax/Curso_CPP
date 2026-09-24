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
    l.insertarInicio(3);
    l.insertarInicio(7);
    l.insertarInicio(1);
    l.imprimir();   // esperado: 1 -> 7 -> 3 -> nullptr

    return 0;
}