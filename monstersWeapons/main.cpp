#include "pch.h"

int main() {
    Game game;
    int retCode = game.Run();
    if (!retCode)
        std::cout << "Game shut down incorrectly. Error code: " << retCode << "\n\n";

    return 0;
}
