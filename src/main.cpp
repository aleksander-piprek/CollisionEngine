#include "../include/engine.hpp"

int main()
{
    auto engine = new Engine();

    while(engine->isRunning())
    {
        engine->update();
        engine->lateUpdate();
        engine->draw();
    }
}