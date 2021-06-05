#include "SFMLapp.h"
#include <fstream>
#include <string>

//konstruktor 
SFMLapp::SFMLapp(Pacman & pacman_sfml, Board & board_sfml,Bonus & bonus_sfml, Manager & manager_sfml): pacman_sfml(pacman_sfml), board_sfml(board_sfml), bonus_sfml(bonus_sfml), manager_sfml(manager_sfml)
{

   state=INTRODUCTION;
  
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

   std::vector < std::string > fontSearchPath2 {
    
        "../resources/LibreBaskerville-Regular.ttf",
    };
   bool fontLoaded2=false;
   for(auto file: fontSearchPath2)
   {
     fontLoaded2=font2.loadFromFile(file);
     if(fontLoaded2) break;
     std::cerr<<"CZCIONKA SIĘ NIE ŁADUJE!!!!"<<std::endl;
     exit(-1);
   }
   txt2.setFont(font2);
txt2.setFillColor(sf::Color::Black);
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

//----------------------------------------
//FUNKCJE RYSUJĄCE

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
    if(state==INTRODUCTION) draw_introduction(win);
    if(manager_sfml.get_is_bonus_state()==true) state=BONUS; 

    if(state==BONUS) draw_bonus_info(win);
    else if(state==GAME)
    {
        draw_board(win);
        manager_sfml.play(ANY);
    }
    else if(state==DIED) draw_game_over(win);
    else if(state==RESULTS) draw_game_results(win);
          
  
  if(n==0)
  {
      if((manager_sfml.is_pacman_alive()==false)or(manager_sfml.all_vaccine_taken()==true))
      {
         state=DIED;
         ++n;
       }   
  }
}

//rysowanie widoku INTRODUCTION
void SFMLapp::draw_introduction(sf::RenderWindow & win)
{
    draw_board(win);

    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(1);
    rect.setPosition(100,30);
    rect.setSize(sf::Vector2f(600,200));
    rect.setFillColor(sf::Color(209,162,6));
    win.draw(rect);
    rect.setFillColor(sf::Color(0,153,0));
    rect.setSize(sf::Vector2f(100,30));
    rect.setPosition(350,180);
    win.draw(rect);
    txt2.setString("START");
    txt2.setCharacterSize(20);
    txt2.setPosition(360,185);
    win.draw(txt2);

    txt2.setString(L"1. Poruszaj pacmanem strzałkami");
    txt2.setPosition(200,50);
    win.draw(txt2);
    txt2.setString(L"2. Wyszczep całą populację");
    txt2.setPosition(230,80);
    win.draw(txt2);
    txt2.setString(L"3. Unikaj zakażenia koronawirusem");
    txt2.setPosition(200,110);
    win.draw(txt2);
    txt2.setString(L"4. Aktywuj bonusy");
    txt2.setPosition(290,140);
    win.draw(txt2);
}


//rysowanie widoku po śmierci 
void SFMLapp::draw_game_over(sf::RenderWindow & win)
{
   rect.setPosition(0,0);
   rect.setOutlineThickness(1);
   rect.setOutlineColor(sf::Color::Black);
   rect.setSize(sf::Vector2f(800,600));
   rect.setFillColor(sf::Color(209,162,6));
   win.draw(rect);
   if(manager_sfml.all_vaccine_taken()==false)
   {
       txt.setFillColor(sf::Color::Black);
       txt.setString("GAME OVER!");
       txt.setPosition(130,110);
       txt.setCharacterSize(100);
        win.draw(txt);
   }
   else 
   {
       txt.setFillColor(sf::Color::Black);
       txt.setString(L"Gratuluacje, wyszczepiono całą populację!");
       txt.setPosition(40,110);
       txt.setCharacterSize(40);
       win.draw(txt);
   }
   

   txt.setString(L"Podsumowanie;");
   txt.setPosition(250,240);
   txt.setCharacterSize(50);
   win.draw(txt);
   txt.setString("Zdobyto              "+std::to_string(manager_sfml.get_score()));
   txt.setPosition(110,300);
   txt.setCharacterSize(40);
   win.draw(txt);
   txt.setString(L" punktów");
   txt.setPosition(480,300);
   txt.setCharacterSize(40);
   win.draw(txt);
   txt.setString("Zaszczepiono     "+std::to_string(100*(manager_sfml.get_done_vaccine_number())/(board_sfml.get_total_vaccine_number())));
   txt.setPosition(110,350);
   txt.setCharacterSize(40);
   win.draw(txt);
   txt.setString(L" % populacji");
   txt.setPosition(480,350);
   txt.setCharacterSize(40);
   win.draw(txt);
    win.draw(back);
  back.setSize(sf::Vector2f(250,50));
  back.setPosition(275,530);
  back.setFillColor(sf::Color::Green);
  back.setOutlineColor(sf::Color::Black);
  back.setOutlineThickness(1);
  win.draw(back);
  txt.setFillColor(sf::Color::Black);
  txt.setString(L"Porównaj wyniki");
  txt.setCharacterSize(30);
  txt.setPosition(290,535);
  win.draw(txt);
}


