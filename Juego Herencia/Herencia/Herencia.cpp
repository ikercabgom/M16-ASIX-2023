#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Personaje.h"
#include "EnemigoFinal.h"

using namespace std;

const int FILAS = 10;
const int COLUMNAS = 10;
const char VACIO = '.';
const char HEROE = 'H';
const char ENEMIGO = 'E';
const char GUARIDA = 'G';

void inicializarArray(char nivel[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            nivel[i][j] = VACIO;
        }
    }
}

void colocarPersonaje(char nivel[FILAS][COLUMNAS], Personaje& personaje, char simbolo) {
    nivel[personaje.getPosicionX()][personaje.getPosicionY()] = simbolo;
}

void moverHeroe(char nivel[FILAS][COLUMNAS], Personaje& heroe) {
    char movimiento;
    cout << "Mueve al héroe (w/a/s/d): ";
    cin >> movimiento;

    int nuevaX = heroe.getPosicionX();
    int nuevaY = heroe.getPosicionY();

    switch (movimiento) {
    case 'w': nuevaX--; break; // Mover hacia arriba
    case 'a': nuevaY--; break; // Mover hacia la izquierda
    case 's': nuevaX++; break; // Mover hacia abajo
    case 'd': nuevaY++; break; // Mover hacia la derecha
    default: cout << "Movimiento no válido." << endl; return;
    }

    return 0;
}
