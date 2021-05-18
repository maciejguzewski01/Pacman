#ifndef EVENTS_H
#define EVENTS_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>
#include "Pacman.h"
#include "Coronavirus.h"
#include "Board.h"
#include "Manager.h"
#include "SFMLapp.h"

class Events
{
   Pacman & pacman_e;
   Board & board_e;
   Manager & manager_e;
   SFMLapp & sfml_e;
  public:
  Events(Pacman & pacman_e, Board & board_e, Manager & manager_e,SFMLapp & sfml_e);
  void key_was_pressed(sf::Event event);
  
};

#endif