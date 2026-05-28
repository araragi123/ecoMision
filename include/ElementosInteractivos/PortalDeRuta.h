#ifndef PORTAL_DE_RUTA_H
#define PORTAL_DE_RUTA_H

#include "ElementoInteractivo.h"

class PortalDeRuta : public ElementoInteractivo {
private:
    std::string zonaDestino;

public:
    PortalDeRuta(std::string nombre, std::string zonaDestino);
    void interactuar(Explorador* explorador) override;
};

#endif
