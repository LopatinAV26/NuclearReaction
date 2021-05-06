#include "Fuel.h"

Fuel::Fuel(int x, int y) {
    fuelShape.setSize(sf::Vector2f(x, y));
    fuelShape.setFillColor(sf::Color::Yellow);
    fuelShape.setOrigin(x / 2, y / 2);
}

void Fuel::update(sf::Time deltaTime) {
    period += deltaTime.asSeconds();
}

//Эмиссия нейтронов. Функция возвращает указатель!
Neutron *Fuel::emission() {
    Neutron *neutronElement = new Neutron;
    return neutronElement;
}
//////////////////////////////////////////////////////////////////////////
void Fuel::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(fuelShape, states);
}




