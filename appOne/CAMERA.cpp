#include"input.h"
#include"mathUtil.h"
#include"GAME.h"
#include"MODEL.h"
#include "CAMERA.h"
CAMERA::CAMERA(class GAME* game)
    : GAME_OBJECT(game)
{
}

int CAMERA::create()
{
    Data = game()->allData.cameraData;
    OBJECT::Angle = Data.angle;

    Target[0] = game()->object(GAME::OBJ::FLOOR);
    Target[1] = game()->object(GAME::OBJ::BULLET);
    Target[2] = game()->object(GAME::OBJ::SATELLITE1);// object(GAME::OBJ::SATELLITE1();
    Target[3] = game()->object(GAME::OBJ::SATELLITE2); //object(GAME::OBJ::SATELLITE2();
    Target[4] = game()->object(GAME::OBJ::ENEMY); //object(GAME::OBJ::ENEMY);

    return 0;
}

void CAMERA::update(){
    //経度（東西）
    if (isPress(KEY_J)) { Angle.y -= Data.rotSpeed; }
    if (isPress(KEY_L)) { Angle.y += Data.rotSpeed; }
    //緯度（南北）
    if (isPress(KEY_I)) { Angle.x += Data.rotSpeed; }
    if (isPress(KEY_K)) { Angle.x -= Data.rotSpeed; }
    //ズーム
    if (isPress(KEY_U)) { Data.distance -= Data.zoomSpeed; }
    if (isPress(KEY_O)) { Data.distance += Data.zoomSpeed; }
    if (Data.distance < 1.0f) { Data.distance = 1.0f; }
    //ターゲット変更
    if (isTrigger(KEY_C)) {
        ++TargetIdx %= 5;
        if (TargetIdx == 0) {
            Data.distance = 17;
        }
        else {
            Data.distance = 6;
        }
    }
    TargetPos = Target[TargetIdx]->pos();
    //カメラ位置（３D極座標）
    Pos.x = sin(Angle.y) * cos(Angle.x) * Data.distance + TargetPos.x;
    Pos.y =                sin(Angle.x) * Data.distance + TargetPos.y;
    Pos.z = cos(Angle.y) * cos(Angle.x) * Data.distance + TargetPos.z;
    UpVec.y = cos(Angle.x);
    MODEL::view.camera(Pos, TargetPos, UpVec);
#ifdef _DEBUG
    print((let)"Angle.y=" + Angle.y);
    print((let)"Angle.x=" + Angle.x);
    print((let)"Data.distance=" + Data.distance);
#endif
}
