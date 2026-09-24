#include <iostream>
#include <vector>
using namespace std;

class Contador{
public:
    Contador(int n) : n(n){}

    ~Contador(){
        cout << "Se destruye\n";
    }

    Contador(const Contador &otro): n(otro.n) {
        cout << "Copia\n";
    } 

    Contador(Contador&& otro) : n(otro.n){
        cout << "Mueve y roba\n";
        otro.n =0;
    }

private:
    int n;
};

int main(){
    std::vector<Contador> contadores;
    std::cout << "capacity inicial: " << contadores.capacity() << '\n';

    for (int i = 0; i < 10; ++i) {
        contadores.push_back(i);
        std::cout << "size=" << contadores.size() << " capacity=" << contadores.capacity()
                  << (contadores.size() == contadores.capacity() ? "  <-- se lleno (reubicara en el proximo push)" : "")
                  << '\n';
    }
    return 0;
 
}