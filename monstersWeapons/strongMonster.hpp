#pragma once
#include "Monster.hpp"

class strongMonster :public Monster {
public:
    strongMonster(const int& h, const int& d, Weapon* w) : Monster(h, d, w, STRONGMONSTER) {}
    int attack(Entity*);
};
