#ifndef ZONA_H
#define ZONA_H

#include "ElementoInteractivo.h"
#include <string>
#include <vector>

class Explorador;

// Lugar de la reserva. Agrega elementos interactivos.
// interactuarCon esta sobrecargado: por indice o por nombre.
class Zona {
private:
    std::string nombre;
    std::vector<ElementoInteractivo*> elementos;

public:
    Zona(std::string nombre);
    ~Zona();

    std::string getNombre() const;
    void agregarElemento(ElementoInteractivo* elemento);
    void mostrarElementos() const;

    void interactuarCon(int indice, Explorador* explorador);
    void interactuarCon(std::string nombreElemento, Explorador* explorador);
};

#endif
