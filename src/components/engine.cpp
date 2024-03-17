#include "../../include/engine.hpp"

Engine::Engine()
    : window("Collision Engine")
{
    deltaTime = clock.restart().asSeconds();

    // objectTexture.loadFromFile(workingDir.get() + "heart.png");
    // objectSprite.setTexture(objectTexture);

    shape.setRadius(150);
    shape.setFillColor(sf::Color(100, 250, 50));    
}

void Engine::update()
{
    window.update();

    const sf::Vector2f& shapePos = shape.getPosition();
    const int pixelsToMovePerSec = 20;
    const float frameMovement = pixelsToMovePerSec * deltaTime;
    shape.setPosition(shapePos.x + frameMovement, shapePos.y);
}

void Engine::lateUpdate()
{

}

void Engine::draw()
{
    window.beginDraw();
    window.draw(shape);
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