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
#include "Bonus.h"


class Events
{
   Pacman & pacman_e;
   Board & board_e;
   Bonus & bonus_e;
   Manager & manager_e;
   SFMLapp & sfml_e;
   
   void   mouse_bonus(sf::Event event);
   void mouse_results(sf::Event event);
  public:
  explicit Events(Pacman & pacman_e, Board & board_e,Bonus & bonus_e,Manager & manager_e,SFMLapp & sfml_e);
  void key_was_pressed(sf::Event event);
  void  mouse_was_pressed(sf::Event event);
  void mouse_died(sf::Event event);
  
};

#endif