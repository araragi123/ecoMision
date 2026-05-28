#ifndef RESIDUO_CONTAMINANTE_H
#define RESIDUO_CONTAMINANTE_H

#include "ElementoInteractivo.h"

class ResiduoContaminante : public ElementoInteractivo {
private:
    int energiaQueCuesta;
    int puntosPorLimpiar;

public:
    ResiduoContaminante(std::string nombre, int energiaQueCuesta, int puntosPorLimpiar);
    void interactuar(Explorador* explorador) override;
};

#endif
