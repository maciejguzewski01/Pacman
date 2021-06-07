#include "Events.h"
#include <iostream>

//konstruktor
Events::Events(Pacman & pac, Board & boa,Bonus & bon,Manager & man,SFMLapp & sfml): pacman_e(pac), board_e(boa),bonus_e(bon), manager_e(man), sfml_e(sfml) 
{
    
}



//obsługa sterowania strzałkami 
void Events::key_was_pressed(sf::Event event)
{
    if(sfml_e.get_sfml_app_state()!=GAME)
    {
        was_enter_pressed(event);
        return;
    } 

  
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


//jeśli wciśnięto enter przełącza aplikację do nastepnego trybu (jeśli to możliwe)
void Events::was_enter_pressed(sf::Event event)
{
   if(event.key.code!=sf::Keyboard::Enter) return;

   if(sfml_e.get_sfml_app_state()==INTRODUCTION) sfml_e.set_app_state(GAME);
   else if(sfml_e.get_sfml_app_state()==BONUS) 
   {
     manager_e.end_bonus();
      sfml_e.end_bonus();
   }
   else if(sfml_e.get_sfml_app_state()==DIED) sfml_e.set_app_state(RESULTS);
}

//wywoływanie odpowiedniej funkcji sterującej obsługującej kliknięcia myszką
void Events::mouse_was_pressed(sf::Event event)
{
  if(sfml_e.get_sfml_app_state()==INTRODUCTION) mouse_intro(event);
  else if(sfml_e.get_sfml_app_state()==BONUS) mouse_bonus(event);
  else if(sfml_e.get_sfml_app_state()==DIED) mouse_died(event);
  else if(sfml_e.get_sfml_app_state()==RESULTS) mouse_results(event);
}

//obsługa kliknięć w trybie intro
void Events::mouse_intro(sf::Event event)
{
    if(event.mouseButton.button==1) return; //prawy

  int x=event.mouseButton.x;
  int y=event.mouseButton.y;
  
  if((x>350)and(x<450)and(y>180)and(y<210))
  {
     sfml_e.set_app_state(GAME);
  }
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
