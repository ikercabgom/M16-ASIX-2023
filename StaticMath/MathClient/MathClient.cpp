#include <iostream>
#include <vector>
#include "../MathLibrary/MathLibrary.h"

int main() {
    std::vector<int> numerosPrimitiva = MathLibrary::generarNumerosPrimitiva();
    int reintegro = MathLibrary::generarReintegro();

    std::cout << "Números de la Primitiva: ";
    for (int num : numerosPrimitiva) {
        std::cout << num << " ";
    }
    std::cout << "\nReintegro: " << reintegro << std::endl;

    return 0;
}
