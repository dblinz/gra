#ifndef FIELD_H
#define FIELD_H
#include <string>
#include "Unit.h"

using namespace std;

class Unit;
class Field
{
    public:
        Field();
        virtual ~Field();
        Unit* getUnit();
        void setUnit(Unit* unit);
        bool isEmpty(Field* field);
    protected:
    private:
        Unit* unit;
};

#endif // FIELD_H
