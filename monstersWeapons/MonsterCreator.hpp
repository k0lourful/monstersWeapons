#pragma once
class Monster;
class Weapon;

class MonsterCreator {
public:
    virtual Monster* createMonster(const short&, const short&, Weapon*) const = 0;
};
