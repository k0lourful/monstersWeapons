#pragma once
#include "Monster.hpp"

class StrongMonster :public Monster {
public:
    StrongMonster(const short& h, const short& d, Weapon* w) : Monster(h, d, w, TYPE::STRONGMONSTER) {}
    short attack(Entity*);
};
