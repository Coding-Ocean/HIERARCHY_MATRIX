#include"GAME.h"
void gmain() {
    GAME* game = new GAME;
    game->create();
    game->run();
    delete game;
}
