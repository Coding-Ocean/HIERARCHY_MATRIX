#include "GAME.h"
#include "SATELLITE.h"
int SATELLITE::Num = 0;

SATELLITE::SATELLITE(class GAME* game) 
    :OBJECT(game)
{
    Id = Num;
    Num++;
}

SATELLITE::~SATELLITE() {
    SAFE_DELETE(Cylinder);
}

int SATELLITE::setup()
{
    Data = game()->allData()->satelliteData[Id];

    Cylinder = new CYLINDER(36, 0, -1.5f);

    WingModel.scaling(0.7f, 1.1f, 1.0f);

    return 0;
}

void SATELLITE::update()
{
    if (objState() == OBJ_STATE::MOVE) {
        int fid = formationId();
        if (isTrigger(KEY_X)) {
            const FORMATION_DATA& fd = game()->allData()->formationData[fid];
            Data.pos = fd.satellitePos[Id];
        }

        if (fid == 0) {
            Data.pos.z = sin(AngleForPos) * Data.moveRange;
            AngleForPos += Data.advSpeed;
        }
    }

    if (objState() == OBJ_STATE::ROTATE) {
        //‚±‚ê‚©‚çŒü‚­•ûŒüdir
        //dir‚Íu”ò‚ñ‚Å—ˆ‚½•ûŒüav‚Æu”ò‚ñ‚Ås‚­•ûŒübv‚ð‚Q•ª‚µ‚½•ûŒü
        VECTOR a = game()->object(Data.preObjId)->pos() - Data.pos;
        VECTOR b = game()->object(Data.postObjId)->pos() - Data.pos;
        a.normalize();
        b.normalize();
        //a + b‚Å‚Q•ª‚µ‚½•ûŒü‚Æ‚È‚é
        VECTOR dir = a + b;
        //‰ñ“]
        rotate(&Data.angle, dir, Data.rotSpeed, Data.endOfRotationFlag);
    }

    if (objState() == OBJ_STATE::ROTATE_BACK) {
        //‰ñ“]
        VECTOR dir(0, 0, 1);
        rotate(&Data.angle, dir, Data.rotBackSpeed, Data.endOfRotationFlag);
    }

    Master.identity();
    Master.mulTranslate(Data.pos.x, Data.pos.y, Data.pos.z);
    Master.mulRotateY(Data.angle.y);
    Master.mulRotateX(Data.angle.x);
    Ref.identity();
    Ref.mulTranslate(0, 0, 0.001f);
    Ref.mulRotateZ(AnimAngle);
    Ref.mulScaling(1.1f, 1.1f, 1.0f);
    WingL.identity();
    WingL.mulTranslate(0.85f, 0, -1.0f);
    WingL.mulRotateX(AnimAngle);
    WingR.identity();
    WingR.mulTranslate(-0.85f, 0, -1.0f);
    WingR.mulRotateX(AnimAngle);
    AnimAngle += Data.animSpeed;
}

void SATELLITE::draw()
{
    Cylinder->draw(Master, Data.bodyColor, Data.ambient);
    Square.draw(Master * Ref, Data.squareColor, Data.refAmbient);
    Square.draw(Master * WingL * WingModel, Data.squareColor, Data.ambient);
    Square.draw(Master * WingR * WingModel, Data.squareColor, Data.ambient);
}

VECTOR SATELLITE::pos()
{
    return Data.pos;
}
