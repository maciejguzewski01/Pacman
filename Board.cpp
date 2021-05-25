#include "Board.h"
#include <iostream>

//konstruktor 
Board::Board(Pacman & pacman_b, Level_name level, Board_order choosed_board): pacman_b(pacman_b),level(level), choosed_board(choosed_board)
{
    virues_speed=0.2;
    
   
    for(int row=0;row<=29;++row)
    {
        for(int col=0;col<=39;++col)
        {
            fields[row][col].has_wall=false;
            fields[row][col].has_vaccine=false; 
            fields[row][col].has_bonus=false;   
        }
    }
    
    generate_walls();
    generate_viruses();
    generate_bonus();
    generate_vaccines();
    
}


//generuje ilość i położenie bonusów
void Board::generate_bonus()
{
    int number_of_bonuses=rand()%5+2;
    int placed_bonuses=0;
    while(placed_bonuses!=number_of_bonuses)
    {
        int row,col;
        row=rand()%27+1;
      col=rand()%38+1;
      if(fields[row][col].has_wall==true) continue;
      if((row==1)and(col==1)) continue;
      if((row==15)and(col>=11)and(col<=30)) continue;
      fields[row][col].has_bonus=true;
      bonus_vec.push_back(sf::Vector2f(col,row));
        placed_bonuses++;
    }
}

//generuje wirusy 
void Board::generate_viruses()
{
    int number;
    if(level==FIRST) number=5;
    else if(level==SECOND) number=7;
    else number=10;

    for(int i=0;i<number;i++)
    {
        viruses.push_back(Coronavirus(i));
        
    } 
}


//generuje ściany- wywołuje funkcję generującą ściany zewnętrzne, a następnie funkcję genrującą jedną z predefiniowanych planszy (lub generującą losową)
void Board::generate_walls()
{
    
    generate_outside_walls();

    if(choosed_board==RANDOM) generate_random();
    else if(choosed_board==ONE) generate_one();
    else if(choosed_board==TWO) generate_two();
    else if(choosed_board==THREE) generate_three();
    else if(choosed_board==FOUR) generate_four();
    else if(choosed_board==FIVE) generate_five();
    
    generate_outside_walls();

  //kawałek planszy z "bazą" wirusów
  fields[15][10].has_wall=true;
    fields[15][31].has_wall=true;
    for(int i=11;i<=30;i++)
    {
        fields[14][i].has_wall=false;
        fields[15][i].has_wall=false;
    }
   
}


//generuje zewnętrzne ściany
void Board::generate_outside_walls()
{
   for(int row=0;row<30;row++)
  {
    fields[row][0].has_wall=true;
  }
  for(int col=0;col<40;col++)
  {
    fields[0][col].has_wall=true;
  }

  for(int row=0;row<30;row++)
  {
    fields[row][39].has_wall=true;
  }
  for(int col=0;col<40;col++)
  {
    fields[29][col].has_wall=true;
    fields[28][col].has_wall=true;
  }
}


//generuje planszę jeśli wybrano tryb losowy
void Board::generate_random()
{
  int number_of_walls=rand()%450+10;

  int row,col;
  int placed_walls=0;

  while(placed_walls!=number_of_walls)
  {
      int row,col;
      row=rand()%27+1;
      col=rand()%38+1;
      if(fields[row][col].has_wall==true) continue;
      if((row==1)and(col==1)) continue;
      fields[row][col].has_wall=true;
      placed_walls++;
  }
  
}

//generuje planszę jeśli wybrano tryb jeden
void Board::generate_one()
{
 for(int row=2;row<=27;row=row+2)
    {
        for(int col=2;col<=37;col++)
        {
            fields[row][col].has_wall=true;
            
        }
        for(int col=5;col<=35;col=col+5)
        {
            fields[row][col].has_wall=false;
              
        }
    }
  
}

