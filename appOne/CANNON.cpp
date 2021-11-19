#include "GAME.h"
#include "CAMERA.h"
#include "CYLINDER.h"
#include "BARREL.h"
#include "CANNON.h"

CANNON::CANNON(GAME* game) :
    OBJECT(game)
{
}

CANNON::~CANNON()
{
    delete Cylinder;
    delete Barrel;
}

int CANNON::setup()
{
    //Data
    Data = game()->allData()->cannonData;
    Target = game()->object(Data.objId);

    //Model
    Cylinder = new CYLINDER(36, 0, -0.2f);
    Barrel = new BARREL;

    return 0;
}

void CANNON::update()
{
    if (objState()==OBJ_STATE::MOVE) {
        if (isTrigger(KEY_X)) {
            const FORMATION_DATA& fd = game()->allData()->formationData[FormationId];
            Data.pos = fd.cannonPos;
        }
        //ˆÚ“®•ûŒü‚ðŒˆ‚ß‚é
        VECTOR dir(0, 0, 0);
        if (isPress(KEY_D)) { dir.x = 1; }
        if (isPress(KEY_A)) { dir.x = -1; }
        if (isPress(KEY_W)) { dir.z = -1; }
        if (isPress(KEY_S)) { dir.z = 1; }
        if (dir.x != 0 || dir.z != 0) {
            dir.normalize();
            MATRIX rot;
            rot.rotateY(game()->object(OBJ_ID::CAMERA)->angle().y);
            dir = rot * dir;
            //ˆÚ“®
            Data.pos += dir * Data.advSpeed;
            //‰ñ“]
            rotate(&Data.angle, dir, Data.advRotSpeed);
        }
    }

    if (objState()==OBJ_STATE::ROTATE) {
        //dir‚ÖŒü‚¯‚é
        VECTOR dir = Target->pos() - Data.pos;
        rotate(&Data.angle, dir, Data.rotSpeed, Data.endOfRotationFlag);
    }
    
    if (objState() == OBJ_STATE::ROTATE_BACK) {
        VECTOR dir(0, 0, 1);
        rotate(&Data.angle, dir, Data.rotBackSpeed, Data.endOfRotationFlag);
    }

    Master.identity();
    Master.mulTranslate(Data.pos.x, Data.pos.y, Data.pos.z);
    Master.mulRotateY(Data.angle.y);
    WheelL.identity();
    WheelL.mulTranslate(0.5f, -0.3f, 0);
    WheelL.mulRotateY(-1.57f);
    WheelR.identity();
    WheelR.mulTranslate(-0.5f, -0.3f, 0);
    WheelR.mulRotateY(1.57f);
    Body.identity();
    Body.mulTranslate(0, 0, 0);
    Body.mulRotateX(Data.angle.x);
}

void CANNON::draw() 
{
    WheelL = Master * WheelL;
    Cylinder->draw(WheelL, Data.wheelColor, Data.ambient);
    WheelR = Master * WheelR;
    Cylinder->draw(WheelR, Data.wheelColor, Data.ambient);
    Body = Master * Body;
    Barrel->draw(Body,Data.bodyColor, Data.ambient);
}

VECTOR CANNON::pos()
{
    return Data.pos;
}

VECTOR CANNON::angle()
{
    return Data.angle;
}


