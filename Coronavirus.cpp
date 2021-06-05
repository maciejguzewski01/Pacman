#include "Coronavirus.h"
#include <iostream>

//konstruktor 
Coronavirus::Coronavirus(int nr): number(nr)
{
    position=sf::Vector2f(10+number+1,15);
}

//-------------------------------------------------
//FUNKCJE MODYFIKUJĄCE STAN OBIEKTU 

//aktualizuje pozycję 
void Coronavirus::move(Move_direction direction)
{
    if(direction==NORTH) position=position+sf::Vector2f(0,-1);
    else if(direction==SOUTH) position=position+sf::Vector2f(0,1);
    else if(direction==WEST) position=position+sf::Vector2f(-1,0);
    else if(direction==EAST) position=position+sf::Vector2f(1,0);
    else exit(-1);
}

//ustawia wirusa na danej pozycji
void Coronavirus::set_position_to(int row,int col)
{
    if((row<0)or(row>29)or(col<0)or(col>39)) exit(-1);
    position=sf::Vector2f(row,col);
}

//-------------------------------------------------
//FUNKCJE ZWRACAJĄCE INFORMACJE O WIRUSIE 

//zwraca lokalizację następnego pola na ktorym znajdzie się koronawirus idąc w danym kierunku
sf::Vector2f Coronavirus::get_next_field_location(Move_direction direction) const 
{
    
    if(direction==NORTH) return position+sf::Vector2f(0,-1);
    else if(direction==SOUTH) return position+sf::Vector2f(0,1);
    else if(direction==WEST) return position+sf::Vector2f(-1,0);
    else if(direction==EAST) return position+sf::Vector2f(1,0);
    exit(-1);
}

//zwraca współrzędne na których znajduje się koronawirus
sf::Vector2f Coronavirus::get_position() const
{
    return position;
}