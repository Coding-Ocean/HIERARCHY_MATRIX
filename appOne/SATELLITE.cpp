#include "GAME.h"
#include "SATELLITE.h"
int SATELLITE::Num = 0;

SATELLITE::SATELLITE(class GAME* game) 
    :GAME_OBJECT(game)
    ,Cylinder(36, 0, -1.5f)
{
    Ambient = 0.4f;
    BodyColor.set(255, 255, 0);
    SquareColor.set(255, 200, 60);
    WingModel.scaling(0.7f, 1.1f, 1.0f);
    AdvSpeed = 0.01f;

    Id = Num;
    if (Id == 0) {
        Pos.set(4, 5, 0);
    }
    else{
        Pos.set(-4, 6, 0);
    }

    Num++;
}

void SATELLITE::update()
{
    //move
    if (game()->stateIsMove()) {
        Pos.z = sin(AngleForPos) * 5;
        if (Id == 0) {
            AngleForPos += AdvSpeed;
        }
        else {
            AngleForPos += -AdvSpeed;
        }
        finishRotating = 0;
    }

    //rotate
    if (game()->stateIsRotate()) {
        //‚±‚ê‚©‚çŒü‚­•ûŒüdir
        VECTOR a,b,dir;
        if (Id == 0) {
            a = game()->object(GAME::OBJ::CANNON)->pos() - Pos;
            b = game()->object(GAME::OBJ::SATELLITE2)->pos() - Pos;
        }
        else {
            a = game()->object(GAME::OBJ::SATELLITE1)->pos() - Pos;
            b = game()->object(GAME::OBJ::ENEMY)->pos() - Pos;
        }
        a.normalize();
        b.normalize();
        dir = a + b;
        //‰ñ“]
        if (rotate(dir, 0.05f)) {
            finishRotating = 1;
        }
    }

    if (game()->stateIsFly()) {
        finishRotating = 0;
    }

    //rotateBack
    if (game()->stateIsRotateBack()) {
        //‰ñ“]
        if (rotate(VECTOR(0,0,1), 0.05f)) {
            finishRotating = 1;
        }
    }

    //create matrix
    Ref.translate(0, 0, 0.001f);
    Ref.mulRotateZ(AnimAngle);
    Ref.mulScaling(1.1f, 1.1f, 0.0f);
    WingL.translate( 0.85f, 0, -1.0f);
    WingL.mulRotateX(AnimAngle);
    WingR.translate(-0.85f, 0, -1.0f);
    WingR.mulRotateX(AnimAngle);
    AnimAngle += 0.017f;
}

void SATELLITE::draw()
{
    Master.translate(Pos.x, Pos.y, Pos.z);
    Master.mulRotateY(Angle.y);
    Master.mulRotateX(Angle.x);

    Cylinder.draw(Master,BodyColor,Ambient);
    
    Ref = Master * Ref;
    Square.draw(Ref,SquareColor,Ambient);

    WingL = Master * WingL;
    Square.draw(WingL*WingModel,SquareColor,Ambient);

    WingR = Master * WingR;
    Square.draw(WingR*WingModel, SquareColor, Ambient);
}

int SATELLITE::finished()
{
    return finishRotating;
}
