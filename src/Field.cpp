#include "Field.h"

Field::Field()
{

}

Field::~Field()
{
    //dtor
}

Unit* Field::getUnit()
{
    return unit;
}

void Field::setUnit(Unit* unit)
{
    this->unit=unit;
}

bool Field::isEmpty(Field* field)
{
    if(field->getUnit()==NULL)
        return true;
    else
        return false;
}
