#include <iostream>
#include "pch.h"

int main() {
    Player *p = new Player(1,1,nullptr);
    Monster* monsters = { new weakMonster(1,1,nullptr) };
    monsters[0].attack(p);
}
