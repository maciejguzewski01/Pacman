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




void Events::mouse_was_pressed(sf::Event event)
{
  if(sfml_e.get_sfml_app_state()==BONUS) mouse_bonus(event);
  else if(sfml_e.get_sfml_app_state()==DIED) mouse_died(event);
  else if(sfml_e.get_sfml_app_state()==RESULTS) mouse_results(event);
}



//obsługa kliknięć w trybie bonusów
void Events::mouse_bonus(sf::Event event)
{
   if(event.mouseButton.button==1) return; //prawy

  int x=event.mouseButton.x;
  int y=event.mouseButton.y;
  
  Bonus_type type=manager_e.get_active_bonus_type();
  if((x>300)and(x<500)and(y>530)and(y<580))
  {

      manager_e.end_bonus();
      sfml_e.end_bonus();
      if(type==PLANE) manager_e.reset_clk_uniform();
      else if(type==LOCKDOWN) manager_e.reset_clk_lockdown();
  }
}



//obsługa kliknięć w trybie died
void Events::mouse_died(sf::Event event)
{
    if(event.mouseButton.button==1) return; //prawy

  int x=event.mouseButton.x;
  int y=event.mouseButton.y;

  if((x>275)and(x<525)and(y>530)and(y<580))
  {
     sfml_e.set_app_state(RESULTS);
  }
}

//obsługa kliknięć w trybie RESULTS
void Events::mouse_results(sf::Event event)
{
   if(event.mouseButton.button==1) return; //prawy

  int x=event.mouseButton.x;
  int y=event.mouseButton.y;

  if((x>275)and(x<525)and(y>530)and(y<580))
  {
     
      sfml_e.end_game();
  }
}
