#include <iostream>

using namespace std;

int mcd(int a, int b) {
    while (b != 0) {
        int temporal = b;
        b = a % b;
        a = temporal;
    }
    return a;
}



class Fraccion{
public:
    Fraccion(int num, int den) : num(num), den(den == 0 ? 1 : den){
        simplificar();
        signo();}

    void simplificar(){
        int simp = mcd(num, den);
        num /= simp;
        den /= simp;}
    void signo(){
        if(den < 0){
            den = -den;
            num = -num;
        }}

    Fraccion operator+(const Fraccion &otro) const{
        int Nnum = ((num*otro.den)+ (otro.num*den));
        int Nden = (den*otro.den);
        return Fraccion(Nnum, Nden);
    }
    Fraccion operator-(const Fraccion &otro) const{
        int Nnum = ((num*otro.den)- (otro.num*den));
        int Nden = (den*otro.den);
        return Fraccion(Nnum, Nden);
    }
    Fraccion operator/(const Fraccion &otro)const{
        return Fraccion(num*otro.den,den*otro.num);
    }
    Fraccion operator*(const Fraccion &otro)const{
        return Fraccion(num*otro.num,den*otro.den);
    }
    bool operator==(const Fraccion &otro)const{
        return (num == otro.num && den == otro.den);
    }

    friend ostream &operator<<(ostream &os, const Fraccion &p);
        

private:
    int num, den;
};

ostream &operator<<(ostream &os, const Fraccion &p){
    if(p.num == 0){
        os << p.num << "\n";
    }
    else if(p.den == 1){
        os << p.num << "\n";
    }
    else{
        os << p.num << "/" << p.den << "\n";
    }
    return os;
}
int main(){
    Fraccion a(1,2);
    Fraccion b(1,3);
    Fraccion d(3,4);
    Fraccion e(2,3);
    Fraccion f(2,4);
    Fraccion g(1,4);
    
    Fraccion c = a + b;
    Fraccion h = d * e;
    Fraccion i = a + g;
    if(a == f){
        cout << "Son iguales\n";
    }
    Fraccion j = a / g;
    Fraccion k(0,5); 

    cout << c;
    cout << h;
    cout << i;
    cout << j;
    cout << k;
    Fraccion l(1,0);
    cout << l;
    
    return 0;
}