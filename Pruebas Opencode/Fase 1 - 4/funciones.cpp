#include <iostream>

int sumar(int a, int b){
    std::cout << "(Suma int)";
    return a+b;
}
double sumar(double a, double b){
    std::cout << "(Suma double)";
    return a+b;
}
void dibujarRec(int ancho, int alto, char carac = '*'){
    for(int i =0; i< alto;i++){
        for(int j=0; j< ancho; j++){
            std::cout << carac;
        }
        std::cout << "\n";
    }
    
}

int main(){
    std::cout << sumar(3, 7);
    std::cout << sumar(3.6, 2.9);
    // std::cout << sumar(4.7, 8); el programa no sabe cual decidir
    std::cout << "\n";
    dibujarRec(12, 5);

    std::cout << "\n";
    dibujarRec(12, 5, '"');

    
    return 0;
}