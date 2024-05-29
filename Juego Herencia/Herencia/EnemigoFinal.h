#ifndef ENEMIGOFINAL_H
#define ENEMIGOFINAL_H

#include "Personaje.h"

using namespace std;

class EnemigoFinal : public Personaje {
private:
    string superAtaque1;
    string superAtaque2;

public:
    EnemigoFinal(int vida, int ataque, string nombre, int posicionX, int posicionY, string superAtaque1, string superAtaque2);

    string getSuperAtaque1() const;
    void setSuperAtaque1(string superAtaque1);

    string getSuperAtaque2() const;
    void setSuperAtaque2(string superAtaque2);
};

#endif
