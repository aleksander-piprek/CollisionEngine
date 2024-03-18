#include "../../include/sphere.hpp"

Sphere::Sphere()
    : radius(radius), color(color)
{
    shape.setRadius(radius);
    shape.setFillColor(sf::Color(color.red, 
                                 color.green, 
                                 color.blue, 
                                 color.opacity));    
}