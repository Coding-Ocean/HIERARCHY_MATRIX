#pragma once
#include "GAME_OBJECT.h"
#include "OBJECT.h"
#include "CYLINDER.h"
#include "SQUARE.h"
class SATELLITE :
    public GAME_OBJECT,
    public OBJECT
{
    static int Num;
    int Id;
    CYLINDER Cylinder;
    SQUARE Square;
    MATRIX RefModel, WingModel;
    MATRIX Master, Ref, WingL, WingR;
    COLOR SquareColor, BodyColor;
    float Ambient = 0;
    float AnimAngle = 0;
    float AngleForPos = 0;
    float AdvSpeed = 0;
    int finishRotating = 0;
public:
    SATELLITE(class GAME* game);
    void update();
    void draw();
    int finished();
};

