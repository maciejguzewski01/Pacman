#include "Start.h"

//konstruktor 
Start::Start()
{
    state=HELLO;
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
   virus.setScale(0.1,0.1);

   wave_t.loadFromFile("../resources/wave.png");
   wave.setTexture(wave_t);
   wave.setScale(0.3,0.3);

   cube_t.loadFromFile("../resources/board/cube.png");
   cube.setTexture(cube_t);
   cube.setScale(0.25,0.25);

   one_t.loadFromFile("../resources/board/one.png");
   one.setTexture(one_t);
   one.setScale(0.25,0.25);

   two_t.loadFromFile("../resources/board/two.png");
   two.setTexture(two_t);
   two.setScale(0.25,0.25);

   three_t.loadFromFile("../resources/board/three.png");
   three.setTexture(three_t);
   three.setScale(0.25,0.25);

   four_t.loadFromFile("../resources/board/four.png");
   four.setTexture(four_t);
   four.setScale(0.25,0.25);

   five_t.loadFromFile("../resources/board/five.png");
   five.setTexture(five_t);
   five.setScale(0.25,0.25);

   boss_t.loadFromFile("../resources/boss.png");
   boss.setTexture(boss_t);
   boss.setScale(1,1);

   smoke_t.loadFromFile("../resources/smoke.png");
   smoke.setTexture(smoke_t);
   smoke.setScale(1,1);
   
   vaccine_t.loadFromFile("../resources/vaccine.png");
   vaccine.setTexture(vaccine_t);
   vaccine.setScale(1,1);

   smoke_two_t.loadFromFile("../resources/smoke_two.png");
   smoke_two.setTexture(smoke_two_t);
   smoke_two.setScale(1,1);   
}


//----------------------------------------
//FUNKCJE RYSUJĄCE 

//przekazywanie rysowania do odpowiednich funkcji 
void Start::draw(sf::RenderWindow & win)
{
    if(end==true) win.close();
   if(state==HELLO) draw_hello_state(win);
   else if(state==LEVEL) draw_level_state(win);
   else if(state==BOARD_TYPE) draw_board_type_state(win);
   else if(state==NAME) draw_name_state(win);
   else if(state==INSTRUCTION_ONE) draw_instruction_one_state(win);
   else if(state==INSTRUCTION_TWO) draw_instruction_two_state(win);
}

//wyświetla ekran powitalny 
void Start::draw_hello_state(sf::RenderWindow & win)
{
   rect.setSize(sf::Vector2f(300,100));
   rect.setFillColor(sf::Color(0,153,0));
   rect.setPosition(250,275);
   rect.setOutlineThickness(1);
   rect.setOutlineColor(sf::Color::Black);
   win.draw(rect);
   txt2.setString("START");
   txt2.setFillColor(sf::Color::Black);
   txt2.setCharacterSize(70);
   txt2.setPosition(260,280);
   win.draw(txt2);
   virus.setScale(0.5,0.5);
   virus.setPosition(0,0);
   win.draw(virus);
   virus.setPosition(-250,200);
   win.draw(virus);
   virus.setPosition(300,350);
   win.draw(virus);
   virus.setScale(0.25,0.25);
   virus.setPosition(400,50);
   win.draw(virus);
   virus.setPosition(-40,430);
   win.draw(virus);
   virus.setPosition(250,450);
   win.draw(virus);

}


//rysowanie aplikacji w trybie wyboru poziomu trudności 
void Start::draw_level_state(sf::RenderWindow & win)
{
   rect.setSize(sf::Vector2f(200,100));
   rect.setFillColor(sf::Color(209,162,6));
   
   rect.setOutlineThickness(1);
   rect.setOutlineColor(sf::Color::Black);

   rect.setPosition(50,275);
   win.draw(rect);
    rect.setPosition(300,275);
   win.draw(rect);
    rect.setPosition(550,275);
   win.draw(rect);
   wave.setPosition(100,280);
   win.draw(wave);

   wave.setPosition(370,280);
   win.draw(wave);
   wave.setPosition(340,280);
   win.draw(wave);

   wave.setPosition(640,280);
   win.draw(wave);
   wave.setPosition(600,280);
   win.draw(wave);
   wave.setPosition(560,280);
   win.draw(wave);

   txt2.setCharacterSize(40);
   txt2.setFillColor(sf::Color::Black);
   txt2.setString(L"Wybierz poziom trudności");
   txt2.setPosition(100,50);
   win.draw(txt2);

   txt2.setCharacterSize(20);

   txt2.setString(L"Pierwsza fala");
   txt2.setPosition(80,380);
   win.draw(txt2);

   txt2.setString(L"Druga fala");
   txt2.setPosition(350,380);
   win.draw(txt2);

   txt2.setString(L"Trzecia fala");
   txt2.setPosition(600,380);
   win.draw(txt2);




}


