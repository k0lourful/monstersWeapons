#pragma once
#include "MonsterCreator.hpp"
#include "StrongMonster.hpp"

class StrongMonsterCreator : public MonsterCreator {
public:
    Monster* createMonster(const short& h, const short& d, Weapon* w) const { return new StrongMonster(h, d, w); }
};
