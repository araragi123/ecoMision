#include "ElementosInteractivos/EstacionEnergia.h"
#include "Explorador.h"
#include <iostream>

EstacionEnergia::EstacionEnergia(std::string nombre, int energiaQueDa)
    : ElementoInteractivo(nombre), energiaQueDa(energiaQueDa) {}

void EstacionEnergia::interactuar(Explorador* explorador) {
    std::cout << ">> Estacion de energia: " << nombre << "\n";
    explorador->recuperarEnergia(energiaQueDa);
}
