#pragma once
#include"VECTOR.h"
#include "GAME_OBJECT.h"
#include "OBJECT.h"
class CAMERA :
    public GAME_OBJECT, 
    public OBJECT
{
    VECTOR CamPos;
    VECTOR LookPos;
    VECTOR UpVec;
    float Longitude = 0;//�o�x(����)
    float Latitude = 0;//�ܓx(��k)
    float Radius = 0;
    float Speed = 0;
    float PosOffsetY = 0;
    float ZoomSpeed = 0;
    OBJECT* Target[5];
    int TargetIdx = 0;
    VECTOR TargetPos;
public:
    CAMERA(class GAME* game, float distance=17, float zoomSpeed=0.1f);
    void setTarget();
    void update();
    float longitude() {
        return Longitude;
    }
};

