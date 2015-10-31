#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "Board.h"

using namespace std;

Board::Board()
{
//inicjalizacja planszy

    for (int i = 0; i < FIELDS_NUMBER; i++)
    {
        fields.push_back(Field());
        fields[i].setUnit(NULL);
    }
}


Board::~Board()
{
    delete &fields;
}



void Board::display() //petla do wyswietlania
{

    system("cls");
    cout<<"Gra dla dwoch graczy: Gracza x oraz Gracza o. Gracze wybieraja poczatkowe"<<endl;
    cout<<"ustawienie pionkow na planszy poprzez podanie ich wspolrzednych a nastepnie";
    cout<<" na  przemian wybieraja na ktore pole chca sie ruszyc. Wybor wspolrzednych spoza"<<endl;
    cout<<"przedzialu <1,8> konczy gre niezaleznie od etapu rozgrywki. "<<endl;
    cout<<endl;
    cout<<"    1   2   3   4   5   6   7   8  "<<endl;
    for (int k=0;k<sqrt(FIELDS_NUMBER);k++){
    cout<<"   -------------------------------  "<<endl;
    cout<<k+1;
    for (int l=0;l<sqrt(FIELDS_NUMBER);l++){
        if(fields[l*sqrt(FIELDS_NUMBER)+k].getUnit()==0)
        {
        cout<<" | "<<" ";
        }
        else
        cout<<" | "<<fields[l*sqrt(FIELDS_NUMBER)+k].getUnit()->getSymbol();
        }
        cout<<" | ";
        cout<<endl;}
    cout<<"   -------------------------------  "<<endl;
}

Field* Board::getField(int x, int y)
{
    return &fields [y*sqrt(FIELDS_NUMBER)+x];
}
