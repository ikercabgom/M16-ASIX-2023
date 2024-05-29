#include <iostream>
#include "EnemigoFinal.h"

using namespace std;

EnemigoFinal::EnemigoFinal(int vida, int ataque, string nombre, int posicionX, int posicionY, string superAtaque1, string superAtaque2)
    : Personaje(vida, ataque, nombre, posicionX, posicionY), superAtaque1(superAtaque1), superAtaque2(superAtaque2) {}

string EnemigoFinal::getSuperAtaque1() const {
    return superAtaque1;
}

void EnemigoFinal::setSuperAtaque1(string sa1) {
    superAtaque1 = sa1;
}

string EnemigoFinal::getSuperAtaque2() const {
    return superAtaque2;
}

void EnemigoFinal::setSuperAtaque2(string sa2) {
    superAtaque2 = sa2;
}
