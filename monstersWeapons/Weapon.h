#pragma once

class Weapon {
    int damage;
    int durability;

public:
    Weapon(int d, int dur) : damage(d), durability(dur) {}
    int getDamage() const { return damage; }
    int getDurability() const { return durability; }
    int reduceDurability(const int& dmg);
};
