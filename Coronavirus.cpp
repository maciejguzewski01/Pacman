#include "Coronavirus.h"

//konstruktor 
Coronavirus::Coronavirus(int nr): number(nr)
{
    position=sf::Vector2f(35+number,29);
}

//zwraca współrzędne na których znajduje się koronawirus
sf::Vector2f Coronavirus::get_position() const
{
    return position;
}