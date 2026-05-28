#ifndef PLANTA_MEDICINAL_H
#define PLANTA_MEDICINAL_H

#include "ElementoInteractivo.h"

class PlantaMedicinal : public ElementoInteractivo {
private:
    int energiaQueDa;
    int puntosQueDa;

public:
    PlantaMedicinal(std::string nombre, int energiaQueDa, int puntosQueDa);
    void interactuar(Explorador* explorador) override;
};

#endif
