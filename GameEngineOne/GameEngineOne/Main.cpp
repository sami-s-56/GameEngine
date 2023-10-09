
#include <iostream>
#include "Engine.h"


int main()
{
    std::cout << "Hello World!\n";

    Engine* engine = new Engine();
    engine->Load();
    engine->GameLoop();
    delete(engine);

    return 0;
}
