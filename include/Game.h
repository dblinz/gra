#ifndef GAME_H
#define GAME_H
#include "Player.h"

class Game
{
    public:
        Game();
        virtual ~Game();
        void play();
    protected:
    private:
        Player *player;
        Player *opponent;
        Board *board;
};

#endif // GAME_H
