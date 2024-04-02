#include "MathLibrary.h"
#include <random>
#include <algorithm>

std::vector<int> MathLibrary::generarNumerosPrimitiva() {
    std::vector<int> numeros;
    for (int i = 1; i <= 49; ++i) {
        numeros.push_back(i);
    }

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(numeros.begin(), numeros.end(), g);

    return std::vector<int>(numeros.begin(), numeros.begin() + 6);
}

int MathLibrary::generarReintegro() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<int> distribution(0, 9);
    return distribution(g);
}
