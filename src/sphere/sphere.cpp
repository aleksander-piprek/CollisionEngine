#include "sphere.hpp"
#include <math.h>

Sphere::Sphere()
{
    shape.setRadius(radius);
    shape.setFillColor(sf::Color(0, 255, 0));    
    setInitialPosition(position.initial);
    setInitialAcceleration(acceleration.initial);
}

void Sphere::updatePosition(float dt)
{
    velocity = position.current - position.previous;

    position.previous = position.current;

    position.current = position.current + velocity + acceleration.current * dt * dt;

    shape.setPosition(position.current);

    // logObject();

    acceleration.current = {};
}

void Sphere::logObject()
{
    float instantaneousVelocity = std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
    std::cout << "Object "<< id << std::endl;
    std::cout << "  Position " 
              << "      x: " << position.current.x 
              << "          y: " << position.current.y << std::endl; 
    std::cout << "  Velocity       " 
              << instantaneousVelocity << std::endl; 
    std::cout << "  Acceleration " 
              << "  x: " << acceleration.current.x 
              << "            y: " << acceleration.current.y << std::endl; 

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