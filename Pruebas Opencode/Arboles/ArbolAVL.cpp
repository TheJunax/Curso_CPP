#include <iostream>

struct Nodo {
    int dato;
    int altura;
    Nodo* izq;
    Nodo* der;

};

Nodo* CrearNodo(int valor){
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->altura = 1;
    nuevo->izq = nullptr;
    nuevo->der = nullptr;
    
    return nuevo;
}

int altura(Nodo* nodo){
    if(nodo == nullptr){
        return 0;
    }
    return nodo->altura;
    
}

int mayor(int a, int b){
    return a > b ? a : b;
}

void actualizarAltura(Nodo* nodo){
    nodo->altura = mayor(altura(nodo->izq), altura(nodo->der)) + 1;
}

int factorEquilibrio(Nodo* nodo){
    if(nodo == nullptr){
        return 0;
    }
    return altura(nodo->izq) - altura(nodo->der);
}

Nodo* rotarDerecha(Nodo*nodo){
    Nodo* hijo = nodo->izq; 
    Nodo* nieto = hijo->der;

    hijo->der = nodo;
    nodo->izq = nieto;

    actualizarAltura(nodo);
    actualizarAltura(hijo);
    return hijo;

}

Nodo* rotarIzquierda(Nodo* nodo){
    Nodo* hijo = nodo->der;
    Nodo* nieto = hijo->izq;

    hijo->izq = nodo;
    nodo->der = nieto;

    actualizarAltura(nodo);
    actualizarAltura(hijo);
    return hijo;
}

Nodo* insertar(Nodo* raiz, int valor){
    if(raiz == nullptr){
        return CrearNodo(valor);
    }
    if (valor < raiz->dato)
        raiz->izq = insertar(raiz->izq, valor);     // bajar a la izquierda
    else if (valor > raiz->dato)
        raiz->der = insertar(raiz->der, valor);
    else return raiz;

    actualizarAltura(raiz);
    
    if(valor > raiz->dato && factorEquilibrio(raiz) < -1){
        return rotarIzquierda(raiz);
    }else if(valor < raiz->dato && factorEquilibrio(raiz) > 1){
        return rotarDerecha(raiz);
    }else if(valor < raiz->dato && factorEquilibrio(raiz) < -1){
        raiz->izq = rotarIzquierda(raiz->izq);
        return rotarDerecha(raiz);
    }else if(valor > raiz->dato && factorEquilibrio(raiz) > 1){
        raiz->der = rotarDerecha(raiz->der);
        return rotarIzquierda(raiz);
    }
    return raiz;

}

void inorden(Nodo* raiz){
    if(raiz == nullptr){
        return;
    }
    inorden(raiz->izq);
    std::cout << raiz->dato << " ";
    inorden(raiz->der);
}

void mostrarArbol(Nodo* raiz, int nivel) {
    if (raiz == nullptr) return;

    mostrarArbol(raiz->der, nivel + 1);

    for (int i = 0; i < nivel; i++) std::cout << "      ";
    std::cout << raiz->dato << "\n";

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

    int datos[] = {10,20,30,40,50,25};
    for (int i = 0; i < 6; i++) {
        std::cout << "Insertar " << datos[i] << std::endl;
        raiz = insertar(raiz, datos[i]);
    }

    std::cout << std::endl << "Arbol AVL final (acostado):" << std::endl;
    mostrarArbol(raiz, 0);

    std::cout << std::endl << "Inorden: ";
    inorden(raiz);
    std::cout << std::endl << "Altura: " << altura(raiz) << std::endl;

    // Prueba: insertar 1..15 en orden.
    // Un BST normal quedaria como una lista (altura 15).
    // El AVL queda con altura 4.
    Nodo* otro = nullptr;
    std::cout << std::endl << "Insertando 1 a 15 en orden..." << std::endl;
    for (int i = 1; i <= 15; i++) otro = insertar(otro, i);
    std::cout << "Altura del AVL: " << altura(otro) << " (un BST normal tendria 15)" << std::endl;

    destruir(raiz);
    destruir(otro);

    return 0;
}
