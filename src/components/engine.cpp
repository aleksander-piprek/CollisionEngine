#include "../../include/engine.hpp"

Engine::Engine()
    : window("Collision Engine")
{
    generateObjects(totalObjects);
    for(auto& object : objects)
        applyGravity();
}

void Engine::update(float dt)
{
    window.update();
    applyConstraint();

    totalTime += dt;
    if(totalTime == 15.0f)
        if(objectReleaseCount != totalObjects)
        {
            objectReleaseCount++;
            totalTime = 0;
        }

    for(int i = 0; i < objectReleaseCount; i++)
    {
        objects[i].updatePosition(dt);
    }
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
        object.color.red = 255;
        object.color.green = 150;
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

        // Left border
        if (position.x - size.x < 0) 
            position.x = size.x; 

        // Right border
        if (position.x + size.x > window.size.x) 
            position.x = window.size.x - size.x; 

        // Top border
        if (position.y - size.y < 0) 
            position.y = size.y; 

        // Bottom border
        if (position.y + size.y > window.size.y) 
            position.y = window.size.y - size.y; 

        object.positionCurrent = position;
    }
}