#include "GAME.h"
#include "BULLET.h"

BULLET::BULLET(GAME* game)
    :GAME_OBJECT(game)
{
}

BULLET::~BULLET()
{
    SAFE_DELETE(Cone);
    SAFE_DELETE_ARRAY(Targets);
}

int BULLET::setup()
{
    Data = game()->allData.bulletData;
    
    Targets = new OBJECT * [Data.numTargets];
    for (int i = 0; i < Data.numTargets; i++) {
        Targets[i] = game()->object(Data.objId[i]);
    }

    Cone = new CONE;

    return 0;
}

void BULLET::update()
{
    if (game()->state() == GAME::STATE::MOVE) {
        Data.pos = game()->object(OBJ_ID::CANNON)->pos();
        Data.angle = game()->object(OBJ_ID::CANNON)->angle();
        Step = 0;
    }

    if (game()->state() == GAME::STATE::ROTATE) {
        Data.angle = game()->object(OBJ_ID::CANNON)->angle();
    }

    if (game()->state() == GAME::STATE::FLY) {
        if (Step < Data.numTargets) {
            VECTOR dir = Targets[Step]->pos() - Data.pos;
            float len = dir.mag();
            Data.pos += dir.normalize() * 0.2f;
            rotate(&Data.angle, dir, 1);
            if (len < 0.3f) {
                Step++;
            }
        }
    }

    Master.translate(Data.pos.x, Data.pos.y, Data.pos.z);
    Master.mulRotateY(Data.angle.y);
    Master.mulRotateX(Data.angle.x);
    Master.mulScaling(0.6f, 0.6f, 0.6f);
}

void BULLET::draw()
{
    Cone->draw(Master, Data.color, Data.ambient);
}

VECTOR BULLET::pos()
{
    return Data.pos;
}

int BULLET::finished()
{
    return Step == Data.numTargets;
}
