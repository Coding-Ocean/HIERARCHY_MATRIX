#pragma once
class GAME_OBJECT
{
    class GAME* Game = 0;
public:
    GAME_OBJECT(class GAME* game);
    class GAME* game();
};

