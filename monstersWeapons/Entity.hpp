#pragma once
class Weapon;

class Entity {
protected:
    int health;
    int damage;
    Weapon* weapon;

public:
    Entity(const int& h, const int& d, Weapon* w) : health(h), damage(d), weapon(w) {}
    ~Entity() { if (weapon) delete weapon; }

    void reduceHealth(const int& dmg) { health -= dmg; }
    virtual int attack(Entity*) = 0;
};
