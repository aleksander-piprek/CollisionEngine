#include "../../include/sphere.hpp"

Sphere::Sphere()
{
    shape.setRadius(radius);
    shape.setFillColor(sf::Color(color.red, 
                                 color.green, 
                                 color.blue, 
                                 color.opacity));    
    setInitialPosition(position.initial);
    accelerate(acceleration.initial);

    text.setFont(font);
    text.setString("Hello world");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Yellow);
    // text.setStyle(sf::Text::Bold);
}

void Sphere::updatePosition(float dt)
{
    velocity = position.current - position.previous;

    position.previous = position.current;

    position.current = position.current + velocity + acceleration.current * dt * dt;

    shape.setPosition(position.current);
    
    std::cout << "Position = x: " << position.current.x << "y: " << position.current.y << std::endl; 

    acceleration.current = {};
}

void Sphere::setInitialPosition(sf::Vector2f newPosition)
{
    position.current = position.initial;

    position.previous = newPosition;

    shape.setPosition(newPosition);
}

void Sphere::accelerate(sf::Vector2f acc)
{
    acceleration.current += acc;
}

// sf::Vector2f Sphere::applyForces()
// {

// }