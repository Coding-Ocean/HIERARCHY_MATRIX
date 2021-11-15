#pragma once
#include <vector>
#include "ALL_DATA.h"
class GAME
{
//Custom for this app.
private:
    int CameraIdx, FloorIdx, CannonIdx, BulletIdx, 
        Satellite1Idx, Satellite2Idx, 
        EnemyIdx, SnowManIdx, HumanIdx;
    enum STATE { MOVE, ROTATE, FLY, ROTATE_BACK };
    STATE State;
public:
    ALL_DATA allData;
    int create();
    class OBJECT* camera();
    class OBJECT* floor();
    class OBJECT* cannon();
    class OBJECT* bullet();
    class OBJECT* satellite1();
    class OBJECT* satellite2();
    class OBJECT* enemy();
    class OBJECT* snowMan();
    class OBJECT* human();
    bool stateIsMove();
    bool stateIsRotate();
    bool stateIsFly();
    bool stateIsRotateBack();
    void changeStateToMove();
    void changeStateToRotate();
    void changeStateToFly();
    void changeStateToRotateBack();
//Framework
private:
    std::vector<class OBJECT*> Objects;
    int AddObject(class OBJECT*);
public:
    GAME();
    ~GAME();
    void run();
};

