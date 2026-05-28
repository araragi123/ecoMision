#include "Zona.h"
#include "Explorador.h"
#include <iostream>

Zona::Zona(std::string nombre) : nombre(nombre) {}

std::string Zona::getNombre() const {
    return nombre;
}

void Zona::agregarElemento(ElementoInteractivo* elemento) {
    elementos.push_back(elemento);
}

void Zona::mostrarElementos() const {
    std::cout << "\nElementos en la zona '" << nombre << "':\n";
    if (elementos.empty()) {
        std::cout << "   (no hay elementos)\n";
        return;
    }
    for (int i = 0; i < (int)elementos.size(); i++) {
        std::cout << "   [" << i << "] " << elementos[i]->getNombre() << "\n";
    }
}

// Sobrecarga: por indice
void Zona::interactuarCon(int indice, Explorador* explorador) {
    if (indice < 0 || indice >= (int)elementos.size()) {
        std::cout << "   (Indice invalido)\n";
        return;
    }
    elementos[indice]->interactuar(explorador);
}

// Sobrecarga: por nombre
void Zona::interactuarCon(std::string nombreElemento, Explorador* explorador) {
    for (int i = 0; i < (int)elementos.size(); i++) {
        if (elementos[i]->getNombre() == nombreElemento) {
            elementos[i]->interactuar(explorador);
            return;
        }
    }
    std::cout << "   (No se encontro el elemento '" << nombreElemento << "')\n";
}

Zona::~Zona() {
    for (int i = 0; i < (int)elementos.size(); i++) {
        delete elementos[i];
    }
}
