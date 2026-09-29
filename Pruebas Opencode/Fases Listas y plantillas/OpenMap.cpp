#include <iostream>
#include <map>
#include <string>

int main() {
    // map: diccionario clave->valor; se ordena SOLO por la clave
    std::map<std::string, std::string> agenda;

    agenda["Juan"]  = "300-123-4567";
    agenda["Maria"] = "301-987-6543";
    agenda["Messi"]   = "305-555-0000";

    // buscar con find: devuelve iterador al elemento o end() si no existe
    auto it = agenda.find("Maria");
    if (it != agenda.end())
        std::cout << "Maria: " << it->first << " -> " << it->second << '\n';

    // recorrer con ITERADORES (ya viene ordenado por clave: Ana, Juan, Maria)
    std::cout << "\nAgenda completa (iteradores):\n";
    for (auto it = agenda.begin(); it != agenda.end(); it++)
        std::cout << "  " << it->first << " -> " << it->second << '\n';

    // recorrido con for-rango (el compilador usa iteradores por debajo)
    std::cout << "\nAgenda completa (for-rango):\n";
    for (const auto& par : agenda)
        std::cout << "  " << par.first << " -> " << par.second << '\n';

    return 0;
}