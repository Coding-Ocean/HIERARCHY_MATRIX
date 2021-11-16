#include "GAME.h"
#include "BULLET.h"

BULLET::BULLET(GAME* game)
    :GAME_OBJECT(game)
    , Cone(36, 1)
{
    Color.set(255, 60, 60);
}

void BULLET::update()
{
    if (game()->state() == GAME::STATE::MOVE) {
        Pos = game()->object(GAME::OBJ_ID::CANNON)->pos();
        Angle = game()->object(GAME::OBJ_ID::CANNON)->angle();
        Step = -1;
    }

    if (game()->state() == GAME::STATE::ROTATE) {
        Angle = game()->object(GAME::OBJ_ID::CANNON)->angle();
    }

    if (game()->state() == GAME::STATE::FLY) {
        if (Step == -1) {
            Target[0] = game()->object(GAME::OBJ_ID::SATELLITE1);
            Target[1] = game()->object(GAME::OBJ_ID::SATELLITE2);
            Target[2] = game()->object(GAME::OBJ_ID::ENEMY);
            Step = 0;
        }
        if (Step <= 2) {
            VECTOR dir = Target[Step]->pos() - Pos;
            float len = dir.mag();
            Pos += dir.normalize() * 0.2f;
            rotate(dir, 1);
            if (len < 0.3f) {
                Step++;
            }
        }
    }
}

int BULLET::finished()
{
    return Step == 3;
}

void BULLET::draw()
{
    Master.translate(Pos.x, Pos.y, Pos.z);
    Master.mulRotateY(Angle.y);
    Master.mulRotateX(Angle.x);
    Master.mulScaling(0.6f, 0.6f, 0.6f);
    Cone.draw(Master, Color);
}

