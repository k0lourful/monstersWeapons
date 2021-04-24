#pragma once
#include "Entity.hpp"
class Weapon;

class Player: public Entity {
public:
    Player(const int& h, const int& d, Weapon* w) : Entity(h,d,w) {}
    int attack(Entity* monster);
};
