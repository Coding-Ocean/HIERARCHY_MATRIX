#pragma once
class GAME_POINTER
{
public:
    GAME_POINTER(class GAME* game);
    class GAME* game();
private:
    class GAME* Game = 0;
};

