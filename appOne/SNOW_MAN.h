#pragma once
#include"GAME_OBJECT.h"
#include"OBJECT.h"
#include"SPHERE.h"
#include"CYLINDER.h"
#include"CUBE.h"
class SNOW_MAN : public OBJECT,public GAME_OBJECT{
    SPHERE Sphere;
    CUBE Cube;
    CYLINDER Cylinder;
    CYLINDER TruncatedCone;

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
        Hat
        ;
    float angle = 0;
    float Theta = 0;//位置決め用アングル
public:
    SNOW_MAN(class GAME* game);
    void update();
    void draw();
};

