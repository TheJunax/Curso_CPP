#include <iostream>
#include <map>
#include <string>

void agregarContacto(std::map<std::string, std::string> &contacto, const std::string& nombre, const std::string& telefono){
    contacto[nombre] = telefono;
    std::cout << "Contacto Agregado con exito";
}

void buscarContacto(const std::map<std::string, std::string> &contacto, const std::string& nombre){
    auto it = contacto.find(nombre);
    if(it == contacto.end()){
        std::cout << "No se encontro la persona";
    }else{
        std::cout << it->first << ": " << it->second;
    }
}

void mostrarContactos(const std::map<std::string, std::string> &contacto){
    for(auto it = contacto.begin();it != contacto.end(); it++ ){
        std::cout << it->first << ": " << it->second << "\n";

    }
}

void eliminarContacto(std::map<std::string, std::string> &contacto, const std::string& nombre){
    auto it = contacto.find(nombre);
    if(it == contacto.end()){
        std::cout << "No se encontro la persona";
    }else{
        contacto.erase(nombre);
        if(contacto.find(nombre) == contacto.end()){
            std::cout << "Persona eliminada con exito";
        }
    }

}

int main(){

    std::map<std::string, std::string> contactos;

    contactos["Juan"] = "3198435364";
    contactos["Deiby"] = "3056448762";
    contactos["Isabella"] = "3202750141";
    contactos["Aura"] = "3005091057";

    auto opcion =0;
    std::cout << "Elija una opcion: \n";

    do{
        std::cout << "1. Agregar contacto \n2. Buscar por nombre \n3. Mostrar todos los contactos ordenados \n4. Eliminar un contacto \n5. Salir\n";
        std::cin >> opcion;
        
        switch (opcion){
            case 1:{
                std::string nombre, telefono;
                std::cout << "Escriba el nombre: ";
                std::cin >> nombre;
                std::cout << "\n";

                std::cout << "Escriba el telefono: ";
                std::cin >> telefono;
                std::cout << "\n";
                agregarContacto(contactos, nombre, telefono);
                std::cout << "\n";

                break;
            }
            case 2:{
                std::string nombre;
                std::cout << "Escriba el nombre de la persona a buscar: ";
                std::cin >> nombre;
                std::cout << "\n";
                buscarContacto(contactos, nombre);
                std::cout << "\n";
                break;
            }
            case 3:
                mostrarContactos(contactos);
                std::cout << "\n";
                break;

            case 4:{
                std::string nombre;
                std::cout << "Escriba el nombre de la persona a buscar: ";
                std::cin >> nombre;
                std::cout << "\n";
                eliminarContacto(contactos, nombre);
                std::cout << "\n";
                break;
            }
            case 5:
            std::cout << "Chao";
            break;
        }

    }while(opcion !=5);




}