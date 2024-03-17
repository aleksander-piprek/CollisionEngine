#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SFML/Graphics.hpp>
#include "window.hpp"
#include "workingDirectory.hpp"

class Engine
{
    public:
        Engine();
        void update();
        void lateUpdate();
        void draw();
        bool isRunning() const;
        
    private:
        Window window;
        WorkingDirectory workingDir;
        
        // Custom texture
        // sf::Texture objectTexture;
        // sf::Sprite objectSprite;

        // Shape
        sf::CircleShape shape;
}; 

#endif