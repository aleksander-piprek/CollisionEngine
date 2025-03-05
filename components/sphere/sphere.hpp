#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../window/window.hpp"

class Sphere
{
    void logObject();

    public:
        Sphere();
        void updatePosition(float dt);
        void setInitialPosition(sf::Vector2f newPosition);
        void setInitialAcceleration(sf::Vector2f initialAcceleration);
        void setPosition(sf::Vector2f pos);
        void accelerate(sf::Vector2f acc);

        // Custom shape
        sf::CircleShape shape; 
        sf::Text text;
        sf::Font font;

        int id = 0;
        float radius = 15.0;

        struct 
        {
            sf::Uint8 red = 255;
            sf::Uint8 green = 0;
            sf::Uint8 blue = 255;
            sf::Uint8 opacity = 255;
        } color;   

        struct 
        {
            sf::Vector2f initial {100.0f, 100.0f};
            sf::Vector2f previous;
            sf::Vector2f current;
        } position;

        sf::Vector2f velocity;

        struct 
        {
            sf::Vector2f initial {10.0f, 10.0f};
            sf::Vector2f current;
        } acceleration;
};

#endif //SPHERE_HPP