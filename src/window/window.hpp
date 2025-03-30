#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>

class Window
{
    sf::RenderWindow window;

    public:
        Window(const std::string& windowName);

        void update();
        void clearContents();
        void setDrawableContents(const sf::Drawable& drawable);
        void displayContents();

        inline bool isOpen() const { return window.isOpen(); }

        static const int screenWidth = 800;
        static const int screenHeight = 600;

        const uint FPSLimit = 60;
};

#endif