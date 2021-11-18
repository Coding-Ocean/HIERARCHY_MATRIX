#pragma once
#include "OBJECT.h"
#include "CYLINDER.h"
#include "SQUARE.h"
class SATELLITE :
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
        float rotBackSpeed;
        OBJ_ID preObjId;
        OBJ_ID postObjId;
        COLOR squareColor;
        COLOR bodyColor;
        float ambient;
        float refAmbient;
        float moveRange;
        float animSpeed;
        int endOfRotationFlag;
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

