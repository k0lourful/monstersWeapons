#include "Game.h"
#include "weakMonster.h"
#include "normalMonster.h"
#include "strongMonster.h"
#include "Player.h"
#include "Weapon.h"
#include <iostream>

void Game::createEntities() {
    int weaponChoice = 0;
    Weapon* weapon = nullptr;
    Monster* weak, *normal, *strong;

    std::cout << "\nGive player a weapon?\n";
    std::cout << "1. None\n";
    std::cout << "2. Bat\n";
    std::cout << "3. Sword\n";

    while (weaponChoice < 1 || weaponChoice > 3) {
        std::cin >> weaponChoice;

        switch (weaponChoice) {
        case 1:
            break;

        case 2: {
            weapon = new Weapon(5, 15);
            break;
        }

        case 3: {
            weapon = new Weapon(10, 30);
            break;
        }
              
        default: {
            std::cout << "\nInvalid input, try again: ";
        }
        }
    }

    player = new Player(100, 15, weapon);

    std::cout << "Should enemies have weapons? Type 1 if so, or 0 otherwise: ";
    std::cin >> weaponChoice;
    while (weaponChoice < 0 || weaponChoice > 1) {
        std::cout << "Invalid input, try again: ";
        std::cin >> weaponChoice;
    }

    weak = new weakMonster(100,10,weaponChoice?new Weapon(8,12):nullptr);
    normal = new normalMonster(100, 10, weaponChoice ? new Weapon(8, 12) : nullptr);
    strong = new strongMonster(100, 10, weaponChoice ? new Weapon(8, 12) : nullptr);

    enemies = { new weakMonster(100,10,weaponChoice?new Weapon(8,12):nullptr),
        new normalMonster(100,10,nullptr) };
}

Game::Game() {

}

int Game::Run() {



    return 0;
}
