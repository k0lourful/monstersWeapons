#pragma once
#include "Monster.hpp"

class strongMonster :public Monster {
public:
    strongMonster(const int& h, const int& d, Weapon* weapon) : Monster(h, d, w) {}
    int attack(Entity*);
};
