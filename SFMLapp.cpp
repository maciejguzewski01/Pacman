#include "SFMLapp.h"
#include <fstream>

//konstruktor 
SFMLapp::SFMLapp(Pacman & pacman_sfml, Board & board_sfml, Manager & manager_sfml): pacman_sfml(pacman_sfml), board_sfml(board_sfml), manager_sfml(manager_sfml)
{

 
  
   wall.setSize(sf::Vector2f(20,20));

  
   wall.setFillColor(sf::Color(128,128,128));

   std::vector < std::string > fontSearchPath {
    
        "../resources/Calibri.ttf",
    };
   bool fontLoaded=false;
   for(auto file: fontSearchPath)
   {
     fontLoaded=font1.loadFromFile(file);
     if(fontLoaded) break;
     std::cerr<<"CZCIONKA SIĘ NIE ŁADUJE!!!!"<<std::endl;
     exit(-1);
   }
   txt.setFont(font1);

   virus_t.loadFromFile("../resources/wirus.png");
   virus.setTexture(virus_t);
   virus.setScale(0.05,0.05);

   vaccine_t.loadFromFile("../resources/vaccine.png");
   vaccine.setTexture(vaccine_t);
   vaccine.setScale(0.025,0.025);

   heart_t.loadFromFile("../resources/heart.png");
   heart.setTexture(heart_t);
   heart.setScale(0.05,0.05);

   pacman_static.loadFromFile("../resources/pacman_static.png");
   pacman_north.loadFromFile("../resources/pacman_north.png");
   pacman_south.loadFromFile("../resources/pacman_south.png");
   pacman_east.loadFromFile("../resources/pacman_east.png");
   pacman_west.loadFromFile("../resources/pacman_west.png");
   pacman.setTexture(pacman_static);
   pacman.setScale(0.08,0.08);
}


//funkcja rysująca planszę 
void SFMLapp::draw_board(sf::RenderWindow & win)
{
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
             vaccine.setPosition(col*20-5,row*20);
              win.draw(vaccine);
         }
         
         if(board_sfml.is_any_virus_on_field(row,col))
         {
             
             virus.setPosition(col*20-25,row*20-4);
             win.draw(virus);

         }
         if(board_sfml.is_pacman_on_field(row,col))
         {
             if(clk.getElapsedTime().asSeconds()>0.1) 
             {
              pacman_icon_movment();
               clk.restart();
             }
             pacman.setPosition(col*20-45,row*20-12);
             win.draw(pacman);
            
         }
      }
      
  }
  
  
  for(int i=0;i<pacman_sfml.get_lives_number();++i)
  {
      heart.setPosition(20+i*30,560);
      win.draw(heart);
  }
  int procent;
  procent=100*(manager_sfml.get_score())/(board_sfml.get_total_vaccine_number());
  txt.setCharacterSize(25);
  txt.setFillColor(sf::Color::White);
  txt.setString("Zaszczepiono");
  txt.setPosition(190,560);
  win.draw(txt);
  txt.setString(std::to_string(procent)+"% populacji");
  txt.setPosition(330,560);
  win.draw(txt);
  txt.setString("Zdobyte punkty: "+std::to_string(manager_sfml.get_score()));
  txt.setPosition(550,560);
  win.draw(txt);
  
}

//odpowiada za symulowanie ruchu "poruszania szczęk" pacmana
void SFMLapp::pacman_icon_movment()
{
 Move_direction move;
 move=pacman_sfml.get_move_to();
 if(test==1) 
 {
     pacman.setTexture(pacman_static);
     test=0;
 }
 else 
 {
     if(move==NORTH) pacman.setTexture(pacman_north);
     else if(move==SOUTH) pacman.setTexture(pacman_south);
     else if(move==EAST) pacman.setTexture(pacman_east);
     else if(move==WEST) pacman.setTexture(pacman_west);
     test=1;
 }

}

//funkcja rysująca
void SFMLapp::draw(sf::RenderWindow & win)
{
    draw_board(win);

 manager_sfml.play(ANY);
 if(manager_sfml.is_pacman_alive()==false)
 {
     sf::RectangleShape r;
     r.setSize(sf::Vector2f(100,100));
     r.setPosition(0,0);
     r.setFillColor(sf::Color::Red);
     win.draw(r);
 }
     
}