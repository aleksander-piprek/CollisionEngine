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

    // logObject();

    acceleration.current = {};
}

void Sphere::logObject()
{
    std::cout << "Object "<< id << std::endl;
    std::cout << "  Position " 
              << "      x: " << position.current.x 
              << "          y: " << position.current.y << std::endl; 
    std::cout << "  Velocity " 
              << "      x: " << velocity.x 
              << "            y: " << velocity.y << std::endl; 
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

void Sphere::setPosition(sf::Vector2f pos)
{
    object1position.current = pos;
}

void Sphere::accelerate(sf::Vector2f acc)
{
    this->acceleration.current += acc;
}