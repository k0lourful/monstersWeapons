#include "StrongMonster.hpp"
#include "Weapon.hpp"

short StrongMonster::attack(Entity* player) {
    short dealtDmg = 0;
    if (weapon) {
        dealtDmg = short(damage + 0.5 * weapon->getDamage());
        weapon->reduceDurability(2);
        if (weapon->getDurability() <= 0) {
            delete weapon;
            weapon = nullptr;
        }
    }
    else
        dealtDmg = damage;

    player->reduceHealth(dealtDmg);

    return dealtDmg;
}
