#pragma once
class Player;
class Monster;

class Game {
private:
    Player* player;
    Monster* enemies;

    void createEntities();

public:
    Game();
    int Run();

};
