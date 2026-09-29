#include <iostream>
#include <memory>
using namespace std;

class Punto {
public:
    Punto(int x=0, int y=0) : x(x), y(y) {
        cout << "  Punto(" << x << "," << y << ") creado\n";
    }
    ~Punto() {
        cout << "  Punto(" << x << "," << y << ") destruido\n";
    }
private:
    int x, y;
};

int main() {
    // ============ PARTE 1: las dos fugas (NO tocar todavia) ============

    // FUGA 1: new sin su pareja
    unique_ptr<Punto> p = make_unique<Punto>(10, 20);
    // ... (aqui en un programa real usarias el objeto)

    // FUGA 2: new[] sin su pareja
    unique_ptr<Punto[]> arr = make_unique<Punto[]>(2);
    arr[0] = Punto(1, 1);
    arr[1] = Punto(2, 2); 
 

    return 0;
}