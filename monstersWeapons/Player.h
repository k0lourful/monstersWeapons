#pragma once
#include "Entity.h"
class Weapon;

class Player: public Entity {
public:
    Player(const int& h, const int& d, Weapon* w) : Entity(h,d,w) {}
    int attack(Entity* monster);
};
