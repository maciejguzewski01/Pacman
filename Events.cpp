#include "Events.h"
#include <iostream>

//konstruktor
Events::Events(Pacman & pacman_e, Board & board_e,Bonus & bonus_e, Manager & manager_e,SFMLapp & sfml_e): pacman_e(pacman_e), board_e(board_e),bonus_e(bonus_e), manager_e(manager_e), sfml_e(sfml_e) 
{
    
}


void Events::key_was_pressed(sf::Event event)
{
     
  if(event.key.code==sf::Keyboard::Left)
  {
    
    manager_e.play(WEST);
  }
  else if(event.key.code==sf::Keyboard::Right)
  {
    manager_e.play(EAST);
  } 
  else if(event.key.code==sf::Keyboard::Up)
  {
    manager_e.play(NORTH);
  }
  else if(event.key.code==sf::Keyboard::Down)
  {
     
    manager_e.play(SOUTH);
   
  }
   
}