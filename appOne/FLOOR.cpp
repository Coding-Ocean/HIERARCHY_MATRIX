#include "GAME.h"
#include "FLOOR.h"

FLOOR::FLOOR(GAME* game):
    GAME_OBJECT(game)
{
}

int FLOOR::setup()
{
    Data = game()->allData.floorData;
    return 0;
}

void FLOOR::draw()
{
    for (int z = -3; z <= 3; z++) {
        for (int x = -3; x <= 3; x++) {
            World.identity();
            World.mulScaling(3, 1, 3);
            World.mulTranslate((float)x, 0, (float)z);
            int no = (z + x) % 2 == 0 ? 0 : 1;
            Plane.draw(World, Data.color[no]);
        }
    }
}

//カメラターゲット用位置
VECTOR FLOOR::pos()
{
    return Data.pos;
}
