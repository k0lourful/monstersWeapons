#pragma once
#include <vector>
class Player;
class Monster;

class Game {
private:
    int enemiesNumber;
    Player* player;
    std::vector<Monster*> enemies;

    void createEntities(const short& monstersNumber);

public:
    ~Game();
    int Run();

};
