#include "../../include/sphere.hpp"

Sphere::Sphere(float radius)
    : radius(radius)
{        
    shape.setRadius(radius);
    shape.setFillColor(sf::Color(100, 250, 50));    
}