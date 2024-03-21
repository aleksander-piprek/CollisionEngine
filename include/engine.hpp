#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SFML/Graphics.hpp>
#include "window.hpp"
#include "workingDirectory.hpp"
#include "sphere.hpp"
#include "scene.hpp"
#include <math.h>

class Engine
{
    public:
        Engine();
        void update(float dt);
        void lateUpdate();
        void draw();
        bool isRunning() const;
        void generateObjects(int count);
        void applyGravity();
        void applyConstraint();
        
    private:
        Window window;
        WorkingDirectory workingDir;
        std::vector<Sphere> objects;
        sf::Vector2f gravity = {0.0f, 1.0f};
}; 

#endif