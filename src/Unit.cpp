#include <string>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <vector>
#include "Unit.h"

using namespace std;

Unit::Unit()
{

}

Unit::~Unit()
{

}

Field* Unit::getField()
{
    return field;
}

void Unit::setField (Field* field)
{
    this->field=field;
}

string Unit::getSymbol()
{
    return symbol;
}

void Unit::setSymbol(string symbol)
{
    this->symbol=symbol;
}

void Unit::move(Field* field_nowe)
{
    if(field != NULL)
    {
        field->setUnit(0);
    }
    field = field_nowe;
}
