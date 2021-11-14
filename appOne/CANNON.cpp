#include"GAME.h"
#include"CAMERA.h"
#include "CANNON.h"

CANNON::CANNON(GAME* game) :
    GAME_OBJECT(game),
    Cylinder(36, 0, -0.2f)
{
    Pos.set(-3, 0.8f, 0);
}

void CANNON::update()
{
    if (game()->stateIsMove()) {
        //移動方向を決める
        VECTOR dir(0, 0, 0);
        if (isPress(KEY_D)) { dir.x = 1; }
        if (isPress(KEY_A)) { dir.x = -1; }
        if (isPress(KEY_W)) { dir.z = -1; }
        if (isPress(KEY_S)) { dir.z = 1; }
        if (dir.x != 0 || dir.z != 0) {
            dir.normalize();
            MATRIX rot;
            rot.rotateY(game()->camera()->longitude());
            dir = rot * dir;
            //移動
            Pos += dir * 0.05f;
            //回転
            rotate(dir, 0.25f);
        }
        //next
        if (isTrigger(KEY_Z)) {
            game()->changeStateToRotate();
        }
    }

    if (game()->stateIsRotate()) {
        //dirへ向ける
        VECTOR dir = game()->satellite1()->pos() - Pos;
        //回転が終了、かつ、キーが押された
        if (rotate(dir, 0.05f)) {
            print("発射準備完了");
            if (isTrigger(KEY_Z)) {
                game()->changeStateToFly();
            }
        }
    }

    if (game()->stateIsRotateBack()) {
        if (rotate(VECTOR(0, 0, 1), 0.05f) &&
            game()->satellite1()->finished() &&
            game()->satellite2()->finished()) {
            game()->changeStateToMove();
        }
    }

    Master.identity();
    Master.mulTranslate(Pos.x, Pos.y, Pos.z);
    Master.mulRotateY(Angle.y);
    WheelL.identity();
    WheelL.mulTranslate(0.5f, -0.3f, 0);
    WheelL.mulRotateY(-1.57f);
    WheelR.identity();
    WheelR.mulTranslate(-0.5f, -0.3f, 0);
    WheelR.mulRotateY(1.57f);
    BarrelMat.identity();
    BarrelMat.mulTranslate(0, 0, 0);
    BarrelMat.mulRotateX(Angle.x);
}

void CANNON::draw() 
{
    COLOR c = COLOR(150, 0, 150);
    COLOR cBody = COLOR(255, 150, 150);
    float ambient = 0.3f;
    WheelL = Master * WheelL;
    Cylinder.draw(WheelL, c,ambient);
    WheelR = Master * WheelR;
    Cylinder.draw(WheelR, c, ambient);
    BarrelMat = Master * BarrelMat;
    Barrel.draw(BarrelMat,cBody, ambient);
}


