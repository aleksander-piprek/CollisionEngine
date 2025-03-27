#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>

class Window
{
    public:
        Window(const std::string& windowName);

        void update();
        void clearContents();
        void setDrawableContents(const sf::Drawable& drawable);
        void displayContents();

        inline bool isOpen() const { return window.isOpen(); }

        sf::RenderWindow window;
        const int screenWidth = 800;
        const int screenHeight = 600;
};

#endif