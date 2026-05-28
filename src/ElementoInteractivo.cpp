#include "ElementoInteractivo.h"
#include <iostream>

ElementoInteractivo::ElementoInteractivo(std::string nombre) : nombre(nombre) {}

std::string ElementoInteractivo::getNombre() const {
    return nombre;
}

ElementoInteractivo::~ElementoInteractivo() {
    std::cout << "   (Se elimina el elemento: " << nombre << ")\n";
}
