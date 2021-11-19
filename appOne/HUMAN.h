#pragma once
#include "OBJECT.h"
#include "CUBE.h"
#include "MATRIX.h"
class HUMAN : 
    public OBJECT
{
public:
    HUMAN(class GAME* game, OBJ_ID objId = OBJ_ID::NUM_OBJECTS);
    int setup();
    void update();
    void draw();
    VECTOR pos();
public:
    struct DATA {
        VECTOR pos;
        float animSpeed;
        COLOR c1, c2, c3, c4, c5;
        float ambient;
    };
private:
    DATA Data;

    CUBE Cube;
    //上半身のパーツモデリング用マトリックス
    MATRIX BodyModel, NeckModel, HeadModel,
        MouseModel, EyeModel, HairModel,
        Arm1Model, Arm2Model;
    //下半身パーツモデリング用マトリックス
    MATRIX WaistModel, Leg1Model, Leg2Model;
    //階層行列
    MATRIX
        Master,
            Body,
                Neck,
                    Head,
                        Mouse,
                        EyeR,
                        EyeL,
                        Hair,
                Arm1R,
                    Arm2R,
                Arm1L,
                    Arm2L,
            Waist,
                Leg1R,
                    Leg2R,
                Leg1L,
                    Leg2L;
    //汎用アングル
    float AnimAngle = 0;
};
