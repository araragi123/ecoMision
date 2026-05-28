#include "ElementosInteractivos/PlantaMedicinal.h"
#include "Explorador.h"
#include <iostream>

PlantaMedicinal::PlantaMedicinal(std::string nombre, int energiaQueDa, int puntosQueDa)
    : ElementoInteractivo(nombre),
      energiaQueDa(energiaQueDa),
      puntosQueDa(puntosQueDa) {}

void PlantaMedicinal::interactuar(Explorador* explorador) {
    std::cout << ">> Planta medicinal: " << nombre << "\n";
    explorador->recuperarEnergia(energiaQueDa);
    explorador->aumentarPuntaje(puntosQueDa);
}
