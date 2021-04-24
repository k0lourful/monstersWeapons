#pragma once
#include "Monster.hpp"

class normalMonster : public Monster {
public:
    normalMonster(const int& h, const int& d, Weapon* w) : Monster(h, d, w) {}
    int attack(Entity*);
};

