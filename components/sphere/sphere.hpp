#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../window/window.hpp"

class Sphere
{
    public:
        Sphere();
        void updatePosition(float dt);
        void setInitialPosition(sf::Vector2f newPosition);
        void setInitialAcceleration(sf::Vector2f initialAcceleration);
        void accelerate(sf::Vector2f acc);

        sf::Vector2f applyForces();

        // Custom shape
        sf::CircleShape shape; 
        sf::Text text;
        sf::Font font;

        float radius = 25.0;

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
            sf::Vector2f previous;
            sf::Vector2f current;
        } position;

        sf::Vector2f velocity;

        struct 
        {
            sf::Vector2f initial {20.0f, 20.0f};
            sf::Vector2f current;
        } acceleration;
};

#endif