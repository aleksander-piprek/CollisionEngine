#include "../../include/engine.hpp"

Engine::Engine()
    : window("Collision Engine")
{
    generateObjects(totalObjects);                             
}

void Engine::update(float dt)
{
    window.update();
    releaseObject(dt);
    applyConstraint();    
    applyGravity();

    for(int i = 0; i < objectReleaseCount; i++)
        objects[i].updatePosition(dt);
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
        object.radius = 20.0;
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

void Engine::releaseObject(float dt)
{
    totalTime += dt;
    if(totalTime == releaseTime)
        if(objectReleaseCount != totalObjects)
        {
            objectReleaseCount++;
            totalTime = 0;
        }
}

void Engine::applyGravity()
{
    for(int i = 0; i < objectReleaseCount; i++)
        objects[i].accelerate(gravity);
}

void Engine::applyConstraint()
{
    for(auto& object : objects)
    {
        sf::Vector2f position = object.position.current;
        sf::Vector2f size(object.radius * 2, object.radius * 2);

        // Left border
        if (position.x - size.x < 0) 
            position.x = size.x; 

        // Right border
        if (position.x + size.x > window.screenWidth) 
            position.x = window.screenWidth - size.x; 

        // Top border
        if (position.y - size.y < 0) 
            position.y = size.y; 

        // Bottom border
        if (position.y + size.y > window.screenHeight) 
            position.y = window.screenHeight - size.y; 

        object.position.current = position;
    }
}