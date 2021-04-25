#include "Game.hpp"
#include "WeakMonsterCreator.hpp"
#include "NormalMonsterCreator.hpp"
#include "StrongMonsterCreator.hpp"
#include "Player.hpp"
#include <iostream>
#include <random>
using std::cout;
using std::cin;

void Game::chooseDifficulty() {
    cout << "Choose difficulty:\n"
        "1 - Normal\n"
        "2 - Hard\n";
    cin >> difficulty;
    while (difficulty < 1 || difficulty > 3) {
        cout << "Invalid input, try again: ";
        cin >> difficulty;
    }
}

void Game::randomiseMonsters() {
    std::random_device dev;
    std::mt19937 engine(dev());
    std::uniform_int_distribution<int> uid(0, 100);

    switch (difficulty) {
    case 1: {
        enemiesNumber = 5 - int(uid(engine) / 25);
        MonsterCreator* creator;

        for (short i = 0; i < enemiesNumber; ++i) {
            short probability = uid(engine);
            if (probability > 60)
                creator = new WeakMonsterCreator;
            else if (probability > 5 && probability <= 60)
                creator = new NormalMonsterCreator;
            else creator = new StrongMonsterCreator;

            short health, damage;
            Weapon* weapon = nullptr;

            probability = uid(engine);
            if (probability > 70) {
                health = probability / 3;
                damage = probability / 8;
            }
            else if (probability > 15 && probability <= 70) {
                health = 30 + probability / 5;
                damage = 14 + probability / 10;
            }
            else {
                health = 45 + probability / 3;
                damage = 18 + probability / 2;
            }

            probability = uid(engine);
            if (probability <= 10) {
                short weaponDamage, durability;
                probability = uid(engine);
                if (probability > 30) {
                    weaponDamage = probability / 10;
                    durability = 5 + probability / 10;
                }
                weapon = new Weapon(weaponDamage, durability);
            }

            enemies.push_back(creator->createMonster(health, damage, weapon));
        }
        break;
    }

    case 2: {
        enemiesNumber = 10 - int(uid(engine) / 25);
        MonsterCreator* creator;

        for (short i = 0; i < enemiesNumber; ++i) {
            short probability = uid(engine);
            if (probability > 80)
                creator = new WeakMonsterCreator;
            else if (probability > 25 && probability <= 80)
                creator = new NormalMonsterCreator;
            else creator = new StrongMonsterCreator;

            short health, damage;
            Weapon* weapon = nullptr;

            probability = uid(engine);
            if (probability > 70) {
                health = int(probability / 2.5);
                damage = probability / 6;
            }
            else if (probability > 15 && probability <= 70) {
                health = 38 + probability / 5;
                damage = 16 + probability / 10;
            }
            else {
                health = 50 + probability / 3;
                damage = 24 + probability / 2;
            }

            probability = uid(engine);
            if (probability <= 10) {
                short weaponDamage, durability;
                probability = uid(engine);
                if (probability > 30) {
                    weaponDamage = probability / 10;
                    durability = 5 + probability / 10;
                }
                weapon = new Weapon(weaponDamage, durability);
            }

            enemies.push_back(creator->createMonster(health, damage, weapon));
        }
        break;
    }
    }
}

void Game::initEntities() {
    randomiseMonsters();

    short weaponChoice = 0;
    Weapon* weapon = nullptr;

    cout << "Give player a weapon?\n"
        "1. None\n"
        "2. Bat\n"
        "3. Sword\n";

    while (weaponChoice < 1 || weaponChoice > 3) {
        cin >> weaponChoice;

        switch (weaponChoice) {
        case 1:
            break;

        case 2: {
            weapon = new Weapon(10, 30);
            break;
        }

        case 3: {
            weapon = new Weapon(20, 50);
            break;
        }

        default:
            cout << "Invalid input, try again: ";
        }
    }

    player = new Player(100, 15, weapon);
}

short Game::Run() {
    chooseDifficulty();
    initEntities();

    short turn;
    cout << "Who goes first?\n"
        "1 - Player\n"
        "2 - Monsters\n";
    cin >> turn;
    while (turn < 1 || turn > 2) {
        cout << "Invalid input, try again: ";
        cin >> turn;
    }

    while (turn == 1 || turn == 2) {
        if (turn == 1) {
            cout << "Player's turn. Health: " << player->getHealth() << "\n";
            if (!player->isAlive()) {
                turn = -1; // enemy wins
                break;
            }
            for (short i = 0; i < enemiesNumber; ++i) {
                Entity::TYPE t = enemies[i]->getType();
                cout << "Attacking " << (t == Entity::TYPE::WEAKMONSTER ? "weak " :
                    t == Entity::TYPE::NORMALMONSTER ? "normal " : "strong ") << "monster. Damage: " << player->attack(enemies[i]) << "\n";
            }
            cout << "\n";

            turn = 2;
        }
        else if (turn == 2) {
            bool somebodyAlive = false;
            for (short i = 0; i < enemiesNumber; ++i) {
                Entity::TYPE t = enemies[i]->getType();
                cout << (t == Entity::TYPE::WEAKMONSTER ? "Weak " : t == Entity::TYPE::NORMALMONSTER ? "Normal " : "Strong ") <<
                    "monster's turn. Health: " << enemies[i]->getHealth() << "\n";
                if (enemies[i]->isAlive()) {
                    somebodyAlive = true;
                    cout << "Attacking player. Damage: " << enemies[i]->attack(player) << "\n";
                }
            }
            cout << "\n";

            if (!somebodyAlive)
                turn = 0; // player wins
            else turn = 1;
        }
    }

    if (turn == -1)
        cout << "Enemy wins!\n\n";
    else if (turn == 0)
        cout << "Player wins!\n\n";

    return 0;
}

Game::~Game() {
    if (player) delete player;
    for (short i = 0; i < enemiesNumber; ++i)
        if (enemies[i]) delete enemies[i];

    enemiesNumber = 0;
}
