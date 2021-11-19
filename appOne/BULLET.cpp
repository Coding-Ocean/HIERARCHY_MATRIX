#include "GAME.h"
#include "BULLET.h"

BULLET::BULLET(GAME* game)
    :OBJECT(game)
{
}

BULLET::~BULLET()
{
    SAFE_DELETE(Cone);
    SAFE_DELETE_ARRAY(Targets);
}

int BULLET::setup()
{
    Data = game()->allData()->bulletData;
    
    Targets = new OBJECT * [Data.numTargets];
    for (int i = 0; i < Data.numTargets; i++) {
        Targets[i] = game()->object(Data.objId[i]);
    }

    Cone = new CONE;

    return 0;
}

void BULLET::update()
{
    if (objState() == OBJ_STATE::MOVE) {
        if (isTrigger(KEY_X)) {
            const FORMATION_DATA& fd = game()->allData()->formationData[FormationId];
            Data.advSpeed = fd.bulletAdvSpeed;
        }

        Data.pos = game()->object(OBJ_ID::CANNON)->pos();
        Data.angle = game()->object(OBJ_ID::CANNON)->angle();
    }

    if (objState() == OBJ_STATE::ROTATE) {
        Data.angle = game()->object(OBJ_ID::CANNON)->angle();
        TargetNo = 0;
    }

    if (objState() == OBJ_STATE::FLY) {
        if (TargetNo < Data.numTargets) {
            VECTOR dir = Targets[TargetNo]->pos() - Data.pos;
            float distance = dir.mag();
            Data.pos += dir.normalize() * Data.advSpeed;
            rotate(&Data.angle, dir, Data.rotSpeed);
            //当たったので次のターゲットへ
            if (distance < Data.collisionDistance) {
                TargetNo++;
            }
        }
        else {
            completeState();
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
