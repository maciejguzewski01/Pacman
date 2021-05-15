#include "Board.h"

//konstruktor 
Board::Board(Level_name level): level(level)
{
    generate_viruses();
    generate_walls();
    
    
    
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
