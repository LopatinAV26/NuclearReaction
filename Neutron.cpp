#include "Neutron.h"

Neutron::Neutron(int x, int y) {
    neutronShape.setSize(sf::Vector2f(x, y));
    neutronShape.setFillColor(sf::Color(255, 0, 0, 255));
}
////////////////////////////////////////////////
void Neutron::update(sf::Time deltaTime) {
    float time = deltaTime.asSeconds();
    neutronShape.move(sf::Vector2f(std::cos(angle), std::sin(angle)) * speed * time);
    path += speed * time;
    //если путь больше 10, частица становится сталкиваемой
    //неоходимо для того, чтобы она успела выйти за пределы
    //своего эмиттера. Значение должно быть больше максимального
    //значения эмиттера
    if(path > 10)
        colliding = true;
    //смерть частицы после прохождения lifePath
    if(path > lifePath)
        isAlive = false;
}
//////////////////////////////////////////////////////////////////////////////
void Neutron::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(neutronShape, states);
}
