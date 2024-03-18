#include "../../include/engine.hpp"

Engine::Engine()
    : window("Collision Engine"), obj1(50.0f)
{
    deltaTime = clock.restart().asSeconds();

    // objectTexture.loadFromFile(workingDir.get() + "heart.png");
    // objectSprite.setTexture(objectTexture);

}

void Engine::update()
{
    window.update();
    
    sf::CircleShape& shape = obj1.getShape();
    const sf::Vector2f& shapePos = shape.getPosition();
    const int pixelsToMovePerSec = 20;
    const float frameMovement = pixelsToMovePerSec * deltaTime;
    shape.setPosition(shapePos.x, shapePos.y + frameMovement);
}

void Engine::lateUpdate()
{

}

void Engine::draw()
{
    window.beginDraw();
    window.draw(obj1.getShape());
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