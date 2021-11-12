#include "FLOOR.h"

FLOOR::FLOOR(GAME* game):
    GAME_OBJECT(game)
{
    Color[0].set(0, 0, 0);
    Color[1].set(64, 128, 64);
}

void FLOOR::update()
{

}

void FLOOR::draw()
{
    for (int z = -3; z <= 3; z++) {
        for (int x = -3; x <= 3; x++) {
            World.identity();
            World.mulScaling(3, 1, 3);
            World.mulTranslate(x, 0, z);
            int no = (z + x) % 2 == 0 ? 0 : 1;
            Plane.draw(World, Color[no]);
        }
    }
}
