#pragma once
#include "Weapon.hpp"

class Entity {
public:
    enum class TYPE { PLAYER, WEAKMONSTER, NORMALMONSTER, STRONGMONSTER };

protected:
    short health;
    short damage;
    Weapon* weapon;
    TYPE type;

public:
    Entity(const short& h, const short& d, Weapon* w, const TYPE& t) : health(h), damage(d), weapon(w), type(t) {}
    ~Entity() { if (weapon) delete weapon; }

    TYPE getType() const { return type; }
    short getHealth() const { return health; }
    bool isAlive() const { return health > 0; }
    void reduceHealth(const short& dmg) { health -= dmg; }
    virtual short attack(Entity*) = 0;
};
