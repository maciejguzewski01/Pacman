#include "Pacman.h"

//konstruktor 
Pacman::Pacman(std::string name) : name(name)
{
    position=sf::Vector2f(1,1);
}


//aktualizuje pozycję 
void Pacman::move(Move_direction direction)
{
    if(direction==NORTH) position=position+sf::Vector2f(0,-1);
    else if(direction==SOUTH) position=position+sf::Vector2f(0,1);
    else if(direction==WEST) position=position+sf::Vector2f(-1,0);
    else position=position+sf::Vector2f(1,0);
}

//zwraca imię pacmana
std::string Pacman::get_name() const 
{
    return name;
}

//zwraca współrzędne na których znajduje się pacman
sf::Vector2f Pacman::get_position() const 
{
    return position;
}