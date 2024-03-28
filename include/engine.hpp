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

        sf::Vector2f gravity = {-1.0f, 1.0f};

        int objectReleaseCount = 1;  
        int totalObjects = 2;
        float totalTime = 0;
        float releaseTime = 40.0f;
}; 

#endif