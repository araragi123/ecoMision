#include "EcoMision.h"
#include "Zona.h"
#include "ElementosInteractivos/AnimalHerido.h"
#include "ElementosInteractivos/EstacionEnergia.h"
#include "ElementosInteractivos/ResiduoContaminante.h"
#include "ElementosInteractivos/PortalDeRuta.h"
#include "ElementosInteractivos/PlantaMedicinal.h"
#include <iostream>

EcoMision::EcoMision()
    : reserva(nullptr), explorador(nullptr) {}

void EcoMision::prepararReserva() {
    std::cout << "\n=== Preparando la reserva natural ===\n";

    reserva = new Reserva();

    Zona* bosque = new Zona("Bosque Humedo");
    bosque->agregarElemento(new AnimalHerido("Tucan herido", 15));
    bosque->agregarElemento(new PlantaMedicinal("Hierba curativa", 10, 5));
    bosque->agregarElemento(new PortalDeRuta("Sendero al rio", "rio"));

    Zona* rio = new Zona("Rio Contaminado");
    rio->agregarElemento(new ResiduoContaminante("Plastico en el agua", 10, 20));
    rio->agregarElemento(new EstacionEnergia("Mirador con descanso", 25));

    reserva->agregarZona("bosque", bosque);
    reserva->agregarZona("rio", rio);
}

void EcoMision::crearExplorador() {
    std::cout << "\n=== Creando al explorador ===\n";
    explorador = new Explorador("Camila", 50);
    explorador->cambiarZona("bosque");
}

void EcoMision::ejecutarDemostracion() {
    std::cout << "\n=== Comienza la demostracion ===\n";

    explorador->mostrarEstado();
    reserva->mostrarZonas();

    Zona* zonaActual = reserva->buscarZona(explorador->getZonaActual());
    zonaActual->mostrarElementos();

    std::cout << "\n=== Interacciones en el bosque ===\n";
    zonaActual->interactuarCon(0, explorador);                  // por indice
    zonaActual->interactuarCon("Hierba curativa", explorador);  // por nombre
    zonaActual->interactuarCon("Sendero al rio", explorador);

    explorador->mostrarEstado();

    Zona* nuevaZona = reserva->buscarZona(explorador->getZonaActual());
    if (nuevaZona != nullptr) {
        nuevaZona->mostrarElementos();
        std::cout << "\n=== Interacciones en el rio ===\n";
        nuevaZona->interactuarCon("Plastico en el agua", explorador);
        nuevaZona->interactuarCon(1, explorador);
    }

    std::cout << "\n=== Estado final del explorador ===\n";
    explorador->mostrarEstado();
}

void EcoMision::iniciar() {
    std::cout << "=== EcoMision ===\n";

    prepararReserva();
    crearExplorador();
    ejecutarDemostracion();

    std::cout << "\n=== Fin de la demostracion ===\n";
}

EcoMision::~EcoMision() {
    std::cout << "\n=== Limpiando memoria ===\n";
    delete explorador;
    delete reserva;
}
