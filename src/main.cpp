#include "../include/engine.hpp"

int main()
{
    Engine engine;

    while(engine.isRunning())
    {
        engine.update(0.5f);
        engine.draw();
    }
}