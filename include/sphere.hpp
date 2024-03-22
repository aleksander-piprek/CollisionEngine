#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <SFML/Graphics.hpp>

class Sphere
{
    public:
        Sphere();
        void updatePosition(float dt);
        void setInitialPosition(sf::Vector2f newPosition);
        void accelerate(sf::Vector2f acc);

        sf::CircleShape shape; 
        int radius;
        struct 
        {
            sf::Uint8 red = 255;
            sf::Uint8 green = 0;
            sf::Uint8 blue = 255;
            sf::Uint8 opacity = 255;
        } color;        

        sf::Vector2f initialPosition {800.0f, 100.0f};
        sf::Vector2f positionCurrent;
        sf::Vector2f positionOld;

        sf::Vector2f velocity;

        sf::Vector2f acceleration;        
};

#endif