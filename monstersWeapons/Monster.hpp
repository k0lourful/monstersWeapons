#pragma once
#include "Entity.hpp"

class Monster :public Entity {
public:
    Monster(const int& h, const int& d, Weapon* w, const TYPE& t) : Entity(h, d, w, t) {}
    virtual int attack(Entity*) = 0;
};
