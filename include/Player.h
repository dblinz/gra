#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Board.h"
#include "Unit.h"

using namespace std;

const int UNITS_NUMBER = 4;

class Player
{
    public:
        Unit units[UNITS_NUMBER];
        Player(string playerName);
        virtual ~Player();
        string getName();
        void init(Board* board);
        void decide(Board* board);
    protected:
    private:
        string name;
};

#endif // PLAYER_H
