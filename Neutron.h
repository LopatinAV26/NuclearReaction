#ifndef NEUTRON_H
#define NEUTRON_H

#include <cmath>
#include <SFML/Graphics.hpp>

/**
 * @todo write docs
 */
class Neutron : public sf::Drawable {
public:
    Neutron(int x = 1, int y = 1);

    void update(sf::Time deltaTime);

    bool colliding {false};                     //сталкиваемость частицы
    bool isAlive {true};                        //жива ли частица

    sf::RectangleShape neutronShape;

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    float path {0};                             //путь, пройденый частицей
    float lifePath = (rand() % 200) + 200.f;    //путь, на протяжении которго частица жива
    float speed {50};                          //скорость частицы
    float angle = (rand() % 360) * M_PI / 180;  //диапазон углов полёта частицы (360)
};

#endif // NEUTRON_H
