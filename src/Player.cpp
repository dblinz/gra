#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "Player.h"

using namespace std;

int a,b,c,d;
int stan = 1;

Player::Player(string playerName)
{
this->name=playerName;

for(int i = 0; i<UNITS_NUMBER; i++){
    units[i].setField(NULL);
    units[i].setSymbol(playerName);}
}

Player::~Player()
{
    delete &units;
}

string Player::getName()
{
    return this->name;
}


void Player::init (Board* board)
{
//WYBOR POCZATKOWEGO USTAWIENIA PIONKOW NA PLANSZY
	for (int i = 0; i<UNITS_NUMBER; i++){

			board->display();
            cout<<"Gracz "<<getName()<<": Wybierz WOLNE pole na ktorym ustawisz pionek: "<<endl;
            cout<<"poziom ";cin>>b;
            cout<<"pion   ";cin>>a;


//JESLI WYBRANO WSPOLRZEDNE SPOZA PLANSZY - KONIEC GRY
			if(a<0 || a>sqrt(FIELDS_NUMBER) || b<0 || b>sqrt(FIELDS_NUMBER)){
                exit(0);}

//JESLI WYBRANE POLE JEST JUZ ZAJETE WYKONAJ PONOWNIE PRZEBIEG PETLI
            if(board->fields[(a-1)*sqrt(FIELDS_NUMBER)+b-1].isEmpty(&board->fields[(a-1)*sqrt(FIELDS_NUMBER)+b-1])==false){
                i=i-1;  continue;}

//PRZYPISZ POLU FIGURE, PRZYPISZ FIGURZE POLE
			else
                board->fields[(a-1)*sqrt(FIELDS_NUMBER)+b-1].setUnit(&units[i]);
                units[i].setField(&board->fields[(a-1)*sqrt(FIELDS_NUMBER)+b-1]);}}


void Player::decide (Board* board)
{
//WYBÓR POLA Z PIONKIEM
    board->display();
    while (stan){
        cout<<"Gracz "<<getName()<<": Wybierz figure do przesuniecia. Podaj wspolrzedne: "<<endl;
        cout<<"poziom ";cin>>d;
        cout<<"pion   ";cin>>c;

//JESLI WYBRANO WSPOLRZEDNE SPOZA PLANSZY - KONIEC GRY
        if(c<0 || c>sqrt(FIELDS_NUMBER) || d<0 || d>sqrt(FIELDS_NUMBER)){
            exit(0);}

//JESLI NA POLU NIE MA PIONKA LUB JEST, ALE NIE NALEZY DO GRACZA - POWTORZ PRZEBIEG PETLI
        if (board->getField(d-1,c-1)->isEmpty(board->getField(d-1,c-1))==true || (board->getField(d-1,c-1)->getUnit()->getSymbol())!= (this->getName()) ){
            stan=1;}

//ZAKONCZ PETLE
        else
            cout<<endl;
            stan=0;}
        stan = 1;


//WYBÓR POLA NA KTÓRE PRZESUNIEMY PIONEK
while(stan){
    int e,f;
    cout<<"Gracz "<<getName()<<": Podaj wspolrzedne pola na ktore chcesz sie ruszyc: "<<endl;
    cout<<"poziom ";cin>>f;
    cout<<"pion   ";cin>>e;
    if(e<0 || e>sqrt(FIELDS_NUMBER) || f<0 || f>sqrt(FIELDS_NUMBER)){
        exit(0);}

//CZY POLE NA KTORE CHCEMY SIE RUSZYC JEST PUSTE?
    if (board->getField(f-1,e-1)->isEmpty(board->getField(f-1,e-1))==true){

        //PIONEK PRZESTAJE WSKAZYWAC NA SWOJE POLE
            board->getField(c-1,d-1)->getUnit()->setField(0);

        //PIONEK WSKAZUJE NA NOWE POLE
            board->getField(c-1,d-1)->getUnit()->move(&board->fields[(e-1)*sqrt(FIELDS_NUMBER)+f-1]);

       //NOWE POLE WSKAZUJE NA PIONEK
            board->fields[(e-1)*sqrt(FIELDS_NUMBER)+f-1].setUnit(board->getField(c-1,d-1)->getUnit());
            board->fields[(e-1)*sqrt(FIELDS_NUMBER)+f-1].getUnit()->setSymbol(getName());

        //STARE POLE PRZESTAJE WSKAZYWAC NA PIONEK
            board->fields[(c-1)*sqrt(FIELDS_NUMBER)+d-1].setUnit(NULL);
            stan = 0;}
    else
        {stan = 1;
        cout<<"\nWYbrane pole nie jest wolne PODAJ WOLNE POLE\n"<<endl;}}
    stan = 1;
}
