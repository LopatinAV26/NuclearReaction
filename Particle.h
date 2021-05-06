#ifndef PARTICLE_H
#define PARTICLE_H

#include <cmath>
#include <SFML/Graphics.hpp>

/**
 * @todo write docs
 */
class Particle : public sf::Drawable, public sf::Transformable {
public:
    Particle(unsigned int count = 10000);

    void setEmitter(sf::Vector2f position) {
        m_emitter = position;
    }
    void update(sf::Time deltaTime);

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
        // apply the transform
        states.transform *= getTransform();

        // our particles don't use a texture
        states.texture = NULL;

        // draw the vertex array
        target.draw(vertexArray, states);
    }

    struct Vertex {
        sf::Vector2f velocity;
        sf::Time lifetime;
    };

    void resetParticle(std::size_t index);

    std::vector<Vertex> structVector;
    sf::VertexArray vertexArray;
    sf::Time m_lifetime;
    sf::Vector2f m_emitter;
};

#endif // PARTICLE_H

