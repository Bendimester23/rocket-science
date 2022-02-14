#include "Game.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#undef RAYGUI_IMPLEMENTATION

int main() {
    Game game;
    game.loop();

    return 0;
}
