#pragma once
#include "MonsterCreator.hpp"
#include "WeakMonster.hpp"

class WeakMonsterCreator : public MonsterCreator {
public:
    Monster* createMonster(const short& h, const short& d, Weapon* w) const { return new WeakMonster(h, d, w); }
};
