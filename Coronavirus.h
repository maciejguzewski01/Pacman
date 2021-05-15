#ifndef CORONAVIRUS_H
#define CORONAVIRUS_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Pacman.h"

//TA KLASA JEST MATEMATYCZNĄ REPREZENTACJĄ KORONAWIRUSA (duchy)


class Coronavirus
{
  const int number;
  sf::Vector2f position;
  

  public:
  explicit Coronavirus(int nr);

  sf::Vector2f get_position() const;
  void move(Move_direction direction);
  sf::Vector2f get_next_field_location(Move_direction direction);
  

};



#endif