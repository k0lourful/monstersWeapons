#pragma once
#include "Entity.hpp"
class Weapon;

class Player: public Entity {
public:
    Player(const short& h, const short& d, Weapon* w) : Entity(h,d,w, TYPE::PLAYER) {}
    short attack(Entity* monster);
};
