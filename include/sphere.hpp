#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <SFML/Graphics.hpp>

class Sphere
{
    public:
        Sphere(float radius);
        sf::CircleShape& getShape() { return shape; }

    private:
        sf::CircleShape shape; 
        int radius;        
};

#endif