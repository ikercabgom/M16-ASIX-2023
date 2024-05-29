#include <iostream>
#include "Personaje.h"

using namespace std;

Personaje::Personaje(int vida, int ataque, string nombre, int posicionX, int posicionY)
    : vida(vida), ataque(ataque), nombre(nombre), posicionX(posicionX), posicionY(posicionY) {}

// Getters y Setters
int Personaje::getVida() const {
    return vida;
}

void Personaje::setVida(int v) {
    vida = v;
}

int Personaje::getAtaque() const {
    return ataque;
}

void Personaje::setAtaque(int a) {
    ataque = a;
}

string Personaje::getNombre() const {
    return nombre;
}

void Personaje::setNombre(string n) {
    nombre = n;
}

int Personaje::getPosicionX() const {
    return posicionX;
}

void Personaje::setPosicionX(int x) {
    posicionX = x;
}

int Personaje::getPosicionY() const {
    return posicionY;
}

void Personaje::setPosicionY(int y) {
    posicionY = y;
}
