#include "ElementosInteractivos/AnimalHerido.h"
#include "Explorador.h"
#include <iostream>

AnimalHerido::AnimalHerido(std::string nombre, int puntosPorAyudar)
    : ElementoInteractivo(nombre), puntosPorAyudar(puntosPorAyudar) {}

void AnimalHerido::interactuar(Explorador* explorador) {
    std::cout << ">> Animal herido: " << nombre << "\n";
    explorador->aumentarPuntaje(puntosPorAyudar);
}
