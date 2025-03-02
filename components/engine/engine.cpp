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
    checkCollisions(dt);
    applyConstraint();
    checkObjectToRelease();

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
        std::cout << object.acceleration.current.x << " " 
        << object.acceleration.current.y << "\n";        
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