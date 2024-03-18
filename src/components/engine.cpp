#include "../../include/engine.hpp"

Engine::Engine()
    : window("Collision Engine")
{
    deltaTime = clock.restart().asSeconds();
    generateObjects(50);
}

void Engine::update()
{
    window.update();

    // auto objectIterator = objects.begin();
    // auto object = std::move(*objectIterator);
    // objects.erase(objectIterator);
    for(auto& object : objects)
    {
        sf::CircleShape& shape = object.getShape();
        const sf::Vector2f& shapePos = shape.getPosition();
        const int pixelsToMovePerSec = 50;
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
    
    while(iteration <= objectsCount)
    {
        Sphere object;
        object.radius = 10.0 + iteration * 2;
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