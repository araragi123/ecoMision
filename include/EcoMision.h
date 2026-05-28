#ifndef ECO_MISION_H
#define ECO_MISION_H

#include "Reserva.h"
#include "Explorador.h"

// Clase coordinadora del prototipo. El main solo llama a iniciar().
class EcoMision {
private:
    Reserva* reserva;
    Explorador* explorador;

    void prepararReserva();
    void crearExplorador();
    void ejecutarDemostracion();

public:
    EcoMision();
    ~EcoMision();

    void iniciar();
};

#endif
