#pragma once
#include "OBJECT.h"
#include "CUBE.h"
#include "MATRIX.h"
class HUMAN : 
    public OBJECT
{
//functions
public:
    HUMAN(class GAME* game, OBJ_ID objId = OBJ_ID::NUM_OBJECTS);
    int setup();
    void update();
    void draw();
    VECTOR pos();
//data
public:
    struct DATA {
        VECTOR pos;
        float animSpeed;
        COLOR c1, c2, c3, c4, c5;
        float ambient;
    };
private:
    //data
    DATA Data;
    float AnimAngle = 0;
    //model
    CUBE Cube;
    //matrix
    //�㔼�g�̃p�[�c���f�����O�p�}�g���b�N�X
    MATRIX BodyModel, NeckModel, HeadModel,
        MouseModel, EyeModel, HairModel,
        Arm1Model, Arm2Model;
    //�����g�p�[�c���f�����O�p�}�g���b�N�X
    MATRIX WaistModel, Leg1Model, Leg2Model;
    //�K�w�s��
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
};
