#include"GAME.h"
#include "SNOW_MAN.h"

SNOW_MAN::SNOW_MAN(GAME* game):
    GAME_OBJECT(game)
{
}

SNOW_MAN::~SNOW_MAN()
{
    SAFE_DELETE(TruncatedCone);
}

int SNOW_MAN::setup()
{
    Data = game()->allData.snowManData;

    TruncatedCone = new CYLINDER(36, 0, -1, 0.5f, 0.3f);

    BodyMdl.identity();
    HeadMdl.scaling(0.7f, 0.7f, 0.7f);
    MouseMdl.scaling(0.1f, 0.05f, 0.1f);
    EyeMdl.scaling(0.1f, 0.1f, 0.1f);
    HatMdl.scaling(0.3f, 0.3f, 0.3f);
    HatMdl.mulRotateX(1.57f);

    return 0;
}

void SNOW_MAN::update()
{
    if (game()->state() == GAME::STATE::MOVE) {
    }

    if (game()->state() == GAME::STATE::ROTATE) {
    }

    Master.translate(Data.pos.x, Data.pos.y, Data.pos.z);
    Master.mulRotateY(Data.angle.y);
    Body.translate(0, 0.5f-1.2f, 0);
    Head.rotateZ(0.1f * sin(animAngle));
    Head.mulTranslate(0, 0.7f, 0);
    Mouse.translate(0, -0.15f, 0.3f);
    EyeL.translate(0.1f, 0, 0.3f);
    EyeR.translate(-0.1f, 0, 0.3f);
    Hat.rotateZ(0.2f);
    Hat.mulTranslate(0, 0.3f, 0);
    animAngle += 0.017f;
}

void SNOW_MAN::draw()
{
    Body = Master * Body;
    Sphere.draw(Body * BodyMdl, COLOR(255,255,255), Data.ambient);
    
    Head = Body * Head;
    Sphere.draw(Head * HeadMdl, COLOR(255, 255, 255), Data.ambient);
    
    Mouse = Head * Mouse;
    Cube.draw(Mouse * MouseMdl, COLOR(0, 0, 0));
    
    EyeL = Head * EyeL;
    Cylinder.draw(EyeL * EyeMdl, COLOR(0, 0, 0));
    
    EyeR = Head * EyeR;
    Cylinder.draw(EyeR * EyeMdl, COLOR(0, 0, 0));
    
    Hat = Head * Hat;
    TruncatedCone->draw(Hat*HatMdl, COLOR(255, 0, 0));
}

VECTOR SNOW_MAN::pos()
{
    return Data.pos;
}
