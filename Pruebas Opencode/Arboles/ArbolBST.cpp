
#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;
};

Nodo* crearNodo(int dato) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->izq = nullptr;
    nuevo->der = nullptr;
    return nuevo;
}


    Nodo* insertar(Nodo* raiz, int valor) {
        if (raiz == nullptr) return crearNodo(valor);   // hueco encontrado

        if (valor < raiz->dato)
            raiz->izq = insertar(raiz->izq, valor);     // bajar a la izquierda
        else if (valor > raiz->dato)
            raiz->der = insertar(raiz->der, valor);     // bajar a la derecha

        return raiz;
    }

    Nodo* minimo(Nodo* raiz){
        if(raiz == nullptr){
            return nullptr;
        }
        while(raiz->izq != nullptr){
            raiz = raiz->izq;
        }
        return raiz;
    }

    void inorden(Nodo* raiz){
        if(raiz == nullptr){
            return;
        }
        inorden(raiz->izq);
        cout << raiz->dato << " ";
        inorden(raiz->der);        
    }

    bool buscar(Nodo* raiz, int valor){
        if(raiz == nullptr){
            return false;
        }
        if(raiz->dato == valor){
            return true;
        }
        if(valor < raiz->dato){
            return buscar(raiz->izq, valor);
        }else if(valor > raiz->dato){
            return buscar(raiz->der, valor);
        }
        return false;
    }

    //// ------------------------------------------------------------
//  BORRAR
//   Caso 1: hoja         -> se elimina y el padre queda en nullptr
//   Caso 2: un hijo      -> el hijo sube a ocupar su lugar
//   Caso 3: dos hijos    -> se copia el SUCESOR (minimo del
//                           subarbol derecho) y se borra el sucesor
//  Siempre se usa asi:  raiz = borrar(raiz, valor);

    Nodo* borrar(Nodo* raiz,int valor){
        if(raiz == nullptr){
            return nullptr;
        }
        if(valor < raiz->dato){
            raiz->izq = borrar(raiz->izq, valor);
        }else if(valor > raiz->dato){
            raiz->der = borrar(raiz->der, valor);
        }
        else{
            if(raiz->izq == nullptr){
                Nodo* hijo = raiz->der;
                delete raiz;
                return hijo;
            }
            if(raiz->der == nullptr){
                Nodo* hijo = raiz->izq;
                delete raiz;
                return hijo;
            }
            Nodo* sucesor = minimo(raiz->der);
            raiz->dato = sucesor->dato;
            raiz->der = borrar(raiz->der, sucesor->dato);
        }
        return raiz;
    }

    void mostrarArbol(Nodo* raiz, int nivel) {
        if (raiz == nullptr) return;

        mostrarArbol(raiz->der, nivel + 1);

        for (int i = 0; i < nivel; i++) cout << "      ";
        cout << raiz->dato << endl;

        mostrarArbol(raiz->izq, nivel + 1);
    }

    void destruir(Nodo* raiz) {
        if (raiz == nullptr) return;
        destruir(raiz->izq);
        destruir(raiz->der);
        delete raiz;
    }



int main(){
    Nodo* raiz = nullptr;

    int datos[] = {70, 5, 50, 10, 40, 65, 20};

    for(int i=0; i<7; i++){
        raiz = insertar(raiz, datos[i]);
    }

    inorden(raiz);

    cout << "Minimo: " << minimo(raiz)->dato;

     cout << endl << "Borrar 20 (hoja):" << endl;
    raiz = borrar(raiz, 20);
    mostrarArbol(raiz, 0);

    cout << endl << "Borrar 10 (un hijo):" << endl;
    raiz = borrar(raiz, 10);
    mostrarArbol(raiz, 0);

     cout << endl << "Borrar 70 (dos hijos, es la raiz):" << endl;
    raiz = borrar(raiz, 70);
    mostrarArbol(raiz, 0);

    destruir(raiz);

    return 0;
}
