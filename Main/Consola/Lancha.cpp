#include "Lancha.h"
#include <cstdlib>

Lancha::Lancha() {
    velocidad = 0;
    distancia = 0;
    nitroUsado = false;
}

int Lancha::getVelocidad() const {
    return velocidad;
}

void Lancha::setVelocidad(int pVelocidad) {
    velocidad = pVelocidad;
}

void Lancha::usarNitro() {
    if (!nitroUsado) {
        nitroUsado = true;
        int random = rand() % 2;
        if (random == 0) {
            velocidad /= 2;
        }
        else {
            velocidad *= 2;
        }
    }
}

int Lancha::lanzarDado() {
    return rand() % 6 + 1;
}

void Lancha::avanzar() {
    distancia += velocidad * 100;
}

bool Lancha::haTerminado() const {
    return distancia >= 5000;
}

int Lancha::getDistancia() const {
    return distancia;
}
