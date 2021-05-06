#include <iostream>
#include "Game.h"

int main(int argc, char *argv[]) {

    sf::ContextSettings settings;
    settings.antialiasingLevel = 0;

    Game game(settings);
    game.run();
}