//rysowanie widoku RESULTS 
void SFMLapp::draw_game_results(sf::RenderWindow & win)
{
    rect.setPosition(0,0);
   rect.setOutlineThickness(1);
   rect.setOutlineColor(sf::Color::Black);
   rect.setSize(sf::Vector2f(800,600));
   rect.setFillColor(sf::Color(209,162,6));
   win.draw(rect);
   txt2.setString(L"Zobacz jak poradzili sobie ministrowie w równoległych wszechświatach!");
   txt2.setCharacterSize(20);
   txt2.setPosition(30,30);
   win.draw(txt2);

if(nr==0)
 {
    std::ifstream plik("../wyniki.txt");
  if(!plik)
  {
    std::cerr<<"Błąd: "<<strerror(errno)<<std::endl;
    exit(-1);
  }
    int idx=0;
    while(plik)
    {
      results.push_back("");    
      getline(plik, results[idx]);
    idx++;
    }
   plik.close();
   nr++;
 }
  
   back.setSize(sf::Vector2f(600,3));
   back.setFillColor(sf::Color::Black);
   sf::RectangleShape r;
   r.setSize(sf::Vector2f(3,40));
   r.setFillColor(sf::Color::Black);

   
  
   for(size_t i=0;i<results.size();++i)
   {
       txt2.setString(results[i]);
       txt2.setPosition(250,80+40*i);
       win.draw(txt2);
       back.setPosition(100,78+40*i);
       win.draw(back);
       if(i==results.size()-1) break;
       r.setPosition(100,78+40*i);
       win.draw(r);
       r.setPosition(700,78+40*i);
       win.draw(r);
   }

   back.setSize(sf::Vector2f(250,50));
  back.setPosition(275,530);
  back.setFillColor(sf::Color::Green);
  back.setOutlineColor(sf::Color::Black);
  back.setOutlineThickness(1);
  win.draw(back);
  txt.setFillColor(sf::Color::Black);
  txt.setString(L"Złóż dymisję");
  txt.setCharacterSize(30);
  txt.setPosition(330,535);
  win.draw(txt);

  if(end==true) win.close();
 
}




//rysowanie ikonki bonusu
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



//funkcja przekierowująca do rysowania widoku odpowiedniego bonusu 
void SFMLapp::draw_bonus_info(sf::RenderWindow & win)
{
  back.setPosition(0,0);
  back.setSize(sf::Vector2f(800,600));
  back.setFillColor(sf::Color(209,162,6));
  win.draw(back);
  back.setSize(sf::Vector2f(200,50));
  back.setPosition(300,530);
  back.setFillColor(sf::Color::Green);
  back.setOutlineColor(sf::Color::Black);
  back.setOutlineThickness(1);
  win.draw(back);
  txt.setFillColor(sf::Color::Black);
  txt.setString("Kontynuuj");
  txt.setCharacterSize(30);
  txt.setPosition(335,535);
  win.draw(txt);
  Bonus_type type=manager_sfml.get_active_bonus_type();

  
  if(type==SCHOOL) draw_bonus_one_info(win);
  else if(type==PLANE) draw_bonus_two_info(win);
  else if(type==BORDER) draw_bonus_three_info(win);
  else if(type==BRITAIN) draw_bonus_four_info(win);
  else if(type==RESPIRATOR) draw_bonus_five_info(win);
  else if(type==LOCKDOWN) draw_bonus_six_info(win);
  else if(type==SUMMER) draw_bonus_seven_info(win);
  else if(type==LITE_LOCKDOWN) draw_bonus_eight_info(win);
  else if(type==DEATH) draw_bonus_nine_info(win);
  else if(type==ANTIVAXXERS) draw_bonus_ten_info(win);
}


