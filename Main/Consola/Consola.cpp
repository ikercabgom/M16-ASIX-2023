#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Lancha.h"

using namespace std;

int main() {
    srand(time(NULL));

    Lancha lancha1;
    Lancha lancha2;

    bool nitroDisponibleLancha1 = true;

    for (int turno = 1; turno <= 5; turno++) {
        cout << "Turno " << turno << endl;

        cout << "Presiona Enter para lanzar el dado con la Lancha 1" << endl;
        cin.ignore();
        int dado1 = lancha1.lanzarDado();
        lancha1.setVelocidad(lancha1.getVelocidad() + dado1);
        lancha1.avanzar();
        cout << "Lancha 1: " << lancha1.getVelocidad() << " m/s, Distancia recorrida: " << lancha1.getDistancia() << " metros\n";

        
        if (nitroDisponibleLancha1 && !lancha1.haTerminado()) {
            cout << "¿Deseas usar el nitro en la Lancha 1? (s/n): ";
            char respuesta;
            cin >> respuesta;
            if (respuesta == 's') {
                lancha1.usarNitro();
                nitroDisponibleLancha1 = false;
            }
        }

        cout << "Presiona Enter para lanzar el dado con la Lancha 2" << endl;
        cin.ignore();
        int dado2 = lancha2.lanzarDado();
        lancha2.setVelocidad(lancha2.getVelocidad() + dado2);
        lancha2.avanzar();
        cout << "Lancha 2: " << lancha2.getVelocidad() << " m/s, Distancia recorrida: " << lancha2.getDistancia() << " metros\n";

        cout << endl;
    }

    cout << "Resultados finales:" << endl;
    cout << "Velocidad de la Lancha 1: " << lancha1.getVelocidad() << " m/s, Distancia recorrida: " << lancha1.getDistancia() << " metros\n";
    cout << "Velocidad de la Lancha 2: " << lancha2.getVelocidad() << " m/s, Distancia recorrida: " << lancha2.getDistancia() << " metros\n";

    if (lancha1.getDistancia() > lancha2.getDistancia()) {
        cout << "¡La lancha 1 ha ganado!" << endl;
    }
    else if (lancha2.getDistancia() > lancha1.getDistancia()) {
        cout << "¡La lancha 2 ha ganado!" << endl;
    }
    else {
        cout << "¡Empate!" << endl;
    }

    return 0;
}
