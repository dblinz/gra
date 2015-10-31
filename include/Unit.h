#ifndef UNIT_H
#define UNIT_H
#include <string>
#include "Field.h"

using namespace std;

class Field;

class Unit
{
    public:
        Unit();
        virtual ~Unit();
        Field* getField();
        void setField(Field* field);
        string getSymbol();
        void setSymbol(string symbol);
        void move(Field* field);

    protected:
    private:
        string symbol;
        Field* field;
};

#endif // UNIT_H