//rysuje widok bonusu pierwszego 
void SFMLapp::draw_bonus_one_info(sf::RenderWindow & win)
{
    sf::Sprite help=bell;
    help.setScale(0.5,0.5);
    help.setPosition(30,-30);
    win.draw(help);

    txt2.setString(L"Otwarcie szkół!"); 
    txt2.setPosition(290,240);
     txt2.setCharacterSize(30);
    win.draw(txt2);
 
    txt2.setString(L"Wiadomość z Ministerstwa Edukacji i Nauki!");
   txt2.setCharacterSize(20);
    txt2.setPosition(190,280);
    win.draw(txt2);
    
    txt2.setString(L"Z dniem dzisiejszym we wszystkich placówkach oświatowych przywrócona"); 
    txt2.setPosition(20,330);
    win.draw(txt2);
    txt2.setString(L"zostaje stacjonarna forma nauczania.");
    txt2.setPosition(200,360);
    win.draw(txt2);
    txt2.setString(L"*Ilość wirusów wzrasta dwukrotnie*");
    txt2.setPosition(220,480);
    win.draw(txt2);
}


//rysuje widok bonusu drugiego
void SFMLapp::draw_bonus_two_info(sf::RenderWindow & win)
{
    sf::Sprite help=plane;
    help.setScale(0.5,0.5);
    help.setPosition(230,10);
    win.draw(help);
    txt2.setString(L"Przesyłka z Chin!");
    txt2.setCharacterSize(30);
    txt2.setPosition(260,230);
    win.draw(txt2);
    txt2.setCharacterSize(20);
    txt2.setString(L"Wiadomość z Agencji Rezerw Materiałowych!");
    txt2.setPosition(160,270);
    win.draw(txt2);
    txt2.setString(L"Na lotnisku wylądował właśnie największy samolot na świecie."); 
    txt2.setPosition(100,300);
    win.draw(txt2);
     txt2.setString(L"Przywiózł środki do walki z pandemią."); 
    txt2.setPosition(210,330);
    win.draw(txt2);
    txt2.setString(L"Otrzymujesz nowy kombinezon ochronny"); 
    txt2.setPosition(200,360);
    win.draw(txt2);
    txt2.setString(L"Niestety przy zakupach sortowaliśmy od najniższej ceny "); 
    txt2.setPosition(130,390);
    win.draw(txt2);
    txt2.setString(L"Więc będzie działał tylko przez 20 sekund"); 
    txt2.setPosition(200,420);
    win.draw(txt2);
    txt2.setString(L"*Przez 20 sekund jesteś odporny na wirusy*"); 
    txt2.setPosition(190,480);
    win.draw(txt2);
}

//rysuje widok bonusu trzeciego
void SFMLapp::draw_bonus_three_info(sf::RenderWindow & win)
{
    sf::Sprite help=barrier;
    help.setScale(0.5,0.5);
    help.setPosition(320,20);
    win.draw(help);
    txt2.setString(L"Otwarcie granic!");
    txt2.setCharacterSize(30);
    txt2.setPosition(250,200);
    win.draw(txt2);
     txt2.setString(L"Wiadomość z Urzędu Do Spraw Cudzoziemców!");
    txt2.setCharacterSize(20);
    txt2.setPosition(180,240);
    win.draw(txt2);
    txt2.setString(L"Przez otwarte granice odnotowaliśmy znaczny napływ niezaszczepionych ");
    txt2.setPosition(10,280);
    win.draw(txt2);
    txt2.setString(L"pracowników ze wschodu");
    txt2.setPosition(280,310);
    win.draw(txt2);
    txt2.setString(L"Musisz ich wyszczepić!");
    txt2.setPosition(290,350);
    win.draw(txt2);
    txt2.setString(L"*Musisz ponownie zebrać szczepionki ze wszystkich pól*");
    txt2.setPosition(110,480);
    win.draw(txt2);
}

