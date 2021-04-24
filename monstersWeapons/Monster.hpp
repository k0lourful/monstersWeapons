#pragma once
#include "Entity.hpp"

class Monster :public Entity {
public:
    Monster(const int& h, const int& d, Weapon* w) : Entity(h, d, w) {}
    virtual int attack(Entity*) = 0;
};
