#include "GAME.h"
#include "HUMAN.h"
HUMAN::HUMAN(class GAME* game)
    :GAME_OBJECT(game)
{
    //上半身パーツのモデリング
    BodyModel.scaling(0.4f, 0.4f, 0.25f);
    BodyModel.mulTranslate(0, 0.5f, 0);
    NeckModel.scaling(0.1f, 0.05f, 0.1f);
    NeckModel.mulTranslate(0, 0.5f, 0);
    HeadModel.scaling(0.2f, 0.25f, 0.2f);
    HeadModel.mulTranslate(0, 0.5f, 0);
    MouseModel.scaling(0.08f, 0.03f, 0.2f);
    EyeModel.scaling(0.02f, 0.02f, 0.2f);
    //mHairModel.scaling(0.22f, 0.15f, 0.25f);
    HairModel.scaling(0.25f, 0.15f, 0.25f);
    HairModel.mulTranslate(0, 0.5f, 0);
    Arm1Model.scaling(0.05f, 0.4f, 0.05f);
    Arm1Model.mulTranslate(0, -0.5f, 0);
    Arm2Model.scaling(0.049f, 0.4f, 0.05f);
    Arm2Model.mulTranslate(0, -0.5f, 0);
    //下半身パーツのモデリング
    WaistModel.scaling(0.3f, 0.2f, 0.2f);
    WaistModel.mulTranslate(0, -0.5f, 0);
    Leg1Model.scaling(0.05f, 0.5f, 0.05f);
    Leg1Model.mulTranslate(0, -0.5f, 0);
    Leg2Model.scaling(0.048f, 0.5f, 0.05f);
    Leg2Model.mulTranslate(0, -0.5f, 0);
}
void HUMAN::update() {
    if (game()->state() == GAME::STATE::MOVE) {
        Pos.x = 9;
        Pos.y = 0;
        Pos.z = 9;
        angle += 0.06f;
    }

    //回転係数
    float s = sin(angle);
    float c0_2 = 1 - cos(angle * 2);
    float s_ntoz = s < 0 ? 0 : s;
    float ns = -s;
    float ns_ntoz = ns < 0 ? 0 : ns;
    //行列をつくる
    Master.translate(Pos.x, Pos.y+0.01f + 0.1f * c0_2, Pos.z);

    Body.translate(0, 1.2f, 0);
    Body.mulRotateY(0.6f * ns);
    Body.mulRotateX(0.4f * c0_2);
    Neck.translate(0, 0.4f, 0);
    Neck.mulRotateY(0.4f * ns);
    Neck.mulRotateX(-0.4f * c0_2);
    Head.translate(0, 0.05f, 0);
    Head.mulRotateX(-0.f);
    Mouse.translate(0.0f, 0.05f, 0.005f);
    EyeR.translate(-0.04f, 0.15f, 0.005f);
    EyeL.translate(0.04f, 0.15f, 0.005f);
    Hair.translate(0, 0.16f, 0.0f);
    Hair.mulRotateX(-0.3f);
    Arm1R.translate(-0.225f, 0.4f, 0);
    Arm1R.mulRotateX(-0.9f * ns);
    Arm2R.translate(0.0f, -0.4f, 0);
    Arm2R.mulRotateX(-1.8f * ns_ntoz);
    Arm1L.translate(0.225f, 0.4f, 0);
    Arm1L.mulRotateX(-0.9f * s);
    Arm2L.translate(0.0f, -0.4f, 0);
    Arm2L.mulRotateX(-1.8f * s_ntoz);

    Waist.translate(0, 1.2f, 0);
    Waist.mulRotateX(0);
    Leg1R.translate(-0.1f, -0.2f, 0);
    Leg1R.mulRotateX(-0.9f * s_ntoz);
    Leg2R.translate(0, -0.5f, 0);
    Leg2R.mulRotateX(1.8f * s_ntoz);
    Leg1L.translate(0.1f, -0.2f, 0);
    Leg1L.mulRotateX(-0.9f * ns_ntoz);
    Leg2L.translate(0, -0.5f, 0);
    Leg2L.mulRotateX(1.8f * ns_ntoz);
}
void HUMAN::draw() {
    //色
    COLOR c1 = COLOR(62, 66, 163);
    COLOR c2 = COLOR(217, 169, 132);
    COLOR c3 = COLOR(0, 0, 0);
    COLOR c4 = COLOR(255, 100, 100);
    COLOR c5 = COLOR(220, 0, 0);
    float ambient = 0.7f;

    Body = Master * Body;
    Cube.draw(Body * BodyModel, c1, ambient);
    Neck = Body * Neck;
    Cube.draw(Neck * NeckModel, c2, ambient);
    Head = Neck * Head;
    Cube.draw(Head * HeadModel, c2, ambient);
    Cube.draw(Head * Mouse * MouseModel, c4, ambient);
    Cube.draw(Head * EyeR * EyeModel, c3, ambient);
    Cube.draw(Head * EyeL * EyeModel, c3, ambient);
    Cube.draw(Head * Hair * HairModel, c5, ambient);
    Arm1R = Body * Arm1R;
    Cube.draw(Arm1R * Arm1Model, c1, ambient);
    Cube.draw(Arm1R * Arm2R * Arm2Model, c2, ambient);
    Arm1L = Body * Arm1L;
    Cube.draw(Arm1L * Arm1Model, c1, ambient);
    Cube.draw(Arm1L * Arm2L * Arm2Model, c2, ambient);
    Waist = Master * Waist;
    Cube.draw(Waist * WaistModel, c1, ambient);
    Cube.draw(Waist * Leg1R * Leg1Model, c1, ambient);
    Cube.draw(Waist * Leg1R * Leg2R * Leg2Model, c2, ambient);
    Cube.draw(Waist * Leg1L * Leg1Model, c1, ambient);
    Cube.draw(Waist * Leg1L * Leg2L * Leg2Model, c2, ambient);
}