//rysowanie aplikacji w trybie wyboru planszy 
void Start::draw_board_type_state(sf::RenderWindow & win)
{
  rect.setSize(sf::Vector2f(200,100));
   rect.setFillColor(sf::Color(209,162,6));
   rect.setOutlineThickness(1);
   rect.setOutlineColor(sf::Color::Black);

    rect.setPosition(50,275);
   win.draw(rect);
    rect.setPosition(300,275);
   win.draw(rect);
    rect.setPosition(550,275);
   win.draw(rect);

    rect.setPosition(50,390);
   win.draw(rect);
    rect.setPosition(300,390);
   win.draw(rect);
    rect.setPosition(550,390);
   win.draw(rect);

   txt2.setString(L"Wybierz planszę");
   txt2.setCharacterSize(40);
   txt2.setPosition(250,10);
   win.draw(txt2);

    txt2.setString(L"Możesz wybrać jedną z predefiniowanych plansz lub wygenerować losową");
   txt2.setCharacterSize(20);
   txt2.setPosition(10,60);
   win.draw(txt2);

   txt2.setString(L"Uwaga: możliwe że na losowo generowanej planszy nie będzie można wygrać");
   txt2.setCharacterSize(10);
   txt2.setPosition(200,110);
   win.draw(txt2);

   cube.setPosition(100,280);
   win.draw(cube);

   one.setPosition(350,290);
   win.draw(one);
   
   two.setPosition(600,290);
   win.draw(two);

   three.setPosition(120,400);
   win.draw(three);

   four.setPosition(350,400);
   win.draw(four);
   
   five.setPosition(600,400);
   win.draw(five);
}



//rysowanie aplikacji w trybie name 
void Start::draw_name_state(sf::RenderWindow & win)
{
    txt2.setString(L"Wpisz nazwę użytkownika:");
    txt2.setCharacterSize(40);
    txt2.setPosition(150,20);
    win.draw(txt2);

    rect.setFillColor(sf::Color(0,153,0));
    rect.setSize(sf::Vector2f(200,50));
    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(1);
    rect.setPosition(300,300);
    win.draw(rect);

    txt2.setString("Gotowe");
    txt2.setCharacterSize(30);
    txt2.setPosition(340,310);
    win.draw(txt2);

    txt2.setString(choosed_name);
    txt2.setPosition(100,200);
    win.draw(txt2);
}



//rysowanie aplikacji w trybie INSTRUCTION_ONE 
void Start::draw_instruction_one_state(sf::RenderWindow & win)
{
    boss.setPosition(600,10);
    win.draw(boss);

    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(1);
    rect.setSize(sf::Vector2f(150,50));
    rect.setFillColor(sf::Color(0,153,0));
    rect.setPosition(200,300);
    win.draw(rect);
    txt2.setString(L"Jaka?");
    txt2.setCharacterSize(30);
    txt2.setPosition(240,305);
    win.draw(txt2);

    txt2.setCharacterSize(30);
    txt2.setString(L"Witaj urzędniku!");
    txt2.setPosition(200,50);
    win.draw(txt2);
    txt2.setCharacterSize(20);

    txt2.setString(L"Właśnie zostałeś powołany na nowego Ministra Zdrowia.");
    txt2.setPosition(20,100);
    win.draw(txt2);
  
    if(choosed_level==FIRST) txt2.setString(L"Do kraju dotarła właśnie epidemia nowej choroby.");
    else if(choosed_level==SECOND) txt2.setString(L"Od wielu miesięcy w kraju szaleje pandemia.");
    else txt2.setString(L"Już prawie rok trwa pandemia.");
    
    txt2.setPosition(20,130);
    win.draw(txt2);

    txt2.setString(L"Obywatele masowo umierają, a gospodarka jest w ruinie.");
    txt2.setPosition(20,160);
    win.draw(txt2);

    txt2.setString(L"Na szczęście pojawiła się nadzieja!");
    txt2.setPosition(110,190);
    win.draw(txt2);

    smoke.setPosition(0,10);
    win.draw(smoke);
}


//rysowanie aplikacji w trybie INSTRUCTION_TWO
void Start::draw_instruction_two_state(sf::RenderWindow & win)
{
    boss.setPosition(600,10);
    win.draw(boss);

    txt2.setCharacterSize(20);
    txt2.setString(L"Szczepionki!");
    txt2.setPosition(300,50);
    win.draw(txt2);

     txt2.setString(L"I twoim zadaniem będzie je wykorzystać.");
    txt2.setPosition(120,80);
    win.draw(txt2);

     txt2.setString(L"Wyszczep całą poplucję zanim wszycy umrzemy!");
    txt2.setPosition(80,110);
    win.draw(txt2);

     txt2.setString(L"Pamiętaj że sytuacja jest dynamiczna");
    txt2.setPosition(150,140);
    win.draw(txt2);
     txt2.setString(L"więc wszystko może się zmieniać.");
    txt2.setPosition(170,170);
    win.draw(txt2);
    txt2.setString(L"Odpowiednie urzędy będą Cię informować.");
    txt2.setPosition(100,200);
    win.draw(txt2);
    

    rect.setOutlineColor(sf::Color::Black);
    rect.setOutlineThickness(1);
    rect.setSize(sf::Vector2f(350,50));
    rect.setFillColor(sf::Color(0,153,0));
    rect.setPosition(180,300);
    win.draw(rect);
    txt2.setString(L"Podejmuję wyzwanie!");
    txt2.setCharacterSize(30);
    txt2.setPosition(190,305);
    win.draw(txt2);
    
    smoke_two.setPosition(50,10);
    win.draw(smoke_two);
}


