#include "../include/engine.hpp"

int main()
{
    auto engine = new Engine();

    while(engine->isRunning())
    {
        engine->update(0.25f);
        engine->draw();
    }
}