//generuje planszę jeśli wybrano tryb dwa
void Board::generate_two()
{
    for(int col=2;col<=37;col=col+2)
    {
        for(int row=2;row<=27;++row)
        {
             fields[row][col].has_wall=true;
        }

        for(int row=5;row<=26;row=row+5)
        {
            fields[row][col].has_wall=false;   
        }
    }  
}


//generuje planszę jeśli wybrano tryb trzy
void Board::generate_three()
{
  for(int idx=0;idx<=30;idx=idx+10)
  {
    for(int col=idx+2;col<=idx+10;col++)
    {
        for(int row=2;row<=10;++row)
        {
             fields[row][col].has_wall=true;
        }
    }
    for(int col=idx+3;col<=idx+9;col++)
    {
        for(int row=3;row<=9;++row)
        {
             fields[row][col].has_wall=false;
        }
    }
   fields[2][idx+8].has_wall=false;
    
    for(int col=idx+2;col<=idx+10;col++)
    {
        for(int row=12;row<=20;++row)
        {
             fields[row][col].has_wall=true;
        }
    }
    for(int col=idx+3;col<=idx+9;col++)
    {
        for(int row=13;row<=19;++row)
        {
             fields[row][col].has_wall=false;
        }
    }
   fields[12][idx+6].has_wall=false;

    for(int col=idx+2;col<=idx+10;col++)
    {
        for(int row=22;row<=26;++row)
        {
             fields[row][col].has_wall=true;
        }
    }
    for(int col=idx+3;col<=idx+9;col++)
    {
        for(int row=23;row<=25;++row)
        {
             fields[row][col].has_wall=false;
        }
    }
   fields[23][idx+2].has_wall=false;
  }
  generate_outside_walls();
}


//generuje planszę jeśli wybrano tryb cztery
void Board::generate_four()
{
 for(int idx=0;idx<=10;idx=idx+2)
 {
     for(int row=2+idx;row<27-idx;row++)
    {
      fields[row][2+idx].has_wall=true;
    }
    for(int col=2+idx;col<38-idx;col++)
    {
      fields[2+idx][col].has_wall=true;
    }

    for(int row=2+idx;row<27-idx;row++)
     {
      fields[row][37-idx].has_wall=true;
     }
    for(int col=2+idx;col<38-idx;col++)
    {
      fields[28-(2+idx)][col].has_wall=true;
    }
 }

 for(int col=2;col<38;col++)
 {
     fields[15][col].has_wall=false;
 }

 for(int row=2;row<28;++row)
 {
     fields[row][13].has_wall=false;
     fields[row][25].has_wall=false;
 }

}


//generuje planszę jeśli wybrano tryb pięć
void Board::generate_five()
{
   for(int col=2;col<=38;col=col+2)
   {
       for(int row=2;row<=28;row=row+2)
       {
           fields[row][col].has_wall=true;
       }
   }
}

//generuje szczepionki
void Board::generate_vaccines()
{
  for(int row=1;row<30;row++)
  {
      for(int col=1;col<40;col++)
      {
          if(fields[row][col].has_wall==true ) continue;
          if(fields[row][col].has_bonus==true ) continue;
          if((row==1)and(col==1)) continue;
          if((row==15)and(col>=11)and(col<=30)) continue;
          
          fields[row][col].has_vaccine=true;
          total_number_of_vaccine++;
      }
      
  }

 
}


//zwraca całkowitą ilość szczepionek 
int Board::get_total_vaccine_number()
{
    return total_number_of_vaccine;
}


//sprawdza czy pacman może wykonać dany ruch
bool Board::can_pacman_move(Move_direction direction)
{
  sf::Vector2f plan;
  plan=pacman_b.get_next_field_location(direction);
  int row=plan.y;
  int col=plan.x;
  
 

  if((row<0)or(row>29)or(col<0)or(col>39)) exit(-1);
  if(fields[row][col].has_wall) return false;

  

  return true;
}


//sprawdza czy dany wirus może wykonać dany ruch
bool Board::can_virus_move(int number,Move_direction direction)
{
  sf::Vector2f plan;
  plan=viruses[number].get_next_field_location(direction);
  int row=plan.y;
  int col=plan.x;

  if((row<0)or(row>29)or(col<0)or(col>39)) exit(-1);
  if(fields[row][col].has_wall==true) return false;

  

  return true;
}

