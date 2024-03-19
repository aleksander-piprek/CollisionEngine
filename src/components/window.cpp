#include "../../include/window.hpp"

Window::Window(const std::string& windowName)
    : window(sf::VideoMode(1280, 720), windowName, sf::Style::Titlebar)
{
    window.setVerticalSyncEnabled(true);
}

void Window::update()
{
    sf::Event event;
    if(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

void Window::beginDraw()
{
    window.clear(sf::Color::Black);
}

void Window::draw(const sf::Drawable& drawable)
{
    window.draw(drawable);
}

void Window::endDraw()
{
    window.display();   
}

bool Window::isOpen() const
{
    return window.isOpen();
}