#pragma once
#include "Monster.h"

class weakMonster : public Monster {
public:
    weakMonster(const int& h, const int& d, Weapon* w) : Monster(h, d, w) {}
    int attack(Entity*);
};