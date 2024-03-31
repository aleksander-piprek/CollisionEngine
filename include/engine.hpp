#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <math.h>

#include "window.hpp"
#include "workingDirectory.hpp"
#include "sphere.hpp"

class Engine
{
    public:
        Engine();
        void update(float dt);
        void draw();
        bool isRunning() const;

        void updateTime(); 
        void restartTime();

        void generateObjects(int count);
        void applyGravity();
        void applyConstraint();
        
    private:
        Window window;
        WorkingDirectory workingDir;
        std::vector<Sphere> objects;

        sf::Clock clock;        
        float elapsedTime;

        sf::Vector2f gravity = {1.0f, -1.0f};

        const int totalObjects = 5;
}; 

#endif