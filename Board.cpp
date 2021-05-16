#include "Board.h"

//konstruktor 
Board::Board(Pacman & pacman_b, Level_name level): pacman_b(pacman_b),level(level)
{
    virues_speed=0.2;
    
    generate_viruses();
    generate_walls();
    generate_vaccines();
    
}


//generuje wirusy 
void Board::generate_viruses()
{
    int number;
    if(level==FIRST) number=2;
    else if(level==SECOND) number=3;
    else number=4;

    for(int i=0;i<number;i++)
    {
        viruses.push_back(Coronavirus(i));
        
    } 
}


//generuje ściany 
void Board::generate_walls()
{
    //tu umieścić odnośniki do funkcji generujących jeden z wybranych trybów ścian 
    //na razie tylko jeden predefiniowany typ 
    generate_outside_walls();

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
    fields[15][15].has_wall=true;
    fields[15][26].has_wall=true;
    for(int i=16;i<=25;i++)
    {
        fields[14][i].has_wall=false;
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
          if((row==1)and(col==1)) continue;
          if((row=15)and(col>=16)and(col<=25)) continue;
          
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
  int row=plan.x;
  int col=plan.y;

  if((row<0)or(row>29)or(col<0)or(col>39)) exit(-1);
  if(fields[row][col].has_wall) return false;

  pacman_b.move(direction);

  return true;
}


//sprawdza czy dany wirus może wykonać dany ruch
bool Board::can_virus_move(int number,Move_direction direction)
{
  sf::Vector2f plan;
  plan=viruses[number].get_next_field_location(direction);
  int row=plan.x;
  int col=plan.y;

  if((row<0)or(row>29)or(col<0)or(col>39)) exit(-1);
  if(fields[row][col].has_wall) return false;

  viruses[number].move(direction);

  return true;
}


//sprawdza czy na danym polu jest ściana
bool Board::is_wall_on_field(int row,int col)
{
 if(fields[row][col].has_wall==true) return true;
 return false;
}

//sprawdza czy na danym polu jest szczepionka
bool Board::is_vaccine_on_field(int row,int col)
{
   if(fields[row][col].has_vaccine==true) return true;
   return false;
}

//sprawdza czy na danym polu jest pacman
bool Board::is_pacman_on_field(int row,int col)
{
    sf::Vector2f position;
    position=pacman_b.get_position();
    int x=position.x;
    int y=position.y;
    if((x==row) and(y==col)) return true;
    return false;

}

//sprawdza czy na danym polu jest jakikolwiek wirus
bool Board::is_any_virus_on_field(int row,int col)
{
 for(size_t i=0;i<viruses.size();i++)
 {
     sf::Vector2f position=viruses[i].get_position();
     int x=position.x;
     int y=position.y;
     if((row==x)and(col==y)) return true;
 }

 return false;
}

//zwraca pozycję wirusa o podanym numerze
sf::Vector2f Board::get_position_of_virus_number(int number)
{
   return viruses[number].get_position();
}



//usuwa szczepionkę z pola
void Board::vaccinate(int row,int col)
{
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
          viruses[i].set_position_to(15,15+i+1);
      }
}


//zwraca prędkość wirusów
double Board::get_viruses_speed()
{
    return virues_speed;
}