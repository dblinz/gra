#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Field.h"

const int FIELDS_NUMBER = 64;

using namespace std;

class Board
{
    public:
        Board();
        virtual ~Board();
        void display ();
        Field* getField(int x, int y);
        vector<Field> fields;
    protected:
    private:
};

#endif // BOARD_H
