#include "GAME.h"
#include "ENEMY.h"
ENEMY::ENEMY(GAME* game)
    :OBJECT(game)
{
}

int ENEMY::setup()
{
    Data = game()->allData()->enemyData;
    
    HeadModel.identity();
    HeadModel.mulScaling(0.8f, 0.8f, 0.8f);

    StickModel.identity();
    StickModel.mulRotateX(1.57f);
    StickModel.mulTranslate(0, 0, -0.5f);
    StickModel.mulScaling(0.1f, 0.1f, 1.0f);

    NucleusModel.identity();
    NucleusModel.mulScaling(0.1f, 0.1f, 0.1f);

    return 0;
}

void ENEMY::update()
{
    if (objState() == OBJ_STATE::MOVE) {
        int fid = formationId();
        if (isTrigger(KEY_X)) {
            const FORMATION_DATA& fd = game()->allData()->formationData[fid];
            Data.pos = fd.enemyPos;
        }

        if (fid == 0) {
            AngleForPos += Data.animSpeed;
        }
        else {
            AngleForPos = 0;
        }
    }

    if (objState()!=OBJ_STATE::ROTATE_BACK){
        AnimAngle += Data.animSpeed;
    }

    Master.identity();
    Master.mulTranslate(Data.pos.x, Data.pos.y, Data.pos.z);
    Head.identity();
    Data.offsetPos.y = Data.offsetPosY + sin(AngleForPos) * 0.2f;
    Head.mulTranslate(Data.offsetPos.x, Data.offsetPos.y, Data.offsetPos.z);
    NucleusA.identity();
    NucleusA.mulRotateZ(0.7f);
    NucleusA.mulRotateX(AnimAngle*16);
    NucleusA.mulTranslate(0, 0, 0.6f);
    NucleusB.identity();
    NucleusB.mulRotateZ(-0.7f);
    NucleusB.mulRotateX(AnimAngle*15);
    NucleusB.mulTranslate(0, 0, 0.6f);
}

void ENEMY::draw()
{
    Cylinder.draw(Master * StickModel, Data.stickColor, Data.ambient);
    
    Head = Master * Head;
    Sphere.draw(Head * HeadModel, Data.headColor, Data.ambient);

    NucleusA = Head * NucleusA;
    Sphere.draw(NucleusA * NucleusModel);

    NucleusB = Head * NucleusB;
    Sphere.draw(NucleusB * NucleusModel);
}

VECTOR ENEMY::pos()
{
    return Data.pos + Data.offsetPos;
}
