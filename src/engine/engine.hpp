#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <math.h>

#include "../window/window.hpp"
#include "../sphere/sphere.hpp"

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
        void checkCollisions();
        void applyConstraint();
        void checkObjectToRelease();
        
    private:
        Window window;
        std::string workingDir = "../src/";
        std::vector<Sphere> objects;

        sf::Clock clock;        
        float elapsedTime;

        float objectReleaseCount = 1;
        float timeToReleaseObject = 15.0f;
        float elapsedTimeToRelease = 0.0f;

        const int totalObjects = 50;
}; 

#endif //ENGINE_HPP