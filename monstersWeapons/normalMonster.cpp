#include "NormalMonster.hpp"
#include "Weapon.hpp"

short NormalMonster::attack(Entity* player) {
    short dealtDmg = 0;
    if (weapon) {
        dealtDmg = short(0.8 * damage + 0.5 * weapon->getDamage());
        weapon->reduceDurability(4);
        if (weapon->getDurability() <= 0) {
            delete weapon;
            weapon = nullptr;
        }
    }
    else
        dealtDmg = short(0.6 * damage);

    player->reduceHealth(dealtDmg);

    return dealtDmg;
}
