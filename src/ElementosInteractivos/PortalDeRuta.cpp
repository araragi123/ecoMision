#include "ElementosInteractivos/PortalDeRuta.h"
#include "Explorador.h"
#include <iostream>

PortalDeRuta::PortalDeRuta(std::string nombre, std::string zonaDestino)
    : ElementoInteractivo(nombre), zonaDestino(zonaDestino) {}

void PortalDeRuta::interactuar(Explorador* explorador) {
    std::cout << ">> Portal: " << nombre << "\n";
    explorador->cambiarZona(zonaDestino);
}