//rysuje widok bonusu czwartego 
void SFMLapp::draw_bonus_four_info(sf::RenderWindow & win)
{
    sf::Sprite help=tea;
    help.setScale(0.4,0.4);
    help.setPosition(120,-30);
    win.draw(help);

    txt2.setString(L"Brytyjska herbatka!");
    txt2.setCharacterSize(30);
    txt2.setPosition(250,200);
    win.draw(txt2);
    txt2.setString(L"Wiadomość z Inspekcji Sanitarnej!");
    txt2.setCharacterSize(20);
    txt2.setPosition(230,240);
    win.draw(txt2);
    txt2.setString(L"Dominujący wariant koronawirusa to teraz tzw. wariant brytyjski");
    txt2.setPosition(80,280);
    win.draw(txt2);
    txt2.setString(L"Pandemia rozprzestrzenia się coraz szybciej");
    txt2.setPosition(200,310);
    win.draw(txt2);
    txt2.setString(L"*Wirusy przyśpieszają*");
    txt2.setPosition(280,480);
    win.draw(txt2);

}


//rysuje widok bonusu piątego 
void SFMLapp::draw_bonus_five_info(sf::RenderWindow & win)
{
     sf::Sprite help=red_cross;
    help.setScale(0.5,0.5);
    help.setPosition(90,-40);
    win.draw(help);

    txt2.setString(L"Respirator!");
    txt2.setCharacterSize(30);
    txt2.setPosition(300,200);
    win.draw(txt2);
    txt2.setString(L"Wiadomość ze Szpitala Narodowego!");
    txt2.setCharacterSize(20);
    txt2.setPosition(210,240);
    win.draw(txt2);
    txt2.setString(L"Otrzymałeś respirator, który pomoże Ci się zregenerować.");
    txt2.setPosition(80,280);
    win.draw(txt2);
    txt2.setString(L"*Liczba żyć zwiększa się do 4*");
    txt2.setPosition(240,480);
    win.draw(txt2);
}

//rysuje widok bonusu szóstego 
void SFMLapp::draw_bonus_six_info(sf::RenderWindow & win)
{
     sf::Sprite help=lockdown;
    help.setScale(0.4,0.4);
    help.setPosition(150,-60);
    win.draw(help);

    txt2.setString(L"Twardy lockdown!");
    txt2.setCharacterSize(30);
    txt2.setPosition(280,200);
    win.draw(txt2);
    txt2.setString(L"Wiadomość z Kancelarii Premiera!");
    txt2.setCharacterSize(20);
    txt2.setPosition(230,240);
    win.draw(txt2);
    txt2.setString(L"Z powodu pogarszającej się sytuacji wprowadzony zostaje twardy lockdown.");
    txt2.setPosition(10,280);
    win.draw(txt2);
    txt2.setString(L"Z powodów gospodarrczych może być utrzymany tylko przez 20 sekund.");
    txt2.setPosition(10,310);
    win.draw(txt2);
    txt2.setString(L"Uwaga: w trakcie lockdownu jeśli trafisz na wirusa wciąż możesz się zarazić!");
    txt2.setPosition(10,340);
    win.draw(txt2);
    txt2.setString(L"*Wirusy przez 20 sekund się nie ruszają*");
    txt2.setPosition(180,480);
    win.draw(txt2);
}

//rysuje widok bonusu siódmego 
void SFMLapp::draw_bonus_seven_info(sf::RenderWindow & win)
{
    sf::Sprite help=sun;
    help.setScale(0.7,0.7);
    help.setPosition(20,-130);
    win.draw(help);

    txt2.setString(L"Wirus w odwrocie!");
    txt2.setCharacterSize(30);
    txt2.setPosition(260,200);
    win.draw(txt2);
    txt2.setString(L"Wiadomość z Kancelarii Premiera!");
    txt2.setCharacterSize(20);
    txt2.setPosition(230,240);
    win.draw(txt2);
    txt2.setString(L"Ten wirus jest już w odwrocie!");
    txt2.setPosition(260,280);
    win.draw(txt2);
    txt2.setString(L"Idzie lato, a w lecie wirusy są słabsze!");
    txt2.setPosition(210,310);
    win.draw(txt2);
    txt2.setString(L"Ten wirus jest w odworcie, nie trzeba go się bać!");
    txt2.setPosition(150,340);
    win.draw(txt2);
    txt2.setString(L"*Wirusy wracają na pozycje startowe*");
    txt2.setPosition(200,480);
    win.draw(txt2);
}


