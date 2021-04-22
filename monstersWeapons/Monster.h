#pragma once
#include "Entity.h"

class Monster :public Entity {
public:
    Monster(int h, int d, Weapon* w) : Entity(h, d, w) {}
    virtual int attack(Entity*) = 0;
};
