#include <iostream>
#include <fstream>
#include <string>

int main() {
    // ========== ESCRIBIR con ofstream (out) ==========
    std::ofstream salida("datos.txt");   // abre (o crea) el archivo para escribir
    if (!salida) {                        // si no se pudo abrir
        std::cerr << "No se pudo abrir para escribir\n";
        return 1;
    }
    salida << "linea 1 del archivo\n";   // igual que fprintf pero con <<
    salida << "linea 2 del archivo\n";
    salida.close();                       // fclose manual (opcional si vives en un bloque)

    // ========== LEER con ifstream (in) ==========
    std::ifstream entrada("datos.txt");
    if (!entrada) {
        std::cerr << "No se pudo abrir para leer\n";
        return 1;
    }
    std::string linea;
    while (std::getline(entrada, linea)) {   // lee linea por linea hasta el final
        std::cout << "Leida: " << linea << '\n';
    }
    // aqui no cerramos: el destructor de entrada lo hace solo al salir de main

    return 0;
}