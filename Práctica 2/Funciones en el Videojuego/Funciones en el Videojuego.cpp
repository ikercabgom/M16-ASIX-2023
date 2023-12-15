#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

void introduccionJuego(std::string& characterName) {
    std::cout << "Tu pokemon principal es un Pikachu, y te has encontrado a unos enemigos, escribe el nombre que quieres ponerle.\n";
    std::cin >> characterName;
}

bool realizaAtaqueEnemigo(int& characterHP, int enemyDamage, const std::string& enemyName) {
    characterHP -= enemyDamage;
    if (characterHP <= 0) {
        characterHP = 0;
        std::cout << enemyName << " te ha puesto fino. Game Over\n";
        return true; // El ataque del enemigo mató al héroe
    }
    std::cout << enemyName << " te ha pegado un tortazo de " << enemyDamage << " y te quedan " << characterHP << " de vida.\n";
    return false; // El héroe sigue vivo
}

bool realizaAtaqueHeroe(int& enemyHP, int attackDamage, const std::string& enemyName, bool& enemyAlive, const std::string& characterName) {
    enemyHP -= attackDamage;
    if (enemyHP <= 0) {
        enemyHP = 0;
        enemyAlive = false;
        std::cout << "Te has cargado a " << enemyName << " y eres la cabra en esto\n";
        return true; // El ataque del héroe mató al enemigo
    }
    std::cout << characterName << " le ha pegado un ataque de " << attackDamage << " a " << enemyName << " y le quedan " << (enemyAlive ? enemyHP : 0) << " de vida\n";
    return false; // El enemigo sigue vivo
}

int seleccionaEnemigo() {
    int choice;
    std::cout << "Elige a que enemigo quieres atacar (1 o 2): ";
    std::cin >> choice;

    // Asegurarse de que la elección sea válida
    while (choice != 1 && choice != 2) {
        std::cout << "Seleccion invalida. Por favor, elige 1 o 2: ";
        std::cin >> choice;
    }

    return choice;
}

int main() {
    srand(time(0));

    int characterHP = 500;
    int characterDamage = 0;
    std::string characterName;

    int boss1HP = 250;
    int boss1Damage = rand() % 100;
    std::string boss1Name = "Gengar";
    bool boss1Alive = true;

    int boss2HP = 150;
    int boss2Damage = rand() % 100;
    std::string boss2Name = "Meowth";
    bool boss2Alive = true;

    int specialAttackCount = 3;

    introduccionJuego(characterName);

    while (characterHP > 0 && (boss1Alive || boss2Alive)) {
        std::cout << characterName << " (HP: " << characterHP << ")\n";
        if (boss1Alive) {
            std::cout << "1. " << boss1Name << " (HP: " << boss1HP << ")\n";
        }
        if (boss2Alive) {
            std::cout << "2. " << boss2Name << " (HP: " << boss2HP << ")\n";
        }

        int choice = seleccionaEnemigo();

        int attackChoice;
        int attackDamage = 0;

        int attackType = rand() % 100;

        if (attackType <= 25) {
            attackChoice = 1;
            attackDamage = rand() % 26;
        }
        else if (attackType <= 50) {
            attackChoice = 2;
            attackDamage = 26 + rand() % 25;
        }
        else {
            attackChoice = 3;
            attackDamage = 51 + rand() % 50;
        }

        std::cout << "Elige el tipo de ataque:\n";
        std::cout << "1. Ataque rapido\n";
        std::cout << "2. Chispazo\n";
        if (specialAttackCount > 0) {
            std::cout << "3. Impactrueno (Ataque especial, quedan " << specialAttackCount << ")\n";
        }
        std::cin >> attackChoice;

        if (attackChoice == 1) {
            attackDamage = rand() % 26;
        }
        else if (attackChoice == 2) {
            attackDamage = 26 + rand() % 25;
        }
        else if (attackChoice == 3 && specialAttackCount > 0) {
            attackDamage = 51 + rand() % 50;
            specialAttackCount--;
        }
        else {
            std::cout << "Seleccion de ataque invalida. Se usara un ataque por defecto.\n";
            attackDamage = rand() % 26;
        }

        if (choice == 1 && boss1Alive) {
            realizaAtaqueHeroe(boss1HP, attackDamage, boss1Name, boss1Alive, characterName);
        }
        else if (choice == 2 && boss2Alive) {
            realizaAtaqueHeroe(boss2HP, attackDamage, boss2Name, boss2Alive, characterName);
        }
        else {
            std::cout << "Selección invalida. Intenta de nuevo.\n";
        }

        if (boss1Alive) {
            realizaAtaqueEnemigo(characterHP, boss1Damage, boss1Name);
        }

        if (boss2Alive) {
            realizaAtaqueEnemigo(characterHP, boss2Damage, boss2Name);
        }
    }

    std::cout << "Se acabo el juego beiby" << std::endl;

    return 0;
}
