#include "Scene.h"

void Scene::add(Fuel *element) {
    fuelArray.push_back(*element);
}
/////////////////////////////////////////
void Scene::add(Neutron *element) {
    neutronArray.push_back(*element);
}
/////////////////////////////////////////
template<typename T>
void Scene::clear(T &iter) {
    neutronArray.erase(neutronArray.begin() + iter);
}

/////////////////////////////////////////
void Scene::processEvents(sf::Event event, sf::RenderWindow &window) {
    if(event.type == sf::Event::MouseButtonPressed) {
        if(event.mouseButton.button == sf::Mouse::Left) {
            Fuel *fuelElement = new Fuel;
            fuelElement->fuelShape.setPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
            add(std::move(fuelElement));
            delete fuelElement;
        }
        else if(event.type == sf::Event::MouseButtonPressed) {
            if(event.mouseButton.button == sf::Mouse::Right) {

            }
            else if(event.type == sf::Event::MouseButtonPressed) {
                if(event.mouseButton.button == sf::Mouse::Middle) {

                }
            }
        }
    }
}
////////////////////////////////////////
void Scene::update(sf::Time deltaTime) {
    for(int i = 0; i < fuelArray.size(); ++i) {
        fuelArray[i].update(deltaTime);
        if(fuelArray[i].period > 1) {
            for(int count = 0; count < ((rand() % 1) + 2); ++count) {
                Neutron *neutronElement = new Neutron;
                neutronElement->neutronShape.setPosition(sf::Vector2f(fuelArray[i].fuelShape.getPosition()));
                add(neutronElement);
                delete neutronElement;
                fuelArray[i].period = 0;
            }
        }
    }
    for(int it = 0; it < neutronArray.size(); ++it) {
        neutronArray[it].update(deltaTime);
        if(!neutronArray[it].isAlive) {
            clear(it);
        }
    }
    for(int fIt = 0; fIt < fuelArray.size(); ++fIt) {
         for(int nIt = 0; nIt < neutronArray.size(); ++nIt) {
             if(neutronArray[nIt].colliding && neutronArray[nIt].isAlive) {
                 if(collision(fuelArray[fIt].fuelShape, neutronArray[nIt].neutronShape)) {
                     neutronArray[nIt].isAlive = false;
                     for(int count = 0; count < ((rand() % 1) + 2); ++count) {
                         Neutron *neutronElement = new Neutron;
                         neutronElement->neutronShape.setPosition(sf::Vector2f(fuelArray[fIt].fuelShape.getPosition()));
                         add(neutronElement);
                         delete neutronElement;
                     }
                 }
             }
         }
     }
}
///////////////////////////////////////////////////////////////////////////////////
bool Scene::collision(const sf::RectangleShape &first, sf::RectangleShape &second) {
    if(first.getGlobalBounds().intersects(second.getGlobalBounds()))
        return true;
    return false;
}
//////////////////////////////////////////////////////////////////////////
void Scene::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(auto &it : neutronArray) {
        target.draw(it);
    }
    for(auto &it : fuelArray) {
        target.draw(it);
    }
}
