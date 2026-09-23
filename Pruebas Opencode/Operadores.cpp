#include <iostream>

using namespace std;

class Complejos{

public:
    Complejos(double a, double bi) : a(a), bi(bi){}

    Complejos operator+(const Complejos &otro) const {
        return Complejos(a + otro.a, bi + otro.bi);
    }

    Complejos operator*(const Complejos &otro) const {
        double nuevoA = (a*otro.a)-(bi*otro.bi);
        double nuevoB = (a*otro.bi)+(bi*otro.a);
        return Complejos(nuevoA , nuevoB);
    }

    bool operator==(const Complejos &otro) const {
        return a == otro.a && bi == otro.bi; 
    }

    friend ostream &operator<<(ostream &os, const Complejos &c);

    private:
        double a;
        double bi;
};

ostream& operator<<(ostream &os, const Complejos &c){
    os << c.a << " + " << c.bi << "i";
    return os;
}

int main(){
    Complejos a(5,7);
    Complejos b(4,6);

    Complejos c = a + b;
    cout << c << "\n";

    Complejos d = a * b;
    cout << d << "\n";

    cout << c << " y " << d << "\n";

    if (a == b)
        cout << "a y b son iguales\n";
    else
        cout << "a y b son distintos\n";

    

    return 0;

}