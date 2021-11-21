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
    WheelLModel.identity();
    WheelLModel.mulTranslate(0.5f, 0.5f, 0);
    WheelLModel.mulRotateY(-1.57f);
    WheelRModel.identity();
    WheelRModel.mulTranslate(-0.5f, 0.5f, 0);
    WheelRModel.mulRotateY(1.57f);

    return 0;
}

void CANNON::update()
{
    if (objState()==OBJ_STATE::MOVE) {
        if (isTrigger(KEY_X)) {
            int id = formationId();
            const FORMATION_DATA& fd = game()->allData()->formationData[id];
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
        VECTOR dir = Target->pos() - pos();
        rotate(&Data.angle, dir, Data.rotSpeed, Data.endOfRotationFlag);
    }
    
    if (objState() == OBJ_STATE::ROTATE_BACK) {
        VECTOR dir(0, 0, 1);
        rotate(&Data.angle, dir, Data.rotBackSpeed, Data.endOfRotationFlag);
    }

    Master.identity();
    Master.mulTranslate(Data.pos.x, Data.pos.y, Data.pos.z);
    Master.mulRotateY(Data.angle.y);
    Body.identity();
    Body.mulTranslate(Data.offsetPos.x,Data.offsetPos.y,Data.offsetPos.z);
    Body.mulRotateX(Data.angle.x);
}

void CANNON::draw() 
{
    Cylinder->draw(Master * WheelLModel, Data.wheelColor, Data.ambient);
    Cylinder->draw(Master * WheelRModel, Data.wheelColor, Data.ambient);
    Barrel->draw(Master * Body, Data.bodyColor, Data.ambient);
}

VECTOR CANNON::pos()
{
    return (Data.pos + Data.offsetPos);
}

VECTOR CANNON::angle()
{
    return Data.angle;
}
