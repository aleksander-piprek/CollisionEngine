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
        object.updatePosition(dt);
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
        object.radius = 50.0;
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
        sf::Vector2f position = object.positionCurrent;
        sf::Vector2f size(object.radius * 2, object.radius * 2);

    // Check left border
    if (position.x - size.x < 0) 
        position.x = size.x; // Adjust the position to be within the window

    // Check right border
    if (position.x + size.x > window.size.x) 
        position.x = window.size.x - size.x; // Adjust the position to be within the window

    // Check top border
    if (position.y - size.y < 0) 
        position.y = size.y; // Adjust the position to be within the window

    // Check bottom border
    if (position.y + size.y > window.size.y) 
        position.y = window.size.y - size.y; // Adjust the position to be within the window

        // Update the object's position after applying constraints
        object.positionCurrent = position;
    }
}