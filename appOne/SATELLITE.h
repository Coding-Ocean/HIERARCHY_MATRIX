#pragma once
#include "GAME_OBJECT.h"
#include "OBJECT.h"
#include "CYLINDER.h"
#include "SQUARE.h"
class SATELLITE :
    public GAME_OBJECT,
    public OBJECT
{
public:
    SATELLITE(class GAME* game);
    ~SATELLITE();
    int setup();
    void update();
    void draw();
    VECTOR pos();
    struct DATA {
        VECTOR pos;
        VECTOR angle;
        float advSpeed;
        float rotSpeed;
        OBJ_ID preObjId;
        OBJ_ID postObjId;
        COLOR squareColor;
        COLOR bodyColor;
        float ambient;
        float refAmbient;
        float moveRange;
        float animSpeed;
        int finishFlag;
    };
private:
    static int Num;
    int Id;

    DATA Data;

    CYLINDER* Cylinder;
    SQUARE Square;
    MATRIX RefModel, WingModel;
    MATRIX Master, Ref, WingL, WingR;

    float AnimAngle = 0;
    float AngleForPos = 0;
};

