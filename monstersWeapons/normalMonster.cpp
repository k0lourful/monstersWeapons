#include "normalMonster.h"
#include "Weapon.h"

int normalMonster::attack(Entity* player) {
    int dealtDmg = 0;
    if (weapon) {
        dealtDmg = 0.8 * damage + 0.5 * weapon->getDamage();
        weapon->reduceDurability(4);
        if (!weapon->getDurability()) {
            delete weapon;
            weapon = nullptr;
        }
    }
    else
        dealtDmg = 0.6 * damage;

    player->reduceHealth(dealtDmg);

    return dealtDmg;
}
