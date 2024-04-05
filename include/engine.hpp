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
        void checkCollisions(float dt);
        void applyConstraint();
        
    private:
        Window window;
        WorkingDirectory workingDir;
        std::vector<Sphere> objects;

        sf::Clock clock;        
        float elapsedTime;
        float objectReleaseCount = 1;
        float totalTime;

        const int totalObjects = 1;
}; 

#endif