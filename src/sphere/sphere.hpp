#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "../window/window.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>

class Sphere
{
    public:
        Sphere();
        void updatePosition(float dt);
        void setInitialPosition(sf::Vector2f newPosition);
        void setInitialAcceleration(sf::Vector2f initialAcceleration);
        void accelerate(sf::Vector2f acc);

        int id = 0;
        float radius = 15.0;

        struct 
        {
            sf::Vector2f initial;
            sf::Vector2f previous;
            sf::Vector2f current;
        } position;

        sf::Vector2f velocity;

        struct 
        {
            sf::Vector2f initial {0.0f, -11.3141f};
            sf::Vector2f current;
        } acceleration;

        sf::CircleShape shape; 

    private:
        void logObject();
        sf::Vector2f getRandomPosition();

        sf::Text text;
        sf::Font font;
};

#endif //SPHERE_HPP