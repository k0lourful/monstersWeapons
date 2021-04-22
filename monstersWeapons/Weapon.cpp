#include "Weapon.h"

int Weapon::reduceDurability(const int& dmg) {
    durability -= dmg;
    return durability;
}
