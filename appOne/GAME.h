#pragma once
#include <vector>
#include "ALL_DATA.h"
class GAME
{
//Custom for this app.
private:
    enum STATE { MOVE, ROTATE, FLY, ROTATE_BACK };
    STATE State;
public:
    ALL_DATA allData;
    int create();
    enum class OBJ {
        CAMERA, PROJECTOR, LIGHT, FLOOR, CANNON, BULLET,
        SATELLITE1, SATELLITE2, ENEMY, SNOW_MAN, HUMAN, NUM_OBJECTS
    };
    class OBJECT* object(OBJ id);//getter

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
    int AddObject(OBJ id, class OBJECT*);
public:
    GAME();
    ~GAME();
    void run();
};

