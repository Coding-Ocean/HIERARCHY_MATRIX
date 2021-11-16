#pragma once
#include <vector>
#include "ALL_DATA.h"
class GAME
{
public:
    GAME();
    ~GAME();
    int setup();
    void run();

    //Data
    ALL_DATA allData;

    //Objects
    enum class OBJ_ID {
        CAMERA, PROJECTOR, LIGHT, FLOOR, CANNON, BULLET,
        SATELLITE1, SATELLITE2, ENEMY, SNOW_MAN, HUMAN, 
        NUM_OBJECTS
    };
    class OBJECT* object(OBJ_ID id);
    int addObject(OBJ_ID id, class OBJECT*);

    //States
    enum class STATE { MOVE, ROTATE, FLY, ROTATE_BACK };
    STATE state();
    void stateManager();
private:
    std::vector<class OBJECT*> Objects;
    STATE State;
    int Count;
};
