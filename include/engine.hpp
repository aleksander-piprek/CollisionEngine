#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SFML/Graphics.hpp>
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

        void generateObjects(int count);
        void releaseObject(float dt);
        void applyGravity();
        void applyConstraint();
        
    private:
        Window window;
        WorkingDirectory workingDir;
        std::vector<Sphere> objects;

        sf::Vector2f gravity = {0.0f, 1.0f};

        int objectReleaseCount = 0;  
        int totalObjects = 100;
        float totalTime = 0;
        float releaseTime = 15.0f;
}; 

#endif