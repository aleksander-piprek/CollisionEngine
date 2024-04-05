#include "../../include/engine.hpp"

Engine::Engine()
    : window("Collision Engine")
{
    generateObjects(totalObjects);
}

void Engine::update(float dt)
{
    window.update();
    checkCollisions(dt);
    applyConstraint();

    totalTime += dt;
    if(totalTime > 10.0f)
        if(objectReleaseCount != totalObjects)
        {
            objectReleaseCount++;
            totalTime = 0;
        }

    for(int i = 0; i < objectReleaseCount; i++)
        objects[i].updatePosition(dt);
}

void Engine::draw()
{
    window.beginDraw();

    // for(int i = 0; i < objectReleaseCount; i++)
    // {
    //     window.draw(objects[i].shape);
    //     // window.draw(objects[i].text);
    // }
    window.draw(objects[0].text);

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

void Engine::checkCollisions(float dt)
{
    const float response = 0.75;
    for(int i = 0; i < objectReleaseCount; i++)
    {
        auto object1 = objects[i];
        for(int j = 0; j < objectReleaseCount; j++)
        {
            auto object2 = objects[i];
            const sf::Vector2f v = object1.position.current - object2.position.current;
            const float distance = v.x * v.x + v.y * v.y;
            const float minDistance = object1.radius + object2.radius;
            if(distance < minDistance * minDistance)
            {
                const float distanceSqr = distance * distance;
                const sf::Vector2f n = v / distanceSqr;
                const float massRatio1 = object1.radius / (object1.radius + object2.radius);
                const float massRatio2 = object2.radius / (object1.radius + object2.radius);
                const float delta        = 0.5f * response * (distanceSqr - minDistance);
                object1.position.current -= n * (massRatio2 * delta);
                object2.position.current += n * (massRatio1 * delta);                    
            }
        }
    }
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
        {
            // object.position.current.y = window.screenHeight - object.radius * 2; 
            object.acceleration.current.y = -0.75f;
            object.accelerate(object.acceleration.current); 
        }
    }
}   