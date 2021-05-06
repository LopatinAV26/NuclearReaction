#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>
#include "Fuel.h"
#include "Neutron.h"

/**
 * Класс управляет созданием и уничтожением сущностей,
 * добавляет их на сцену,
 * проверяет столкновения,
 * убирает со сцены
 */
class Scene : public sf::Drawable {
public:
    void add(Fuel *element);
    void add(Neutron *element);

    template<typename T>
    inline void clear(T &iter);

    void processEvents(sf::Event event, sf::RenderWindow &window);
    void update(sf::Time deltaTime);

    inline bool collision(const sf::RectangleShape &first, sf::RectangleShape &second);

    std::vector<Fuel>fuelArray;
    std::vector<Neutron>neutronArray;
    Fuel fuel;

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif // SCENE_H
