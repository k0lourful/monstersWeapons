#include "strongMonster.h"
#include "Weapon.h"

int strongMonster::attack(Entity* player) {
    int dealtDmg = 0;
    if (weapon) {
        dealtDmg = damage + 0.5 * weapon->getDamage();
        weapon->reduceDurability(2);
        if (!weapon->getDurability()) {
            delete weapon;
            weapon = nullptr;
        }
    }
    else
        dealtDmg = damage;

    player->reduceHealth(dealtDmg);

    return dealtDmg;
}
