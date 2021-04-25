#include "Game.hpp"
#include "weakMonster.hpp"
#include "normalMonster.hpp"
#include "strongMonster.hpp"
#include "Player.hpp"
#include "Weapon.hpp"
#include "clearScreen.hpp"
#include <iostream>

void Game::createEntities(const short& monstersNumber) {
    enemiesNumber = monstersNumber;

    int weaponChoice = 0;
    Weapon* weapon = nullptr;
    Monster* weak, * normal, * strong;

    std::cout << "Give player a weapon?\n";
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
            weapon = new Weapon(15, 30);
            break;
        }

        default:
            std::cout << "\nInvalid input, try again: ";
        }
    }

    player = new Player(100, 15, weapon);

    std::cout << "Should enemies have weapons? Type 1 if so, or 0 otherwise: ";
    std::cin >> weaponChoice;
    while (weaponChoice < 0 || weaponChoice > 1) {
        std::cout << "Invalid input, try again: ";
        std::cin >> weaponChoice;
    }

    weak = new weakMonster(100, 10, weaponChoice ? new Weapon(8, 12) : nullptr);
    normal = new normalMonster(100, 10, weaponChoice ? new Weapon(8, 12) : nullptr);
    strong = new strongMonster(100, 10, weaponChoice ? new Weapon(8, 12) : nullptr);

    enemies = std::vector<Monster*>{ weak, normal, strong };
}

int Game::Run() {
    createEntities(3);

    clearScreen();
    int turn;
    std::cout << "Who goes first? Type 1 for player, 2 for monsters: ";
    std::cin >> turn;
    while (turn < 1 || turn > 2) {
        std::cout << "Invalid input, try again: ";
        std::cin >> turn;
    }

    while (turn == 1 || turn == 2) {
        if (turn == 1) {
            std::cout << "Player's turn. Health: " << player->getHealth() << "\n";
            if (!player->isAlive()) {
                turn = -1; // enemy wins
                break;
            }
            for (short i = 0; i < enemiesNumber; ++i) {
                Entity::TYPE t = enemies[i]->getType();
                std::cout << "Attacking " << (t == Entity::TYPE::WEAKMONSTER ? "weak " :
                    t == Entity::TYPE::NORMALMONSTER ? "normal " : "strong ") << "monster. Damage: " << player->attack(enemies[i]) << "\n";
            }
            std::cout << "\n";

            turn = 2;
        }
        else if (turn == 2) {
            bool somebodyAlive = false;
            for (short i = 0; i < enemiesNumber; ++i) {
                Entity::TYPE t = enemies[i]->getType();
                std::cout << (t == Entity::TYPE::WEAKMONSTER ? "Weak " : t == Entity::TYPE::NORMALMONSTER ? "Normal " : "Strong ") <<
                    "monster's turn. Health: " << enemies[i]->getHealth() << "\n";
                if (enemies[i]->isAlive()) {
                    somebodyAlive = true;
                    std::cout << "Attacking player. Damage: " << enemies[i]->attack(player) << "\n";
                }
            }
            std::cout << "\n";

            if (!somebodyAlive)
                turn = 0; // player wins
            else turn = 1;
        }
    }

    if (turn == -1)
        std::cout << "Enemy wins!\n\n";
    else if (turn == 0)
        std::cout << "Player wins!\n\n";

    return 0;
}

Game::~Game() {
    if (player) delete player;
    for (short i = 0; i < enemiesNumber; ++i)
        if (enemies[i]) delete enemies[i];

    enemiesNumber = 0;
}
