#include "WeakMonster.hpp"
#include "Weapon.hpp"

short WeakMonster::attack(Entity* player) {
    short dealtDmg = 0;
    if (weapon) {
        dealtDmg = short(0.4 * damage + 0.5*weapon->getDamage());
        weapon->reduceDurability(5);
        if (weapon->getDurability() <= 0) {
            delete weapon;
            weapon = nullptr;
        }
    }
    else 
        dealtDmg = short(0.3 * damage);

    player->reduceHealth(dealtDmg);

    return dealtDmg;
}
