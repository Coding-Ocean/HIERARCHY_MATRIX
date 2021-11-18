#pragma once
#include"OBJECT.h"
#include"SPHERE.h"
#include"CYLINDER.h"
#include"CUBE.h"
class SNOW_MAN : 
    public OBJECT{
public:
    SNOW_MAN(class GAME* game);
    ~SNOW_MAN();
    int setup();
    void update();
    void draw();
    VECTOR pos();
    struct DATA {
        VECTOR pos;
        VECTOR angle;
        float ambient;
    };
private:
    DATA Data;

    SPHERE Sphere;
    CUBE Cube;
    CYLINDER Cylinder;
    CYLINDER* TruncatedCone;

    /// <summary>
    /// 各パーツのモデリング行列
    /// </summary>
    MATRIX
        BodyMdl, HeadMdl, MouseMdl, EyeMdl, HatMdl;
    MATRIX
        Master,
            Body,
            Head,
                Mouse,
                EyeR,
                EyeL,
                Hat;
    float animAngle = 0;
};

