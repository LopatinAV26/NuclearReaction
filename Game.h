#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Scene.h"
#include <cmath>

/**
 * @todo write docs
 */
class Game {
public:
    //Game(const Game &) = delete;
    //Game &operator= (const Game &) = delete;
    Game(sf::ContextSettings settings, int width = 640, int height = 360);

    void run(int minimumFramePerSeconds = 1);
private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    sf::RenderWindow window;
    Scene scene;
    sf::Clock clock;
    float period = 0;
    std::string string;
    sf::Font font;
    sf::Text text;
    
};

#endif // GAME_H

