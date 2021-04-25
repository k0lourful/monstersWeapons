#pragma once
class Weapon;

class Entity {
public:
    enum TYPE { PLAYER, WEAKMONSTER, NORMALMONSTER, STRONGMONSTER };

protected:
    int health;
    int damage;
    Weapon* weapon;
    TYPE type;

public:
    Entity(const int& h, const int& d, Weapon* w, const TYPE& t) : health(h), damage(d), weapon(w), type(t) {}
    ~Entity() { if (weapon) delete weapon; }

    TYPE getType() const { return type; }
    int getHealth() const { return health; }
    bool isAlive() const { return health > 0; }
    void reduceHealth(const int& dmg) { health -= dmg; }
    virtual int attack(Entity*) = 0;
};
