#include "../../include/engine.hpp"

Engine::Engine()
    : window("Collision Engine")
{
    generateObjects(totalObjects);                             
}

void Engine::update(float dt)
{
    window.update();
    applyConstraint();
    applyGravity();

    for(auto& object : objects)
        object.updatePosition(dt);
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

void Engine::updateTime() 
{
    elapsedTime = clock.getElapsedTime().asSeconds();
}

void Engine::restartTime()
{
    clock.restart();
}

void Engine::generateObjects(int objectsCount)
{
    for(int i = 0; i < objectsCount; i++)
    {
        Sphere object;
        objects.push_back(object);
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
        // Left border
        if (object.position.current.x < 0) 
            object.position.current.x = 0; 

        // Right border
        if (object.position.current.x + object.radius * 2 > window.screenWidth) 
            object.position.current.x = window.screenWidth - object.radius * 2; 

        // Top border
        if (object.position.current.y < 0) 
            object.position.current.y = 0; 

        // Bottom border
        if (object.position.current.y + object.radius * 2 > window.screenHeight) 
            object.position.current.y = window.screenHeight - object.radius * 2; 
    }
}