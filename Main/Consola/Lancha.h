#pragma once
#include <iostream>

class Lancha {
private:
    int velocidad;
    int distancia;
    bool nitroUsado;
    std::string name;

public:
    Lancha();
    int getVelocidad() const;
    void setVelocidad(int pVelocidad);
    void usarNitro();
    int lanzarDado();
    void avanzar();
    bool haTerminado() const;
    int getDistancia() const;
};
