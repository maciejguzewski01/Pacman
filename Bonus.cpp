#include "Bonus.h"
#include <iostream>


Bonus::Bonus(Pacman & pacman_b, Board & board_b): pacman_b(pacman_b), board_b(board_b)
{
    std::vector <sf::Vector2f> bonuses=board_b.get_bonus_vec();
    for(size_t i=0;i<bonuses.size();++i)
    {
        randomize_vec.push_back(0);
        bonuses_types.push_back(rand_type_of_bonus());
        
    }
}


//losuje rodzaj bonusu
Bonus_type Bonus::rand_type_of_bonus()
{
    //POZMIENIAĆ!!!!!!!!!!!!!!!!!!!
    int number=rand()%10+1;
    bool already_was=false;
   //kawałek kodu wymuszający wygenerowanie danego bonusu 
   //TYLKO DLA TESTÓW 
   //USUNĄĆ!!!!!!!
   if(idx==0)
   {
       number=4;
       idx++;
       //idx w klasie
   }

   do{
       already_was=false;
        for(size_t i=0;i<randomize_vec.size();++i)
         {
            if(randomize_vec[i]==number) already_was=true;
         }
      if(already_was==true) number=rand()%10+1;
   }while(already_was==true);

randomize_vec[randomize_vec.size()-1]=number;
 
    if(number==1) return SCHOOL;
    if(number==2) return TYPE_TWO;
    if(number==3) return TYPE_THREE;
    if(number==4) return BRITAIN;
    if(number==5) return RESPIRATOR;
    if(number==6) return LOCKDOWN;
    if(number==7) return SUMMER;
    if(number==8) return LITE_LOCKDOWN;
    if(number==9) return TYPE_NINE;
    if(number==10) return TYPE_TEN;
   
   exit(-1);
}


Bonus_type Bonus::get_type_of_bonus(int row, int col)
{
    if((row<0)or(row>29)or(col<0)or(col>39)) exit(-1);
    int nr=board_b.get_number_of_bonus(row,col);
    int size=bonuses_types.size();
    if((nr<0)or(nr>size)) return NONE;
    return bonuses_types[nr];
   
}



//sprawdza jaki bonus został uruchomiony i przekazuje sterowanie do odpowiedniej funkcji 
void Bonus::bonus_activated(int row, int col)
{
   int nr=board_b.get_number_of_bonus(row,col);
   int size=bonuses_types.size();
   if((nr<0)or(nr>size)) exit(-1);
   Bonus_type type=bonuses_types[nr];

   switch(type)
   {
       case 0: return;
       break;
       case SCHOOL: bonus_one();
       break;
       case 2: bonus_two();
       break;
       case 3: bonus_three();
       break;
       case 4: bonus_four();
       break;
       case 5: bonus_five();
       break;
       case 6: bonus_six();
       break;
       case 7: bonus_seven();
       break;
       case 8: bonus_eight();
       break;
       case 9: bonus_nine();
       break;
       case 10: bonus_ten();
       break;
   }
}



//obsługa bonusu nr 1
void Bonus::bonus_one()
{
  int number=board_b.get_number_of_viruses();

  for(int i=0;i<number;++i)
  {
      board_b.add_virus();
  }
}

//obsługa bonusu nr 2
void Bonus::bonus_two()
{
    
}

//obsługa bonusu nr 3
void Bonus::bonus_three()
{
    
}

//obsługa bonusu nr 4
void Bonus::bonus_four()
{
    double speed;
    speed=board_b.get_viruses_speed();
    speed=speed/2;
    board_b.set_viruses_speed(speed);
}

//obsługa bonusu nr 5
void Bonus::bonus_five()
{
    pacman_b.set_lives_number(4);
}

//obsługa bonusu nr 6
void Bonus::bonus_six()
{
    lockdown=true;
}

//obsługa bonusu nr 7
void Bonus::bonus_seven()
{
    board_b.reset_viruses();
}

//obsługa bonusu nr 8
void Bonus::bonus_eight()
{
    
    double speed;
    speed=board_b.get_viruses_speed();
    speed=speed*2;
    board_b.set_viruses_speed(speed);

    
}

//obsługa bonusu nr 9
void Bonus::bonus_nine()
{
    
}

//obsługa bonusu nr 10
void Bonus::bonus_ten()
{
    
}




//zwraca prawdę jeśli jest lockdown
bool Bonus::is_lockdown()
{
    return lockdown;
}

//kończy lockdown
bool Bonus::end_lockdown()
{
    lockdown=false;
}