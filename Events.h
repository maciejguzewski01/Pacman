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


//Obsługa zdarzeń 
/* zadania
1. obsługa wpisywania tekstu 
2. obsługa myszy 
3. obsługa sterowania strzałkami
*/

class Events
{
   Pacman & pacman_e;
   Board & board_e;
   Bonus & bonus_e;
   Manager & manager_e;
   SFMLapp & sfml_e;
   
   void   mouse_bonus(sf::Event event);
   void mouse_results(sf::Event event);
   void mouse_intro(sf::Event event);
   void was_enter_pressed(sf::Event event);
  public:
  explicit Events(Pacman & pac, Board & boa,Bonus & bon,Manager & man,SFMLapp & sfml);
  void key_was_pressed(sf::Event event);
  void  mouse_was_pressed(sf::Event event);
  void mouse_died(sf::Event event);
  
};

#endif