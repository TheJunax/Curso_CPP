#include <iostream>
#include <string>

template <typename T>
T minimo(T a, T b){
    return (a < b) ? a : b;
}

int main(){
    std::cout << minimo(4,5) << "\n";
    std::cout << minimo(3.9,3.67) << "\n";
    std::cout << minimo(std::string ("Messi"),std::string ("Juan")) << "\n";
    std::cout << minimo(std::string ("Maria"),std::string ("Aura")) << "\n";

}