#pragma once
#include<vector>
class GAME
{
//Custom for this app.
private:
    int CannonIdx, BulletIdx, Satellite1Idx, Satellite2Idx, SnowManIdx, HumanIdx;
    enum STATE { MOVE, ROTATE };
    STATE State;
public:
    int create();
    class OBJECT* cannon();
    class OBJECT* bullet();
    class OBJECT* satellite1();
    class OBJECT* satellite2();
    class OBJECT* snowMan();
    class OBJECT* human();
    bool stateIsMove();
    bool stateIsRotate();
    void changeStateToMove();
    void changeStateToRotate();
//Framework
private:
    std::vector<class OBJECT*> Objects;
    int CreateObject(class OBJECT*);
public:
    GAME();
    ~GAME();
    void run();
};

