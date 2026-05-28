#ifndef EXPLORADOR_H
#define EXPLORADOR_H

#include <string>

class Explorador {
private:
    std::string nombre;
    int energia;
    int puntajeAmbiental;
    std::string zonaActual;

public:
    Explorador(std::string nombre, int energiaInicial);

    std::string getNombre() const;
    int getEnergia() const;
    int getPuntajeAmbiental() const;
    std::string getZonaActual() const;

    void perderEnergia(int cantidad);
    void recuperarEnergia(int cantidad);
    void aumentarPuntaje(int cantidad);
    void cambiarZona(std::string codigoZona);

    void mostrarEstado() const;
};

#endif
