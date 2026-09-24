#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> palabras = {"casa", "perro", "casa", "gato", "perro", "casa"};

    // unordered_map: sin orden, busqueda O(1) promedio (hash)
    std::unordered_map<std::string, int> freq;
    for (const auto& p : palabras)
        freq[p]++;   // operator[] crea la entrada en 0 la primera vez

    std::cout << "unordered_map (sin orden):\n";
    for (const auto& par : freq)
        std::cout << "  " << par.first << ": " << par.second << '\n';

    // map: ordenado por clave, busqueda O(log n)
    std::map<std::string, int> freqOrd;
    for (const auto& p : palabras)
        freqOrd[p]++;

    std::cout << "\nmap (ordenado por clave):\n";
    for (const auto& par : freqOrd)
        std::cout << "  " << par.first << ": " << par.second << '\n';

    return 0;
}