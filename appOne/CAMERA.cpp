#include"input.h"
#include"mathUtil.h"
#include"GAME.h"
#include"MODEL.h"
#include "CAMERA.h"
CAMERA::CAMERA(class GAME* game)
    : OBJECT(game)
{
}

int CAMERA::setup()
{
    Data = game()->allData()->cameraData;

    Target[0] = game()->object(OBJ_ID::FLOOR);
    Target[1] = game()->object(OBJ_ID::BULLET);
    Target[2] = game()->object(OBJ_ID::SATELLITE1);
    Target[3] = game()->object(OBJ_ID::SATELLITE2);
    Target[4] = game()->object(OBJ_ID::ENEMY);

    return 0;
}

void CAMERA::update(){
    //経度（東西）
    if (isPress(KEY_J)) { Data.angle.y -= Data.rotSpeed; }
    if (isPress(KEY_L)) { Data.angle.y += Data.rotSpeed; }
    //緯度（南北）
    if (isPress(KEY_I)) { Data.angle.x += Data.rotSpeed; }
    if (isPress(KEY_K)) { Data.angle.x -= Data.rotSpeed; }
    //ズーム
    if (isPress(KEY_U)) { Data.distance -= Data.zoomSpeed; }
    if (isPress(KEY_O)) { Data.distance += Data.zoomSpeed; }
    if (Data.distance < 1.0f) { Data.distance = 1.0f; }
    //ターゲット変更
    if (isTrigger(KEY_C)) {
        ++Data.targetIdx %= 5;
        if (Data.targetIdx == 0) {
            Data.distance = 17;
        }
        else {
            Data.distance = 6;
        }
    }
    TargetPos = Target[Data.targetIdx]->pos();
    //カメラ位置（３D極座標）
    Data.pos.x = sin(Data.angle.y) * cos(Data.angle.x) * Data.distance + TargetPos.x;
    Data.pos.y =                     sin(Data.angle.x) * Data.distance + TargetPos.y;
    Data.pos.z = cos(Data.angle.y) * cos(Data.angle.x) * Data.distance + TargetPos.z;
    UpVec.y = cos(Data.angle.x);
    MODEL::view.camera(Data.pos, TargetPos, UpVec);
#ifdef _DEBUG
    print((let)"Data.angle.y=" + Data.angle.y);
    print((let)"Data.angle.x=" + Data.angle.x);
    print((let)"Data.distance=" + Data.distance);
#endif
}

VECTOR CAMERA::angle() {
    return Data.angle;
}
