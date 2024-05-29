#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>

using namespace std;

class Personaje {
private:
    int vida;
    int ataque;
    string nombre;
    int posicionX;
    int posicionY;

public:
    Personaje(int vida, int ataque, string nombre, int posicionX, int posicionY);

    int getVida() const;
    void setVida(int vida);

    int getAtaque() const;
    void setAtaque(int ataque);

    string getNombre() const;
    void setNombre(string nombre);

    int getPosicionX() const;
    void setPosicionX(int posicionX);

    int getPosicionY() const;
    void setPosicionY(int posicionY);
};

#endif
