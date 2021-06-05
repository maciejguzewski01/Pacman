#ifndef CORONAVIRUS_H
#define CORONAVIRUS_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Pacman.h"

//TA KLASA JEST MATEMATYCZNĄ REPREZENTACJĄ KORONAWIRUSA (duchy)
/* Zadania;
1. zna numer wirusa (dany przy inicjalizacji wirusa)
2. zna, modyfikuje i zwraca pozycję wirusa (w tym ustawia wirusa na zadanym polu)
*/


class Coronavirus
{
  const int number;
  sf::Vector2f position;
  

  public:
  explicit Coronavirus(int nr);

 //funkcje modyfikujące obiekt  
  void move(Move_direction direction);
  void set_position_to(int row,int col);

  //Funkcje zwracające informacje 
   sf::Vector2f get_position() const;
   sf::Vector2f get_next_field_location(Move_direction direction) const;
};



#endif