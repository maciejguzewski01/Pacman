#include "Manager.h"
#include <ctime>
#include <cstdlib>
#include <iostream>


//konstruktor 
Manager::Manager(Pacman pacman_m, Board & board_m): pacman_m(pacman_m), board_m(board_m)
{
    score=0;
    
    for(int i=0;i<board_m.get_number_of_viruses();++i)
    {
        viruses_directions.push_back(ANY);
    }
    generate_first_directions();

    
    
}

//generuje początkowe kierunki wirusów 
void Manager::generate_first_directions()
{
    for(int i=0;i<board_m.get_number_of_viruses();++i)
    {
        int number=rand()%4;
        if(number==0) viruses_directions[i]=NORTH;
        else if(number==1) viruses_directions[i]=SOUTH;
        else if(number==2) viruses_directions[i]=WEST;
        else  viruses_directions[i]=EAST;
    }
}

//zwraca prawdę jeśli pacman żyje
bool Manager::is_pacman_alive()
{
  if(pacman_m.get_lives_number()==0) return false;
  return true;
}


//steruje rozgrywką 
void Manager::play(Move_direction direction)
{
    if(is_pacman_alive()==true)
    {
      if(clk_pacman.getElapsedTime().asSeconds()>pacman_m.get_pacman_speed())
      {
       move_pacman( direction);
       clk_pacman.restart();
      }
      
      if(clk_viruses.getElapsedTime().asSeconds()>board_m.get_viruses_speed())
      {
       move_viruses( );
       clk_viruses.restart();
      }
      
      
    }
}



//zarządza ruchem pacmana
void Manager::move_pacman(Move_direction direction)
{
  
  
   if(pacman_meet_virus()==true) return;
   if(direction==ANY) return;
   if(board_m.can_pacman_move(direction)==false) return;
   if(pacman_meet_virus()==true) return;

     sf::Vector2f position=pacman_m.get_position();
     int row=position.x;
     int col=position.y;
     if(board_m.is_vaccine_on_field(row,col)==true)
     {
       score++;
       board_m.vaccinate(row,col);
     }



}


//sprawdza czy pacman i wirus spotkali się na polu i jeśli tak zmniejsza ilość żyć pacmana i wywołuje funkcję resetującą planszę 
bool Manager::pacman_meet_virus()
{
  sf::Vector2f position=pacman_m.get_position();
  int row=position.x;
  int col=position.y;
  if(board_m.is_any_virus_on_field(row,col)==true)
  {
      pacman_m.remove_live();
      board_m.reset();
      return true;
  }

  return false;
}


//zarządza ruchem wirusów 
void Manager::move_viruses( )
{
    
   for(int i=0;i<board_m.get_number_of_viruses();++i)
   {     
      

      while(board_m.can_virus_move(i,viruses_directions[i])==false)
      {
        int number=rand()%4;
        if(number==0) viruses_directions[i]=NORTH;
        else if(number==1) viruses_directions[i]=SOUTH;
        else if(number==2) viruses_directions[i]=WEST;
        else  viruses_directions[i]=EAST;
      }
      
        

       board_m.move_virus(i, viruses_directions[i]);
        if(pacman_meet_virus()==true) break;
   }
   
}


//zwraca ilość zdobytych punktów
int Manager::get_score() const
{
    return score;
}
