#include "weakMonster.hpp"
#include "Weapon.hpp"

int weakMonster::attack(Entity* player) {
    int dealtDmg = 0;
    if (weapon) {
        dealtDmg = 0.4 * damage + 0.5*weapon->getDamage();
        weapon->reduceDurability(5);
        if (weapon->getDurability() <= 0) {
            delete weapon;
            weapon = nullptr;
        }
    }
    else 
        dealtDmg = 0.3 * damage;

    player->reduceHealth(dealtDmg);

    return dealtDmg;
}
