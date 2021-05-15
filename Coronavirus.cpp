#include "Coronavirus.h"

//konstruktor 
Coronavirus::Coronavirus(int nr): number(nr)
{
    position=sf::Vector2f(15,15+number);//nr wiersza- nr kolumny
}



//aktualizuje pozycję 
void Coronavirus::move(Move_direction direction)
{
    if(direction==NORTH) position=position+sf::Vector2f(-1,0);
    else if(direction==SOUTH) position=position+sf::Vector2f(1,0);
    else if(direction==WEST) position=position+sf::Vector2f(0,-1);
    else if(direction==EAST) position=position+sf::Vector2f(0,1);
    exit(-1);
}


//zwraca współrzędne na których znajduje się koronawirus
sf::Vector2f Coronavirus::get_position() const
{
    return position;
}

//zwraca lokalizację następnego pola na ktorym znajdzie się koronawirus idąc w danym kierunku
sf::Vector2f Coronavirus::get_next_field_location(Move_direction direction)
{
    if(direction==NORTH) return position+sf::Vector2f(-1,0);
    else if(direction==SOUTH) return position+sf::Vector2f(1,0);
    else if(direction==WEST) return position+sf::Vector2f(0,-1);
    else if(direction==EAST) position+sf::Vector2f(0,1);
    exit(-1);
}