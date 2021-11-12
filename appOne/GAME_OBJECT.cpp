#include "GAME_OBJECT.h"
GAME_OBJECT::GAME_OBJECT(GAME* game)
{
    Game = game;
}

GAME* GAME_OBJECT::game()
{
    return Game;
}
