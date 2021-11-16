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
    Pos = Data.objPos;
    MODEL::lightPos = normalize(Pos);
    return 0;
}
