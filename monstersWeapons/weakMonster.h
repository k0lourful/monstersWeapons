#pragma once
#include "Monster.h"

class weakMonster : public Monster {
public:
    weakMonster(int h, int d, Weapon* w) : Monster(h, d, w) {};
    int attack(Entity*) {};
};