//porusza wirusem
void Board::move_virus(int number, Move_direction direction)
{
    viruses[number].move(direction);
}



//sprawdza czy na danym polu jest ściana
bool Board::is_wall_on_field(int row,int col)
{
 if((row<0)or(row>29)or(col<0)or(col>39)) exit(-1);
 if(fields[row][col].has_wall==true) return true;
 return false;
}

//sprawdza czy na danym polu jest szczepionka
bool Board::is_vaccine_on_field(int row,int col)
{
    if((row<0)or(row>29)or(col<0)or(col>39)) exit(-1);
   if(fields[row][col].has_vaccine==true) return true;
   return false;
}

//sprawdza czy na danym polu jest pacman
bool Board::is_pacman_on_field(int row,int col)
{
    if((row<0)or(row>29)or(col<0)or(col>39)) exit(-1);
    sf::Vector2f position;
    position=pacman_b.get_position();
    int x=position.x;
    int y=position.y;
    if((x==col) and(y==row)) return true;
    return false;
   
}

//sprawdza czy na danym polu jest jakikolwiek wirus
bool Board::is_any_virus_on_field(int row,int col)
{
    if((row<0)or(row>29)or(col<0)or(col>39)) exit(-1);
 for(size_t i=0;i<viruses.size();i++)
 {
     sf::Vector2f position=viruses[i].get_position();
     int x=position.x;
     int y=position.y;
     if((col==x)and(row==y)) return true;
 }

 return false;
}

//sprawdza czy na danym polu jest bonus 
bool Board::is_bonus_on_field(int row,int col)
{
   if((row<0)or(row>29)or(col<0)or(col>39)) exit(-1);
    
    for(size_t i=0;i<bonus_vec.size();i++)
     {
     if(bonus_vec[i]==sf::Vector2f(-1,-1)) continue;
     int x=bonus_vec[i].x;
     int y=bonus_vec[i].y;
     if((col==x)and(row==y)) return true;
     }
     return false;
}

//zwraca pozycję wirusa o podanym numerze
sf::Vector2f Board::get_position_of_virus_number(int number)
{
    int size=viruses.size();
    if((number<0)or(number>size-1)) exit(-1);
   return viruses[number].get_position();
}



//usuwa szczepionkę z pola
void Board::vaccinate(int row,int col)
{
    if((row<0)or(row>29)or(col<0)or(col>39)) exit(-1);
    fields[row][col].has_vaccine=false;
}

//zwraca ilość wirusów na planszy
int Board::get_number_of_viruses()
{
   int size=viruses.size();
   return size;
}

//resetuje stan planszy (pozycję wirusów i pacmana) 
void Board::reset()
{
      pacman_b.set_position_to(1,1);
      for(int i=0;i<get_number_of_viruses();i++)
      {
          
          viruses[i].set_position_to(10+i+1,15);
      }
}


//zwraca prędkość wirusów
double Board::get_viruses_speed()
{
    return virues_speed;
}


//zwraca numer bonusu na podanej pozycji
int Board::get_number_of_bonus(int row,int col)
{
    if((row<0)or(row>29)or(col<0)or(col>39)) exit(-1);
    
    for(size_t i=0;i<bonus_vec.size();++i)
    {
        if((col==bonus_vec[i].x)and(row==bonus_vec[i].y)) return i;
    }

    return -1;

}

//zwraca wektor bonusów 
std::vector<sf::Vector2f> Board::get_bonus_vec()
{
    return bonus_vec;
}


 void Board::delete_bonus(int row, int col)
 {
    if((row<0)or(row>29)or(col<0)or(col>39)) exit(-1);
    
    fields[row][col].has_bonus=false;
    
    int nr=get_number_of_bonus( row,col);
    bonus_vec[nr]=sf::Vector2f(-1,-1);
 }