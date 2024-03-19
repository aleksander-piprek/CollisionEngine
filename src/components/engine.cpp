#include "../../include/engine.hpp"

Engine::Engine()
    : window("Collision Engine")
{
    generateObjects(100);
}

void Engine::update(float dt)
{
    window.update();
    applyGravity();
    applyConstraint();

    for(auto& object : objects)
    {
        const sf::Vector2f& shapePos = object.shape.getPosition();
        object.updatePosition(dt);
    }
}

void Engine::lateUpdate()
{

}

void Engine::draw()
{
    window.beginDraw();

    for(auto& object : objects)
        window.draw(object.shape);
    
    window.endDraw();
}

bool Engine::isRunning() const
{
    return window.isOpen();
}

void Engine::generateObjects(int objectsCount)
{
    int iteration = 0;
    
    while(iteration <= objectsCount)
    {
        Sphere object;
        object.radius = 25.0;
        object.color.red = 255 - iteration * 2;
        object.color.green = 0 + iteration * 2;
        object.color.blue = 0;
        object.color.opacity = 255;

        objects.push_back(object);
        iteration++;
        if(iteration > objectsCount)
            break;
    }
}

void Engine::applyGravity()
{
    for(auto& object : objects)
        object.accelerate(gravity);
}

void Engine::applyConstraint()
{
    for(auto& object : objects)
    {
        const sf::Vector2f v = constraintCenter - object.positionCurrent;
        const float dist = sqrt(v.x * v.x + v.y * v.y);        
        if(dist > (constraintRadius - object.radius))
        {
            const sf::Vector2f n = v / dist;
            object.positionCurrent = constraintCenter - n * (constraintRadius - object.radius);
        }
    }
}