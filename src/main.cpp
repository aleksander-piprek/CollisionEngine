#include "../include/engine.hpp"

int main()
{
    Engine engine;

    while(engine.isRunning())
    {
        engine.updateTime();
        engine.update(0.50f);
        engine.draw();
        engine.restartTime();
    }
}