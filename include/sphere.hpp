#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "window.hpp"

class Sphere
{
    public:
        Sphere();
        void updatePosition(float dt);
        void setInitialPosition(sf::Vector2f newPosition);
        void accelerate(sf::Vector2f acc);

        // Custom shape
        sf::CircleShape shape; 
        int radius;
        struct 
        {
            sf::Uint8 red = 255;
            sf::Uint8 green = 0;
            sf::Uint8 blue = 255;
            sf::Uint8 opacity = 255;
        } color;   

        struct 
        {
            sf::Vector2f initial {400.0f, 100.0f};
            sf::Vector2f current;
            sf::Vector2f previous;
        } position;

        sf::Vector2f velocity;

        sf::Vector2f acceleration;
};

#endif