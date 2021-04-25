#pragma once
#include "MonsterCreator.hpp"
#include "NormalMonster.hpp"

class NormalMonsterCreator : public MonsterCreator {
public:
    Monster* createMonster(const short& h, const short& d, Weapon* w) const { return new NormalMonster(h, d, w); }
};
