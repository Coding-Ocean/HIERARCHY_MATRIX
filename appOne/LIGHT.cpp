#include "GAME.h"
#include "MODEL.h"
#include "LIGHT.h"

LIGHT::LIGHT(class GAME* game, float x, float y, float z)
    :GAME_OBJECT(game)
{
    MODEL::lightPos = normalize(VECTOR(x,y,z));
}
