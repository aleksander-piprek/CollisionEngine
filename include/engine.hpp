#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SFML/Graphics.hpp>
#include "window.hpp"
#include "workingDirectory.hpp"
#include "sphere.hpp"

class Engine
{
    public:
        Engine();
        void update();
        void lateUpdate();
        void draw();
        bool isRunning() const;
        void calculateDeltaTime();
        void generateObjects(int count);
        
    private:
        Window window;
        WorkingDirectory workingDir;
        std::vector<Sphere> objects;

        sf::Clock clock;
        float deltaTime;
}; 

#endif