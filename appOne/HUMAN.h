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
    //�ėp�A���O��
    float angle = 0;
public:
    HUMAN(class GAME* game);
    void update();
    void draw();
};
