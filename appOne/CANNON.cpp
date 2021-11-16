#include "GAME.h"
#include "CAMERA.h"
#include "CYLINDER.h"
#include "BARREL.h"
#include "CANNON.h"

CANNON::CANNON(GAME* game) :
    GAME_OBJECT(game)
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
    Data = game()->allData.cannonData;
    Pos = Data.objPos;
    //Model
    Cylinder = new CYLINDER(36, 0, -0.2f);
    Barrel = new BARREL;

    return 0;
}

void CANNON::update()
{
    if (game()->state()==GAME::STATE::MOVE) {
        //移動方向を決める
        VECTOR dir(0, 0, 0);
        if (isPress(KEY_D)) { dir.x = 1; }
        if (isPress(KEY_A)) { dir.x = -1; }
        if (isPress(KEY_W)) { dir.z = -1; }
        if (isPress(KEY_S)) { dir.z = 1; }
        if (dir.x != 0 || dir.z != 0) {
            dir.normalize();
            MATRIX rot;
            rot.rotateY(game()->object(GAME::OBJ_ID::CAMERA)->angle().y);
            dir = rot * dir;
            //移動
            Pos += dir * Data.advSpeed;
            //回転
            rotate(dir, Data.advRotSpeed);
        }
    }

    if (game()->state()==GAME::STATE::ROTATE) {
        //dirへ向ける
        VECTOR dir = game()->object(GAME::OBJ_ID::SATELLITE1)->pos() - Pos;
        finishRotating = rotate(dir, Data.rotSpeed);
    }
    
    if (game()->state() == GAME::STATE::ROTATE_BACK) {
        VECTOR dir(0, 0, 1);
        finishRotating = rotate(dir, Data.rotSpeed);
    }
}

void CANNON::draw() 
{
    Master.identity();
    Master.mulTranslate(Pos.x, Pos.y, Pos.z);
    Master.mulRotateY(Angle.y);
    WheelL.identity();
    WheelL.mulTranslate(0.5f, -0.3f, 0);
    WheelL.mulRotateY(-1.57f);
    WheelR.identity();
    WheelR.mulTranslate(-0.5f, -0.3f, 0);
    WheelR.mulRotateY(1.57f);
    Body.identity();
    Body.mulTranslate(0, 0, 0);
    Body.mulRotateX(Angle.x);

    WheelL = Master * WheelL;
    Cylinder->draw(WheelL, Data.wheelColor, Data.ambient);
    WheelR = Master * WheelR;
    Cylinder->draw(WheelR, Data.wheelColor, Data.ambient);
    Body = Master * Body;
    Barrel->draw(Body,Data.bodyColor, Data.ambient);
}

int CANNON::finished()
{
    return finishRotating;
}
