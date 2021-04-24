#include "Player.hpp"
#include "Weapon.hpp"

int Player::attack(Entity* monster) {
    int dealtDmg = 0;
    if (weapon) {
        dealtDmg = damage + 0.5 * weapon->getDamage();
        weapon->reduceDurability(3);
        if (!weapon->getDurability()) {
            delete weapon;
            weapon = nullptr;
        }
    }
    else
        dealtDmg = 0.8 * damage;

    monster->reduceHealth(dealtDmg);

    return dealtDmg;
}
