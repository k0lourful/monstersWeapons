#pragma once
#include "Monster.hpp"

class weakMonster : public Monster {
public:
    weakMonster(const int& h, const int& d, Weapon* w) : Monster(h, d, w, WEAKMONSTER) {}
    int attack(Entity*);
};
