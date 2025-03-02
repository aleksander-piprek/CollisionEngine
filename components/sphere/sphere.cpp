#include "sphere.hpp"

Sphere::Sphere()
{
    shape.setRadius(radius);
    shape.setFillColor(sf::Color(color.red, 
                                 color.green, 
                                 color.blue, 
                                 color.opacity));    
    setInitialPosition(position.initial);
    setInitialAcceleration(acceleration.initial);
}

void Sphere::updatePosition(float dt)
{
    velocity = position.current - position.previous;

    position.previous = position.current;

    position.current = position.current + velocity + acceleration.current * dt * dt;

    shape.setPosition(position.current);
    
    // std::cout << "Position = x: " << position.current.x << "y: " << position.current.y << std::endl; 
    std::cout << velocity.x << " " << velocity.y << "\n";
    acceleration.current = {};
}

void Sphere::setInitialPosition(sf::Vector2f newPosition)
{
    position.current = position.initial;

    position.previous = newPosition;

    shape.setPosition(newPosition);
}

void Sphere::setInitialAcceleration(sf::Vector2f initialAcceleration)
{
    accelerate(acceleration.initial);
}

void Sphere::accelerate(sf::Vector2f acc)
{
    acceleration.current += acc;
}