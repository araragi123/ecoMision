#include "Reserva.h"
#include <iostream>

Reserva::Reserva() {}

void Reserva::agregarZona(std::string codigo, Zona* zona) {
    zonas[codigo] = zona;
    std::cout << "Zona registrada: codigo='" << codigo
              << "' -> " << zona->getNombre() << "\n";
}

Zona* Reserva::buscarZona(std::string codigo) {
    auto resultado = zonas.find(codigo);
    if (resultado == zonas.end()) {
        return nullptr;
    }
    return resultado->second;
}

void Reserva::mostrarZonas() const {
    std::cout << "\n=== Zonas registradas en la reserva ===\n";
    for (const auto& par : zonas) {
        std::cout << "   * codigo '" << par.first
                  << "' -> " << par.second->getNombre() << "\n";
    }
    std::cout << "=======================================\n";
}

Reserva::~Reserva() {
    for (auto& par : zonas) {
        delete par.second;
    }
}
