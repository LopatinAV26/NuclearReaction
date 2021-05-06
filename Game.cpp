#include "Game.h"

Game::Game(sf::ContextSettings settings, int width, int height)
    : window(sf::VideoMode(width, height, 8), "Nuclear", sf::Style::Default, settings) {
    // window.setFramerateLimit(60);
    font.loadFromFile("Natural Mono Alt Regular.ttf");
    text.setFont(font);
    text.setCharacterSize(12);
    text.setPosition(0, 0);
}
////////////////////////////////////////////
void Game::run(int minimumFramePerSeconds) {

    sf::Time timeSinceLastUpdate;
    sf::Time timePerFrame = sf::seconds(1.f / minimumFramePerSeconds);

    while(window.isOpen()) {
//Информация на экране-------------------------------------------------------------------------
    period += timeSinceLastUpdate.asSeconds();
    if(period >= 0.3) {
        
        string = "FPS " + std::to_string(static_cast<int>(1.f / timeSinceLastUpdate.asSeconds()));
        string += "\nfuel count " + std::to_string(scene.fuelArray.size());
        string += "\nneutronArray capacity " + std::to_string(scene.neutronArray.capacity());
        string += "\nneutron count " + std::to_string(scene.neutronArray.size());
        text.setString(string);
    
        period = 0;
    }
        
//-------------------------------------------------

        processEvents();

        timeSinceLastUpdate = clock.restart();

        while(timeSinceLastUpdate > timePerFrame) {
            timeSinceLastUpdate -= timePerFrame;
            update(timePerFrame);
        }

        update(timeSinceLastUpdate);
        render();
    }
}
//Обработка событий---------
void Game::processEvents() {
    sf::Event event;
    while(window.pollEvent(event)) {
        if((event.type == sf::Event::Closed)
                or ((event.type == sf::Event::KeyPressed)
                    and (event.key.code == sf::Keyboard::Escape))) {
            window.close();
        }
        scene.processEvents(event, window);
    }
}
////////////////////////////////////////
void Game::update(sf::Time deltaTime) {
    scene.update(deltaTime);
}
///////////////////////
void Game::render() {
    window.clear();
    window.draw(scene);
    window.draw(text);
    window.display();
}

