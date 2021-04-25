#pragma once
#include "Monster.hpp"

class WeakMonster : public Monster {
public:
    WeakMonster(const short& h, const short& d, Weapon* w) : Monster(h, d, w, TYPE::WEAKMONSTER) {}
    short attack(Entity*);
};
