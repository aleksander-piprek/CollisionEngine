#include "../include/engine.hpp"

int main()
{
    Engine engine;

    while(engine.isRunning())
    {
        engine.updateTime();
        engine.update(0.5f);
        engine.draw();
        engine.restartTime();
    }
}