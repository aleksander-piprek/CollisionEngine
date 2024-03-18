#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <SFML/Graphics.hpp>

class Sphere
{
    public:
        Sphere();
        sf::CircleShape& getShape() { return shape; }
        void update();

        int radius;        
        struct 
        {
            sf::Uint8 red = 255;
            sf::Uint8 green = 0;
            sf::Uint8 blue = 255;
            sf::Uint8 opacity = 255;
        } color;        

    private:
        sf::CircleShape shape; 

        // sf::Vec2d pos { 0.0, 0.0 };
        // sf::Vec2d vel { 2.0, 0.0 }; 
        // sf::Vec2d acc { 0.0, 0.0 }; 
        // double mass = 1.0; 
        // double drag = 0.1; 
};

#endif