#include "../../include/engine.hpp"

Engine::Engine()
    : window("Collision Engine")
{
    // generateObjects(totalObjects);                             
}

void Engine::update(float dt)
{
    window.update();
    // releaseObject(dt);
    // applyConstraint();    
    // applyGravity();

    // objects[0].updatePosition(dt);

    // for(int i = 0; i < objectReleaseCount; i++)
        // objects[i].updatePosition(dt);
}

void Engine::draw()
{
    window.beginDraw();

    for(int i = 0; i < 2; i++)
    {
        Sphere object;

        object.radius = 40.0;
        object.color.red = 255;
        object.color.green = 150;
        object.color.blue = 0;
        object.color.opacity = 255;

        objects.push_back(object);
    }

    window.draw(objects[1].shape);

    // for(int i = 0; i < objectReleaseCount; i++)
        // window.draw(objects[i].shape);
    
    window.endDraw();
}

bool Engine::isRunning() const
{
    return window.isOpen();
}

void Engine::generateObjects(int objectsCount)
{
    for(int i = 0; i < objectsCount; i++)
    {
        Sphere object;

        object.radius = 40.0;
        object.color.red = 255;
        object.color.green = 150;
        object.color.blue = 0;
        object.color.opacity = 255;

        objects.push_back(object);
    }
    std::cout << "Generated " << objects.size() << " objects" << std::endl;
}

void Engine::releaseObject(float dt)
{
    totalTime += dt;
    if(totalTime == releaseTime)
        if(objectReleaseCount < totalObjects)
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
    for(int i = 0; i < objectReleaseCount; i++)
    {
        sf::Vector2f position = objects[i].position.current;
        sf::Vector2f size(objects[i].radius * 2, objects[i].radius * 2);

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

        objects[i].position.current = position;
    }
}