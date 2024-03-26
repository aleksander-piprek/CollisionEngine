#include "../include/engine.hpp"

int main()
{
    auto engine = new Engine();

    while(engine->isRunning())
    {
        engine->update(0.5f);
        engine->draw();
    }
}