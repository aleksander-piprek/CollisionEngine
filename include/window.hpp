#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>

class Window
{
    public:
        Window(const std::string& windowName);

        void update();

        void beginDraw();
        void draw(const sf::Drawable& drawable);
        void endDraw();

        bool isOpen() const;

        sf::RenderWindow window;
        const int screenWidth = 800;
        const int screenHeight = 600;
};

#endif