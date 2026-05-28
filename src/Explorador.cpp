#include "Explorador.h"
#include <iostream>

Explorador::Explorador(std::string nombre, int energiaInicial)
    : nombre(nombre),
      energia(energiaInicial),
      puntajeAmbiental(0),
      zonaActual("") {}

std::string Explorador::getNombre() const { return nombre; }
int Explorador::getEnergia() const { return energia; }
int Explorador::getPuntajeAmbiental() const { return puntajeAmbiental; }
std::string Explorador::getZonaActual() const { return zonaActual; }

void Explorador::perderEnergia(int cantidad) {
    energia -= cantidad;
    if (energia < 0) energia = 0;
    std::cout << "   -> " << nombre << " pierde " << cantidad
              << " de energia. (Energia: " << energia << ")\n";
}

void Explorador::recuperarEnergia(int cantidad) {
    energia += cantidad;
    std::cout << "   -> " << nombre << " recupera " << cantidad
              << " de energia. (Energia: " << energia << ")\n";
}

void Explorador::aumentarPuntaje(int cantidad) {
    puntajeAmbiental += cantidad;
    std::cout << "   -> " << nombre << " gana " << cantidad
              << " puntos ambientales. (Puntaje: " << puntajeAmbiental << ")\n";
}

void Explorador::cambiarZona(std::string codigoZona) {
    zonaActual = codigoZona;
    std::cout << "   -> " << nombre << " se mueve a la zona '" << codigoZona << "'.\n";
}

void Explorador::mostrarEstado() const {
    std::cout << "==============================\n";
    std::cout << " Explorador: " << nombre << "\n";
    std::cout << " Energia: " << energia << "\n";
    std::cout << " Puntaje ambiental: " << puntajeAmbiental << "\n";
    std::cout << " Zona actual: " << zonaActual << "\n";
    std::cout << "==============================\n";
}
