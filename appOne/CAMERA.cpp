#include"input.h"
#include"mathUtil.h"
#include"GAME.h"
#include"MODEL.h"
#include "CAMERA.h"
CAMERA::CAMERA(class GAME* game, float distance, float zoomSpeed)
    : GAME_OBJECT(game)
    , LookPos(0, 0, 0)
    , UpVec(0, 1, 0)
    , Longitude(0)//経度(東西)
    , Latitude(0.15f)//緯度(南北)
    , Speed(0.01f)
    , Radius(distance)
    , PosOffsetY(1.6f)
    ,ZoomSpeed(zoomSpeed)
{
}

void CAMERA::setTarget()
{
    Target[0] = game()->floor();
    Target[1] = game()->bullet();
    Target[2] = game()->satellite1();
    Target[3] = game()->satellite2();
    Target[4] = game()->snowMan();
}

void CAMERA::update(){
    if (isTrigger(KEY_C)) {
        ++TargetIdx %= 5;
        if (TargetIdx == 0) {
            Radius = 17;
        }
        else {
            Radius = 6;
        }
    }
    TargetPos = Target[TargetIdx]->pos();
    //経度（東西）
    if (isPress(KEY_J)) { Longitude -= Speed; }
    if (isPress(KEY_L)) { Longitude += Speed; }
    //緯度（南北）
    if (isPress(KEY_I)) { Latitude += Speed; }
    if (isPress(KEY_K)) { Latitude -= Speed; }
    //ズーム
    if (isPress(KEY_U)) { Radius -= ZoomSpeed; }
    if (isPress(KEY_O)) { Radius += ZoomSpeed; }
    if (Radius < 1.0f) { Radius = 1.0f; }
    //上下
    if (isPress(KEY_Y)) { PosOffsetY += Speed; }
    if (isPress(KEY_H)) { PosOffsetY -= Speed; }
    //カメラ位置（３D極座標）
    CamPos.x = sin(Longitude) * cos(Latitude) * Radius + TargetPos.x;
    CamPos.y =                  sin(Latitude) * Radius + TargetPos.y;
    CamPos.z = cos(Longitude) * cos(Latitude) * Radius + TargetPos.z;
    //CamPos.y += PosOffsetY;
    //TargetPos.y = PosOffsetY;
    UpVec.y = cos(Latitude);
    MODEL::view.camera(CamPos, TargetPos, UpVec);
#ifdef _DEBUG
    print((let)"Longitude=" + Longitude);
    print((let)"Latitude=" + Latitude);
    print((let)"Radius=" + Radius);
    print((let)"PosOffsetY" + PosOffsetY);
#endif
}
