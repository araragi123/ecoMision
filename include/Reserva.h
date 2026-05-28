#ifndef RESERVA_H
#define RESERVA_H

#include "Zona.h"
#include <string>
#include <unordered_map>

// Conjunto de zonas identificadas por un codigo (string).
class Reserva {
private:
    std::unordered_map<std::string, Zona*> zonas;

public:
    Reserva();
    ~Reserva();

    void agregarZona(std::string codigo, Zona* zona);
    Zona* buscarZona(std::string codigo);
    void mostrarZonas() const;
};

#endif
