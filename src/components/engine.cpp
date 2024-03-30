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
        if(elapsedTime > 1.0f)
            object.updatePosition(dt);
}

void Engine::draw()
{
    window.beginDraw();

    for(auto& object : objects)
        if(elapsedTime > 1.0f)
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
        if(elapsedTime > 1.0f)
            object.accelerate(gravity);
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
            position.y = -size.y; 

        // Bottom border
        if (position.y + size.y > window.screenHeight) 
            position.y = window.screenHeight - size.y; 

        object.position.current = position;
    }
}