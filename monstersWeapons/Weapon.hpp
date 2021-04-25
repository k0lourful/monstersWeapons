#pragma once

class Weapon {
    short damage;
    short durability;

public:
    Weapon(const short& dmg, const short& dur) : damage(dmg), durability(dur) {}
    short getDamage() const { return damage; }
    short getDurability() const { return durability; }
    short reduceDurability(const short& dmg) { return durability -= dmg; }
};
