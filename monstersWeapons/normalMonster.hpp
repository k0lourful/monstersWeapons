#pragma once
#include "Monster.hpp"

class NormalMonster : public Monster {
public:
    NormalMonster(const short& h, const short& d, Weapon* w) : Monster(h, d, w, TYPE::NORMALMONSTER) {}
    short attack(Entity*);
};
