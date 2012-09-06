#include <stdio.h>
#include <stdbool.h>
#include "gameengine.h"

int main()
{
    /* create a game engine object */
    game_engine* engine = new game_engine;

    /* loop until the window is closed */
    do
    {
        engine->process_events();
        engine->update();
        engine->render();
    } while ( engine->running() );
    
    /* delete the card deck on exit */
    delete engine;

    return 0;
}
