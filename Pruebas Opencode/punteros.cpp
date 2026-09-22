#include <iostream>

void incrementar(int &n){
    n++;
}

int main(){
    int x = 42;
    int &r = x;
    std::cout << "x: " << &x << " r: " << &r << "\n";
    if(x == r){
        std:: cout << "Son iguales\n";
    }
    else{
        std::cout << "No son iguales\n";
    }
    incrementar(x);
    std:: cout << "x (nuevo) : " << x << "\n";
    int *p = nullptr;
    std::cout << "puntero p: " << p << "\n";
    p = &x;
    std::cout << "Nuevo puntero p: " << *p << "\n";
}