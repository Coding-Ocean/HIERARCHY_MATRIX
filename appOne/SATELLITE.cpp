#include "GAME.h"
#include "SATELLITE.h"
int SATELLITE::Num = 0;

SATELLITE::SATELLITE(class GAME* game) 
    :GAME_OBJECT(game)
{
    Id = Num;
    Num++;
}

SATELLITE::~SATELLITE() {
    SAFE_DELETE(Cylinder);
}

int SATELLITE::setup()
{
    Data = game()->allData.satelliteData[Id];

    Cylinder = new CYLINDER(36, 0, -1.5f);

    WingModel.scaling(0.7f, 1.1f, 1.0f);

    return 0;
}

void SATELLITE::update()
{
    if (game()->state() == GAME::STATE::MOVE) {
        Data.pos.z = sin(AngleForPos) * Data.moveRange;
        AngleForPos += Data.advSpeed;
    }

    if (game()->state() == GAME::STATE::ROTATE) {
        //これから向く方向dir
        //飛んで来た方向aと飛んで行く方向bを２分した方向dirを求める
        VECTOR a = game()->object(Data.preObjId)->pos() - Data.pos;
        VECTOR b = game()->object(Data.postObjId)->pos() - Data.pos;
        a.normalize();
        b.normalize();
        VECTOR dir = a + b;
        //回転
        finishRotating = rotate(&Data.angle, dir, Data.rotSpeed);
    }

    if (game()->state() == GAME::STATE::ROTATE_BACK) {
        //回転
        finishRotating = rotate(&Data.angle, VECTOR(0, 0, 1), Data.rotSpeed);
    }

    Master.translate(Data.pos.x, Data.pos.y, Data.pos.z);
    Master.mulRotateY(Data.angle.y);
    Master.mulRotateX(Data.angle.x);
    Ref.translate(0, 0, 0.001f);
    Ref.mulRotateZ(AnimAngle);
    Ref.mulScaling(1.1f, 1.1f, 0.0f);
    WingL.translate(0.85f, 0, -1.0f);
    WingL.mulRotateX(AnimAngle);
    WingR.translate(-0.85f, 0, -1.0f);
    WingR.mulRotateX(AnimAngle);
    AnimAngle += Data.animSpeed;
}

void SATELLITE::draw()
{
    
    Cylinder->draw(Master, Data.bodyColor, Data.ambient);
    Ref = Master * Ref;
    Square.draw(Ref, Data.squareColor, Data.ambient);
    WingL = Master * WingL;
    Square.draw(WingL * WingModel, Data.squareColor, Data.ambient);
    WingR = Master * WingR;
    Square.draw(WingR * WingModel, Data.squareColor, Data.ambient);
}

VECTOR SATELLITE::pos()
{
    return Data.pos;
}

int SATELLITE::finished()
{
    return finishRotating;
}
