#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main(){

    auto Lambda = [](int a, int b){
        return a * b;
    };
    int base = 5;

    auto valor = [base](int x){
        return pow(base, x);
    };
    auto referencia = [&base](int x){
        return pow(base, x);
    };
    base = 4;

    std::vector<int> notas = {45,80,60,32,95};
    
    int aprobadas = std::count_if(notas.begin(), notas.end(), [](int n){ return n >= 60;});


    int a =4, b=2, x=3;
    std::cout << Lambda(a,b);
    std::cout << "\n";
    std::cout << valor(x);
    std::cout << "\n";
    std::cout << referencia(x);
    std::cout << "\n";
    std::cout << aprobadas << "\n";

}