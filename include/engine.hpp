#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SFML/Graphics.hpp>
#include <math.h>
#include <chrono>
#include <thread>

#include "window.hpp"
#include "workingDirectory.hpp"
#include "sphere.hpp"
#include "scene.hpp"


class Engine
{
    public:
        Engine();
        void update(float dt);
        void draw();
        bool isRunning() const;
        void generateObjects(int count);
        void applyGravity();
        void applyConstraint();
        
    private:
        Window window;
        WorkingDirectory workingDir;
        std::vector<Sphere> objects;
        // std::vector<sf::Sprite> spriteObjects;

        sf::Vector2f gravity = {0.0f, 1.0f};

        // Custom texture
        sf::Texture objectTexture;
        sf::Sprite objectSprite;      

        int objectReleaseCount = 1;  
        int totalObjects = 50;
        float totalTime = 0;
}; 

#endif