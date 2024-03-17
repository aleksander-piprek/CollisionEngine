#include "../../include/engine.hpp"

Engine::Engine()
    : window("Collision Engine")
{
    // objectTexture.loadFromFile(workingDir.get() + "heart.png");
    // objectSprite.setTexture(objectTexture);

    shape.setRadius(150);
    shape.setFillColor(sf::Color(100, 250, 50));    
}

void Engine::update()
{
    const sf::Vector2f& shapePos = shape.getPosition();
    shape.setPosition(shapePos.x + 1, shapePos.y + 1);
    window.update();
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