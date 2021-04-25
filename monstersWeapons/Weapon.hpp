#pragma once

class Weapon {
    int damage;
    int durability;

public:
    Weapon(const int& dmg, const int& dur) : damage(dmg), durability(dur) {}
    int getDamage() const { return damage; }
    int getDurability() const { return durability; }
    int reduceDurability(const int& dmg) { return durability -= dmg; }
};
