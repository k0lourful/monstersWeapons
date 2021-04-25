#pragma once
#include "Entity.hpp"

class Monster :public Entity {
public:
    Monster(const short& h, const short& d, Weapon* w, const TYPE& t) : Entity(h, d, w, t) {}
    virtual short attack(Entity*) = 0;
};
