#include "Player.hpp"
#include "Weapon.hpp"

short Player::attack(Entity* monster) {
    short dealtDmg = 0;
    if (weapon) {
        dealtDmg = short(damage + 0.5 * weapon->getDamage());
        weapon->reduceDurability(3);
        if (weapon->getDurability() <= 0) {
            delete weapon;
            weapon = nullptr;
        }
    }
    else
        dealtDmg = short(0.8 * damage);

    monster->reduceHealth(dealtDmg);

    return dealtDmg;
}
