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
    //state‚ÌØ‚è‘Ö‚¦‚Í‚±‚±‚Å‚Ì‚Ýs‚¤I

    if (game()->state()==GAME::STATE::MOVE) {
        //ˆÚ“®•ûŒü‚ðŒˆ‚ß‚é
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
            //ˆÚ“®
            Pos += dir * Data.advSpeed;
            //‰ñ“]
            rotate(dir, Data.advRotSpeed);
        }
        //next
        if (isTrigger(KEY_Z)) {
            game()->setState(GAME::STATE::ROTATE);
        }
    }

    if (game()->state()==GAME::STATE::ROTATE) {
        //dir‚ÖŒü‚¯‚é
        VECTOR dir = game()->object(GAME::OBJ_ID::SATELLITE1)->pos() - Pos;
        int finished = rotate(dir, Data.rotSpeed);
        //‰ñ“]I—¹
        if ( finished &&
            game()->object(GAME::OBJ_ID::SATELLITE1)->finished() &&
            game()->object(GAME::OBJ_ID::SATELLITE2)->finished()) {
            //if (isTrigger(KEY_Z)) 
            {
                game()->setState(GAME::STATE::FLY);
            }
        }
    }

    if (game()->state() == GAME::STATE::FLY) {
        if (game()->object(GAME::OBJ_ID::BULLET)->finished()) {
            if (isTrigger(KEY_Z)) {
                game()->setState(GAME::STATE::ROTATE_BACK);
            }
        }
    }
    
    if (game()->state() == GAME::STATE::ROTATE_BACK) {
        int finished = rotate(VECTOR(0, 0, 1), Data.rotSpeed);
        if ( finished &&
            game()->object(GAME::OBJ_ID::SATELLITE1)->finished() &&
            game()->object(GAME::OBJ_ID::SATELLITE2)->finished()) {
            game()->setState(GAME::STATE::MOVE);
        }
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


