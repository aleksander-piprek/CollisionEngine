#include "engine.hpp"

Engine::Engine()
    : window("Collision Engine")
{
    generateObjects(totalObjects);
}

void Engine::update(float dt)
{
    elapsedTimeToRelease += dt;    

    window.update();
    // checkCollisions(dt);
    applyConstraint();
    checkObjectToRelease();

    std::system ("clear");
    for(int i = 0; i < objectReleaseCount; i++)
        objects[i].updatePosition(dt);
}

void Engine::draw()
{
    window.beginDraw();

    for(int i = 0; i < objectReleaseCount; i++)
        window.draw(objects[i].shape);

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
        object.id = i+1;
        objects.push_back(object);
    }
}

void Engine::checkObjectToRelease()
{
    if(elapsedTimeToRelease > timeToReleaseObject)
    {
        if(objectReleaseCount != totalObjects)
        {
            objectReleaseCount++;
            elapsedTimeToRelease = 0;
        }
    }
}

void Engine::checkCollisions(float dt)
{
    for(int i = 0; i < objectReleaseCount; i++)
    {
        auto& object1 = objects[i];
        for(int j = i + 1; j < objectReleaseCount; j++)
        {
            auto& object2 = objects[j];
            const sf::Vector2f v = object1.position.current - object2.position.current;
            const float distance = sqrt(v.x * v.x + v.y * v.y);
            const float minDistance = object1.radius + object2.radius;
            if(distance < minDistance)
            {
                const float distanceSqr = distance * distance;
                const sf::Vector2f n = v / distance;
                const float delta        = distance - minDistance;
                object1.position.current -= n * 1.0f*delta;
                object2.position.current += n * 1.0f*delta;                    
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
        {
            object.accelerate({
                object.acceleration.initial.x,
                object.acceleration.current.y});            
        }

        // Right border
        if (object.position.current.x + object.radius * 2 > window.screenWidth) 
        {
            object.accelerate({
                -object.acceleration.initial.x,
                object.acceleration.current.y});            
        }

        // Top border
        if (object.position.current.y < 0) 
        {
            object.accelerate({
                object.acceleration.current.x,
                object.acceleration.initial.y});
        }

        // Bottom border
        if (object.position.current.y + object.radius * 2 > window.screenHeight)
        {
            object.accelerate({
                object.acceleration.current.x,
                -object.acceleration.initial.y});
        }
    }
}