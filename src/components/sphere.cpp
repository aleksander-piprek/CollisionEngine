#include "../../include/sphere.hpp"

Sphere::Sphere()
{
    shape.setRadius(radius);
    shape.setFillColor(sf::Color(color.red, 
                                 color.green, 
                                 color.blue, 
                                 color.opacity));    
    setInitialPosition(position.initial);
}

void Sphere::updatePosition(float dt)
{
    velocity = position.current - position.previous;

    position.previous = position.current;

    position.current = position.current + velocity + acceleration * dt * dt;

    shape.setPosition(position.current);
    
    acceleration = {};
}

void Sphere::setInitialPosition(sf::Vector2f newPosition)
{
    position.current = position.initial;

    position.previous = newPosition;

    shape.setPosition(newPosition);
}

void Sphere::accelerate(sf::Vector2f acc)
{
    acceleration += acc;
}