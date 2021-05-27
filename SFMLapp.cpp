#include "SFMLapp.h"
#include <fstream>

//konstruktor 
SFMLapp::SFMLapp(Pacman & pacman_sfml, Board & board_sfml,Bonus & bonus_sfml, Manager & manager_sfml): pacman_sfml(pacman_sfml), board_sfml(board_sfml), bonus_sfml(bonus_sfml), manager_sfml(manager_sfml)
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

   bell_t.loadFromFile("../resources/bonus_icons/bell.png");
   bell.setTexture(bell_t);
   bell.setScale(0.06,0.06);
   
   sun_t.loadFromFile("../resources/bonus_icons/sun.png");
   sun.setTexture(sun_t);
   sun.setScale(0.1,0.1);

   red_cross_t.loadFromFile("../resources/bonus_icons/red_cross.png");
   red_cross.setTexture(red_cross_t);
   red_cross.setScale(0.07,0.07);

   lite_lockdown_t.loadFromFile("../resources/bonus_icons/lite_lockdown.png");
   lite_lockdown.setTexture(lite_lockdown_t);
   lite_lockdown.setScale(0.04,0.04);

   lockdown_t.loadFromFile("../resources/bonus_icons/lockdown.png");
   lockdown.setTexture(lockdown_t);
   lockdown.setScale(0.04,0.04);

   tea_t.loadFromFile("../resources/bonus_icons/tea.png");
   tea.setTexture(tea_t);
   tea.setScale(0.04,0.04);
   
   antivaxx_t.loadFromFile("../resources/bonus_icons/antivaxx.png");
   antivaxx.setTexture(antivaxx_t);
   antivaxx.setScale(0.05,0.05);

   grave_t.loadFromFile("../resources/bonus_icons/grave.png");
   grave.setTexture(grave_t);
   grave.setScale(0.07,0.07);

   barrier_t.loadFromFile("../resources/bonus_icons/barrier.png");
   barrier.setTexture(barrier_t);
   barrier.setScale(0.07,0.07);

   plane_t.loadFromFile("../resources/bonus_icons/plane.png");
   plane.setTexture(plane_t);
   plane.setScale(0.04,0.04);

   
   pacman_uniform_t.loadFromFile("../resources/bonus_icons/pacman_uniform.png");
   pacman_uniform.setTexture(pacman_uniform_t);
   pacman_uniform.setScale(0.08,0.08);

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
         else if(board_sfml.is_bonus_on_field(row,col))
         {
           draw_bonus(row,col,win);
            
            
         }
         
         if(board_sfml.is_any_virus_on_field(row,col))
         {
             
             virus.setPosition(col*20-25,row*20-4);
             win.draw(virus);

         }
         if(board_sfml.is_pacman_on_field(row,col))
         {
             
             if(clk.getElapsedTime().asSeconds()>0.2) 
             {
              pacman_icon_movment();
               clk.restart();
             }
             
            if(manager_sfml.get_uniform_state()==true)
             {
                 pacman_uniform.setPosition(col*20,row*20);
                 win.draw(pacman_uniform);
             }
             else 
             {
                pacman.setPosition(col*20-45,row*20-12);
                win.draw(pacman);
             }
         }
      }
      
  }
  
  
  for(int i=0;i<pacman_sfml.get_lives_number();++i)
  {
      heart.setPosition(20+i*30,560);
      win.draw(heart);
  }
  int procent;
  procent=100*(manager_sfml.get_done_vaccine_number())/(board_sfml.get_total_vaccine_number());
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



//rysowanie bonusu
void SFMLapp::draw_bonus(int row,int col, sf::RenderWindow & win)
{
  Bonus_type bonus=bonus_sfml.get_type_of_bonus(row, col);
 if(bonus==NONE) return;
  if(bonus==SCHOOL) 
  {
      bell.setPosition(col*20-32,row*20-8);
      win.draw(bell);
  }
  else if(bonus==PLANE)
  {
      plane.setPosition(col*20,row*20);
      win.draw(plane);
  }
  else if(bonus==BORDER)
  {
      
      barrier.setPosition(col*20,row*20);
      win.draw(barrier);
  }
  else if(bonus==BRITAIN)
  {
      tea.setPosition(col*20-18,row*20-2);
      win.draw(tea);
  }
  else if(bonus==RESPIRATOR)
  {
      red_cross.setPosition(col*20-33.5,row*20-9);
      win.draw(red_cross);
  }
  else if(bonus==LOCKDOWN)
  {
      lockdown.setPosition(col*20-18,row*20-5);
      win.draw(lockdown);
  }
  else if(bonus==SUMMER)
  {
      sun.setPosition(col*20-45,row*20-23);
      win.draw(sun);
  }
  else if(bonus==LITE_LOCKDOWN)
  {
      lite_lockdown.setPosition(col*20-17,row*20-5);
      win.draw(lite_lockdown);
  }
  else if(bonus==DEATH)
  {
      grave.setPosition(col*20+3,row*20+2);
      win.draw(grave);
  }
  else if(bonus==ANTIVAXXERS)
  {
      antivaxx.setPosition(col*20,row*20);
      win.draw(antivaxx);
  }
}