#ifndef FUEL_H
#define FUEL_H

#include <SFML/Graphics.hpp>
#include "Neutron.h"    //для эмиссии нейтронов

/**
 * @todo write docs
 */
class Fuel : public sf::Drawable {
public:
    Fuel(int x = 6, int y = 6);
    Neutron *emission();

    void update(sf::Time deltaTime);
    //Переменная stаtic не может быть инициализирована
    //внутри класса, а static const может
    
    
    float period{0};
    sf::RectangleShape fuelShape;
private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;


};

#endif // FUEL_H

