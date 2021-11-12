#pragma once
#include "GAME_OBJECT.h"
#include "OBJECT.h"
#include "CUBE.h"
#include "MATRIX.h"
class HUMAN : 
    public GAME_OBJECT,
    public OBJECT
{
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
    float angle = 0;
public:
    HUMAN(class GAME* game);
    void update();
    void draw();
};
