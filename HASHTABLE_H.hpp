#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <optional>
#include <cmath>
#include <vector>
constexpr int SIZE = 16;


class HashTable {
    private:
    int bits = 4;
    int cantidad = 0;
    std::vector<std::vector<std::string>> tablaHash;

    int funcionHashSuma(const std::string& palabra){
        unsigned long int suma = 0;
        for(char c : palabra){
            suma += static_cast<int>(c);
        }
        return suma & ((1UL << bits) - 1);
    }
    int funcionHashMult(const std::string& palabra){
        unsigned long int mult = 1;
        for(char c : palabra){
            mult *= static_cast<int>(c);
        }
        return mult & ((1UL << bits) - 1);
    }
    int funcionHashXOR(const std::string& palabra){
        unsigned long int XOR = static_cast<int>(palabra[0]);
        for(size_t i = 1; i < palabra.length(); i++){
            
            XOR ^= palabra[i];
        }
        return XOR;
    }


public:
    HashTable(int bits = 4) : bits(bits) {
        tablaHash.resize(1 << bits);

    }

    void insertarElemento(const std::string& palabra){
        int ind = funcionHashSuma(palabra);
        tablaHash[ind].push_back(palabra);
        cantidad++;

    }
    void mostrarColisiones(){
        for (std::size_t i = 0; i < tablaHash.size(); i++){
            if (tablaHash[i].size() >= 2){
                
                std::cout << "La cantidad de elementos colisionados en el bucket " << i << " es de: " << tablaHash[i].size() <<  std::endl;
            }
        }
    }

    void resumen() const {
        std::size_t vacias = 0, colisionadas = 0, peor = 0;
        for (const auto& cubeta : tablaHash) {
            if (cubeta.empty()) vacias++;
            if (cubeta.size() >= 2) colisionadas++;
            if (cubeta.size() > peor) peor = cubeta.size();
        }
        std::cout << "cubetas: "      << tablaHash.size() << "\n"
                << " | vacias: "       << vacias  << "\n"
                << " | colisionadas: " << colisionadas << "\n"
                << " | alpha: "        << (double)cantidad / tablaHash.size() << "\n"
                << " | peor cubeta: "  << peor << "\n"
                << "\n";
    }

    // Remove all key-value pairs from the hash table.
    void clear(){
        tablaHash.clear();
        cantidad = 0;
    }

    void crecer(){
        std::vector<std::vector<std::string>> nueva(tablaHash.size() * 2);
        bits += 1;                             
        for (auto& cubeta : tablaHash)
            for (auto& p : cubeta)
                nueva[funcionHashSuma(p)].push_back(p);   // ahora usa b
        tablaHash = nueva;
    }
    

};

#endif // HASHTABLE_H


