
#include <iostream>
#include "Engine.h"


int main()
{
    std::cout << "Hello World!\n";

    Engine* engine = new Engine();
    engine->GameLoop();
    delete(engine);

}
