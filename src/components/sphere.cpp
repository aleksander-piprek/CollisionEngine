#include "../../include/sphere.hpp"

Sphere::Sphere()
    : radius(radius), 
      color(color)
{
    shape.setRadius(radius);
    shape.setFillColor(sf::Color(color.red, 
                                 color.green, 
                                 color.blue, 
                                 color.opacity));    
    setInitialPosition(initialPosition);                                 
}

void Sphere::updatePosition(float dt)
{
    velocity = positionCurrent - positionOld;
    // Save current position
    positionOld = positionCurrent;
    // Verlet integration
    positionCurrent = positionCurrent + velocity + acceleration * dt * dt;

    shape.setPosition(positionCurrent);
    // Reset acceleration
    acceleration = {};
}

void Sphere::setInitialPosition(sf::Vector2f newPosition)
{
    positionCurrent = initialPosition;
    positionOld = newPosition;
    shape.setPosition(newPosition);
}

void Sphere::accelerate(sf::Vector2f acc)
{
    acceleration += acc;
}