#ifndef ANIMAL_HERIDO_H
#define ANIMAL_HERIDO_H

#include "ElementoInteractivo.h"

class AnimalHerido : public ElementoInteractivo {
private:
    int puntosPorAyudar;

public:
    AnimalHerido(std::string nombre, int puntosPorAyudar);
    void interactuar(Explorador* explorador) override;
};

#endif
