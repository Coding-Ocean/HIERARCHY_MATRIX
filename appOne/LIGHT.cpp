#include "GAME.h"
#include "MODEL.h"
#include "LIGHT.h"

LIGHT::LIGHT(class GAME* game)
    :GAME_OBJECT(game)
{
}

int LIGHT::setup()
{
    Data = game()->allData.lightData;
    MODEL::lightPos = normalize(Data.pos);
    return 0;
}
