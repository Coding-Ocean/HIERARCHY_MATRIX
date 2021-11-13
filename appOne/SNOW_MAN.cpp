#include"GAME.h"
#include "SNOW_MAN.h"

SNOW_MAN::SNOW_MAN(GAME* game):
    GAME_OBJECT(game),
    TruncatedCone(36,0,-1,0.5f,0.3f)
{
    BodyMdl.identity();
    HeadMdl.scaling(0.7f,0.7f,0.7f);
    MouseMdl.scaling(0.1f, 0.05f, 0.1f);
    EyeMdl.scaling(0.1f, 0.1f, 0.1f);
    HatMdl.identity();
    HatMdl.scaling(0.3f, 0.3f, 0.3f);
    HatMdl.mulRotateX(1.57f);
}

void SNOW_MAN::update()
{
    if (game()->stateIsMove()) {
        //VECTOR newPos;
        //newPos.x = sin(Theta) * 3;
        //newPos.z = cos(Theta) * 3;
        //newPos.y = 1;
        //Theta += 0.005f;

        //VECTOR b = newPos - Pos;
        //Pos += b;
        Pos.set(6, 1.2f, -3);

        //Angle.y += angleBetweenY(b) * 0.05f;
    }

    if (game()->stateIsRotate()) {
        VECTOR dir = game()->cannon()->pos() - Pos;;
        rotate(dir, 0.05f);
    }

    Master.translate(Pos.x, Pos.y, Pos.z);
    Master.mulRotateY(Angle.y);
    Body.translate(0, 0.5f-1.2f, 0);
    Head.rotateZ(0.1f * sin(angle));
    Head.mulTranslate(0, 0.7f, 0);
    Mouse.translate(0, -0.15f, 0.3f);
    EyeL.translate(0.1f, 0, 0.3f);
    EyeR.translate(-0.1f, 0, 0.3f);
    Hat.rotateZ(0.2f);
    Hat.mulTranslate(0, 0.3f, 0);
    angle += 0.017f;
}

void SNOW_MAN::draw()
{

    Body = Master * Body;
    Sphere.draw(Body * BodyMdl);
    
    Head = Body * Head;
    Sphere.draw(Head * HeadMdl);
    
    Mouse = Head * Mouse;
    Cube.draw(Mouse * MouseMdl, COLOR(0, 0, 0));
    
    EyeL = Head * EyeL;
    Cylinder.draw(EyeL * EyeMdl, COLOR(0, 0, 0));
    
    EyeR = Head * EyeR;
    Cylinder.draw(EyeR * EyeMdl, COLOR(0, 0, 0));
    
    Hat = Head * Hat;
    TruncatedCone.draw(Hat*HatMdl, COLOR(255, 0, 0));
}
