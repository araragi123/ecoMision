#include "ElementosInteractivos/ResiduoContaminante.h"
#include "Explorador.h"
#include <iostream>

ResiduoContaminante::ResiduoContaminante(std::string nombre,
                                         int energiaQueCuesta,
                                         int puntosPorLimpiar)
    : ElementoInteractivo(nombre),
      energiaQueCuesta(energiaQueCuesta),
      puntosPorLimpiar(puntosPorLimpiar) {}

void ResiduoContaminante::interactuar(Explorador* explorador) {
    std::cout << ">> Residuo contaminante: " << nombre << "\n";
    explorador->perderEnergia(energiaQueCuesta);
    explorador->aumentarPuntaje(puntosPorLimpiar);
}
