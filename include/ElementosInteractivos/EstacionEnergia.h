#ifndef ESTACION_ENERGIA_H
#define ESTACION_ENERGIA_H

#include "ElementoInteractivo.h"

class EstacionEnergia : public ElementoInteractivo {
private:
    int energiaQueDa;

public:
    EstacionEnergia(std::string nombre, int energiaQueDa);
    void interactuar(Explorador* explorador) override;
};

#endif
