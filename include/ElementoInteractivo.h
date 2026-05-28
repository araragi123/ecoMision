#ifndef ELEMENTO_INTERACTIVO_H
#define ELEMENTO_INTERACTIVO_H

#include <string>

class Explorador;

// Clase abstracta. Define la interfaz de cualquier elemento
// con el que el explorador puede interactuar.
class ElementoInteractivo {
protected:
    std::string nombre;

public:
    ElementoInteractivo(std::string nombre);
    virtual ~ElementoInteractivo();

    virtual void interactuar(Explorador* explorador) = 0;
    std::string getNombre() const;
};

#endif
