#ifndef CORONAVIRUS_H
#define CORONAVIRUS_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

//TA KLASA JEST MATEMATYCZNĄ REPREZENTACJĄ KORONAWIRUSA (duchy)

class Coronavirus
{
  const int number;
  sf::Vector2f position;

  public:
  explicit Coronavirus(int nr);

  sf::Vector2f get_position() const;

};



#endif