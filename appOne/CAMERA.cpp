#include"input.h"
#include"mathUtil.h"
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
void CAMERA::update(){
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
    CamPos.x = sin(Longitude) * cos(Latitude) * Radius;
    CamPos.y =                  sin(Latitude) * Radius;
    CamPos.z = cos(Longitude) * cos(Latitude) * Radius;
    CamPos.y += PosOffsetY;
    LookPos.y = PosOffsetY;
    UpVec.y = cos(Latitude);
    MODEL::view.camera(CamPos, LookPos, UpVec);
#ifdef _DEBUG
    print((let)"Longitude=" + Longitude);
    print((let)"Latitude=" + Latitude);
    print((let)"Radius=" + Radius);
    print((let)"PosOffsetY" + PosOffsetY);
#endif
}
