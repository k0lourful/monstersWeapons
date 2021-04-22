#pragma once
class Weapon;

class Entity {
protected:
    int health;
    int damage;
    Weapon* weapon;

public:
    Entity(int h, int d, Weapon* w) : health(h), damage(d), weapon(w) {}
    virtual int attack(Entity*) = 0;
};
