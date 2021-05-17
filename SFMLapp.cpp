#include "SFMLapp.h"

//konstruktor 
SFMLapp::SFMLapp(Pacman & pacman_sfml, Board & board_sfml, Manager & manager_sfml): pacman_sfml(pacman_sfml), board_sfml(board_sfml), manager_sfml(manager_sfml)
{

}




//funkcja rysująca
void SFMLapp::draw(sf::RenderWindow & win)
{
   sf::RectangleShape pacman;
   sf::RectangleShape wall;
   sf::RectangleShape virus;
   sf::CircleShape vaccine;

   pacman.setSize(sf::Vector2f(20,20));
   wall.setSize(sf::Vector2f(20,20));
   virus.setSize(sf::Vector2f(20,20));

   pacman.setFillColor(sf::Color(255,255,0));
   wall.setFillColor(sf::Color(160,160,160));
   virus.setFillColor(sf::Color(0,255,0));

   vaccine.setRadius(10);
   vaccine.setFillColor(sf::Color(255,0,127));
   
  
   for(int row=0;row<30;row++)
  {
      for(int col=0;col<40;col++)
      {
         
         if(board_sfml.is_wall_on_field(row,col))
         {
             wall.setPosition(col*20,row*20);
             win.draw(wall);
             continue;
         }
         else if(board_sfml.is_vaccine_on_field(row,col))
         {
             vaccine.setPosition(col*20,row*20);
             win.draw(vaccine);
         }
         
         if(board_sfml.is_any_virus_on_field(row,col))
         {
             
             virus.setPosition(col*20,row*20);
             win.draw(virus);

         }
         if(board_sfml.is_pacman_on_field(row,col))
         {
             pacman.setPosition(col*20,row*20);
             win.draw(pacman);
         }
      }
      
  }

  manager_sfml.play(ANY);
     
}