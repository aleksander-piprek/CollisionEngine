#include "window.hpp"

Window::Window(const std::string& windowName)
    : window(sf::VideoMode((uint)screenWidth, (uint)screenHeight), 
      windowName, 
      sf::Style::Titlebar)
{
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(FPSLimit);
}

void Window::update()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
        {
            window.close();
        }
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
        {
            bool paused = true;
            while (paused)
            {
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
                    {
                        paused = false;
                    }
                    else if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                    {
                        window.close();
                        paused = false;
                    }
                }
            }
        }
    }
}


void Window::clearContents()
{
    window.clear(sf::Color::Black);
}

void Window::setDrawableContents(const sf::Drawable& drawable)
{
    window.draw(drawable);
}

void Window::displayContents()
{
    window.display();   
}