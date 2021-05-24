#include "Pacman.h"
#include <iostream>

//konstruktor 
Pacman::Pacman(std::string name) : name(name)
{
    position=sf::Vector2f(1,1);
    lives=3;
    speed=0.01;
    move_to=EAST;
}


//aktualizuje pozycję 
void Pacman::move(Move_direction direction)
{
    move_to=direction;
    
    if(direction==NORTH) position=position+sf::Vector2f(0,-1);
    else if(direction==SOUTH) position=position+sf::Vector2f(0,1);
    else if(direction==WEST) position=position+sf::Vector2f(-1,0);
    else if(direction==EAST) position=position+sf::Vector2f(1,0);
   
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


//zwraca lokalziację następnego pola na ktorym znajdzie się pacman idąc w danym kierunku
sf::Vector2f Pacman::get_next_field_location(Move_direction direction)
{
    if(direction==NORTH) return position+sf::Vector2f(0,-1);
    else if(direction==SOUTH) return position+sf::Vector2f(0,1);
    else if(direction==WEST) return position+sf::Vector2f(-1,0);
    else if(direction==EAST) return position+sf::Vector2f(1,0);
    else return position;
}



//zwraca ilość pozostałych żyć
int Pacman::get_lives_number()
{
    return lives;
}


//zwraca prędkość pacmana
double Pacman::get_pacman_speed()
{
    return speed;
}

//zmniejsza ilość żyć
void Pacman::remove_live()
{
    lives--;
}

//ustawia pacmana na danej pozycji
void Pacman::set_position_to(int row,int col)
{
    if((row<0)or(row>29)or(col<0)or(col>39)) exit(-1);
   position=sf::Vector2f(row,col);
}

//zwraca kierunek ostatniego ruchu pacmana
Move_direction Pacman::get_move_to()
{
    return move_to;
}