#include "Particle.h"

Particle::Particle(unsigned int count):
    structVector(count),
    vertexArray(sf::Points, count),
    m_lifetime(sf::seconds(3.f)),
    m_emitter(0.f, 0.f) {
}

void Particle::update(sf::Time deltaTime) {
    for(std::size_t i = 0; i < structVector.size(); ++i) {
        // update the particle lifetime
        Vertex &p = structVector[i];
        p.lifetime -= deltaTime;

        // if the particle is dead, respawn it
        if(p.lifetime <= sf::Time::Zero)
            resetParticle(i);

        // update the position of the corresponding vertex
        vertexArray[i].position += p.velocity * deltaTime.asSeconds();

        // update the alpha (transparency) of the particle according to its lifetime
        float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
        vertexArray[i].color.a = static_cast<sf::Uint8>(ratio * 255);
    }
}

void Particle::resetParticle(std::size_t index) {
    // give a random velocity and lifetime to the particle
    float angle = (std::rand() % 360) * 3.14f / 180.f;
    float speed = (std::rand() % 50) + 50.f;
    structVector[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
    structVector[index].lifetime = sf::milliseconds((std::rand() % 2000) + 1000);

    // reset the position of the corresponding vertex
    vertexArray[index].position = m_emitter;
}



