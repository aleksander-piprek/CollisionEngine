#include "../../include/engine.hpp"

Engine::Engine()
    : window("Collision Engine")
{
    deltaTime = clock.restart().asSeconds();
    generateObjects(10);
}

void Engine::update()
{
    window.update();
    
    for(auto& object : objects)
    {
        sf::CircleShape& shape = object.getShape();
        const sf::Vector2f& shapePos = shape.getPosition();
        const int pixelsToMovePerSec = 20;
        const float frameMovement = pixelsToMovePerSec * deltaTime;
        shape.setPosition(shapePos.x, shapePos.y + frameMovement);
    }
}

void Engine::lateUpdate()
{

}

void Engine::draw()
{
    window.beginDraw();
    for(auto& object : objects)
        window.draw(object.getShape());
    window.endDraw();
}

bool Engine::isRunning() const
{
    return window.isOpen();
}

void Engine::calculateDeltaTime()
{
    deltaTime = clock.restart().asSeconds();
}
void Engine::generateObjects(int objectsCount)
{
    int iteration = 0;
    float radius = 50.0;
    while(iteration < objectsCount)
    {
        // radius += 10.0;
        Sphere object(radius);
        objects.push_back(object);
        iteration++;
        if(iteration > objectsCount)
            break;
    }
}