#pragma once
#include <vector>
class Player;
class Monster;

class Game {
private:
    short enemiesNumber;
    short difficulty;
    Player* player;
    std::vector<Monster*> enemies;

    void chooseDifficulty();
    void randomiseMonsters();
    void initEntities();

public:
    ~Game();
    short Run();
};