//rysuje widok bonusu ósmego 
void SFMLapp::draw_bonus_eight_info(sf::RenderWindow & win)
{
     sf::Sprite help=lite_lockdown;
    help.setScale(0.4,0.4);
    help.setPosition(120,-30);
    win.draw(help);

    txt2.setString(L"Lekki lockdown!");
    txt2.setCharacterSize(30);
    txt2.setPosition(280,200);
    win.draw(txt2);
    txt2.setString(L"Wiadomość z Kancelarii Premiera!");
    txt2.setCharacterSize(20);
    txt2.setPosition(230,240);
    win.draw(txt2);
    txt2.setString(L"Pogarsza się sytuacja epidemiczna. ");
    txt2.setPosition(230,280);
    win.draw(txt2);
    txt2.setString(L"Powinniśmy wprowadzić lockdown ale gospodarka tego nie wytrzyma.");
    txt2.setPosition(20,310);
    win.draw(txt2);
    txt2.setString(L"Dlatego zamkniemy fryzjerów, szkoły o nieparzystych numerach, sklepy ");
    txt2.setPosition(10,340);
    win.draw(txt2);
    txt2.setString(L"budowlane oraz włoskie restauracje w większych miastach");
    txt2.setPosition(90,370);
    win.draw(txt2);
    txt2.setString(L"*Wirusy zmniejszają prędkość*");
    txt2.setPosition(230,480);
    win.draw(txt2);
}

//rysuje widok bonusu dziewiątego 
void SFMLapp::draw_bonus_nine_info(sf::RenderWindow & win)
{
   sf::Sprite help=grave;
    help.setScale(0.5,0.5);
    help.setPosition(350,30);
    win.draw(help);

    txt2.setString(L"Wzrost śmiertelności!");
    txt2.setCharacterSize(30);
    txt2.setPosition(250,200);
    win.draw(txt2);
    txt2.setString(L"Wiadomość z Polskiej Akademii Nauk!");
    txt2.setCharacterSize(20);
    txt2.setPosition(230,240);
    win.draw(txt2);
    txt2.setString(L"Nowa mutacja spowowdowała wzrost śmiertelności. ");
    txt2.setPosition(150,280);
    win.draw(txt2);
    txt2.setString(L"W konsekwencji przyspieszył przebieg zakażenia i zmniejszył się");
    txt2.setPosition(80,310);
    win.draw(txt2);
    txt2.setString(L" współczynnik R.");
    txt2.setPosition(310,340);
    win.draw(txt2);
    txt2.setString(L"Więc ilość zakażeń się zmniejszy. ");
    txt2.setPosition(260,370);
    win.draw(txt2);
    txt2.setString(L"*Ilość wirusów zmniejsza się*");
    txt2.setPosition(250,480);
    win.draw(txt2);
}


//rysuje widok bonusu dziesiątego 
void SFMLapp::draw_bonus_ten_info(sf::RenderWindow & win)
{
     sf::Sprite help=antivaxx;
    help.setScale(0.5,0.5);
    help.setPosition(330,10);
    win.draw(help);

    txt2.setString(L"Populacja antyszczepionkowców zwiększa się!");
    txt2.setCharacterSize(30);
    txt2.setPosition(50,200);
    win.draw(txt2);
    txt2.setString(L"Wiadomość z Głównego Urzędu Statystycznego!");
    txt2.setCharacterSize(20);
    txt2.setPosition(180,240);
    win.draw(txt2);
    txt2.setString(L"Odnotowaliśmy zwiększenie się ilości antyszczepionkowców.");
    txt2.setPosition(100,280);
    win.draw(txt2);
    txt2.setString(L"Poważnie utrudnia to dalsze szczepienia.");
    txt2.setPosition(180,310);
    win.draw(txt2);
    txt2.setString(L"Ponieważ akcja szczepień jest teraz trudniejsza do przeprowadzenia");
    txt2.setPosition(60,340);
    win.draw(txt2);
    txt2.setString(L"Będziesz dodatkowo premiowany za każdą szczepionkę");
    txt2.setPosition(130,370);
    win.draw(txt2);
    txt2.setString(L"*Od teraz każde szczepienie za dwa punkty*");
    txt2.setPosition(180,480);
    win.draw(txt2);
}


//------------------------
//INNE FUNKCJE


//kończt wyświetlanie bonusów
void SFMLapp::end_bonus()
{
    state=GAME;
}


//ustawia zadany tryb aplikacji 
void SFMLapp::set_app_state(SFML_state new_state)
{
   state=new_state;
}

//kończy grę
void SFMLapp::end_game()
{
   end=true;
}

//zwraca stan aplikacji
SFML_state SFMLapp::get_sfml_app_state() const
{
    return state;
}