//-------------------------------------------------
//OBSŁUGA ZDARZEŃ

//obsługa kliknięć myszką 
void Start::mouse_was_pressed(sf::Event event)
{
    if(state==HELLO) mouse_hello_state(event);
    else if(state==LEVEL) mouse_level_state(event);
    else if(state==BOARD_TYPE) mouse_board_type_state(event);
    else if(state==NAME) mouse_name_state(event);
    else if(state==INSTRUCTION_ONE) mouse_instruction_one_state(event);
    else if(state==INSTRUCTION_TWO) mouse_instruction_two_state(event);
}

//obsługa kliknięć myszką w trybie HELLO 
void Start::mouse_hello_state(sf::Event event)
{
    if(event.mouseButton.button==1) return; //prawy
  int x=event.mouseButton.x;
  int y=event.mouseButton.y;
  
  if((x>250)and(x<550)and(y>275)and(y<375))
  {
    state=LEVEL;
  }
}

//obsługa kliknięć myszką w trybie HELLO 
void Start::mouse_level_state(sf::Event event)
{
  if(event.mouseButton.button==1) return; //prawy
  int x=event.mouseButton.x;
  int y=event.mouseButton.y;
   

  if((x>50)and(x<250)and(y>275)and(y<375))
  {
    choosed_level=FIRST;
    state=BOARD_TYPE; 
  }
  else if((x>300)and(x<500)and(y>275)and(y<375))
  {
      choosed_level=SECOND;
      state=BOARD_TYPE;
  }
  else if((x>550)and(x<750)and(y>275)and(y<375))
  {
      choosed_level=THIRD;
      state=BOARD_TYPE;
  }

}

//obsługa kliknięć myszką w trybie BOARD_TYPE 
void Start::mouse_board_type_state(sf::Event event)
{
   if(event.mouseButton.button==1) return; //prawy
  int x=event.mouseButton.x;
  int y=event.mouseButton.y;
   if((x>50)and(x<250)and(y>275)and(y<375))
  {
    choosed_board=RANDOM;
    state=NAME; 
  }
  else if((x>300)and(x<500)and(y>275)and(y<375))
  {
      choosed_board=ONE;
      state=NAME;
  }
  else if((x>550)and(x<750)and(y>275)and(y<375))
  {
      choosed_board=TWO;
      state=NAME;
  }
  else if((x>50)and(x<250)and(y>390)and(y<490))
  {
    choosed_board=THREE;
    state=NAME; 
  }
  else if((x>300)and(x<500)and(y>390)and(y<490))
  {
      choosed_board=FOUR;
      state=NAME;
  }
  else if((x>550)and(x<750)and(y>390)and(y<490))
  {
      choosed_board=FIVE;
      state=NAME;
  }
}

//obsługa kliknięć myszką w trybie NAME 
void Start::mouse_name_state(sf::Event event)
{
    if(event.mouseButton.button==1) return; //prawy

  int x=event.mouseButton.x;
  int y=event.mouseButton.y;
  
  if(choosed_name=="") return;

   if((x>300)and(x<500)and(y>300)and(y<350))
  {
    state=INSTRUCTION_ONE; 
  }
}

//obsługa kliknięć myszką w trybie INSTRUCTION_ONE 
void Start::mouse_instruction_one_state(sf::Event event)
{
  if(event.mouseButton.button==1) return; //prawy

  int x=event.mouseButton.x;
  int y=event.mouseButton.y;
  

   if((x>200)and(x<350)and(y>300)and(y<350))
  {
    state=INSTRUCTION_TWO; 
  }
}

//obsługa kliknięć myszką w trybie INSTRUCTION_TWO 
void Start::mouse_instruction_two_state(sf::Event event)
{
  if(event.mouseButton.button==1) return; //prawy

  int x=event.mouseButton.x;
  int y=event.mouseButton.y;

   if((x>180)and(x<530)and(y>300)and(y<350))
  {
    end=true; 
  }
}

//obsługa wpisywania tekstu 
void Start::text_was_entered(sf::Event event)
{
    if(state!=NAME) return;
 char help=event.text.unicode;
 if((event.key.code=='\b')and(choosed_name.length()>0)) 
 {
     choosed_name=choosed_name.erase(choosed_name.length()-1,1);
     return;
 }
 choosed_name=choosed_name+help;
}

//----------------------------------------
//ZWRACANIE USTALONYCH INFORMACJI 


//zwraca wybrany poziom
Level_name Start::get_choosed_level() const
{
   return choosed_level;
}

//zwraca wybraną planszę 
Board_order Start::get_choosed_board() const
{
   return choosed_board;
}

//zwraca wybraną nazwę
std::string Start::get_choosed_name() const
{
   return choosed_name;
}