#include "strongMonster.hpp"
#include "Weapon.hpp"

int strongMonster::attack(Entity* player) {
    int dealtDmg = 0;
    if (weapon) {
        dealtDmg = damage + 0.5 * weapon->getDamage();
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
