#include "Bonus.h"


Bonus::Bonus(Pacman & pacman_b, Board & board_b): pacman_b(pacman_b), board_b(board_b)
{
    std::vector <sf::Vector2f> bonuses=board_b.get_bonus_vec();
    for(size_t i=0;i<bonuses.size();++i)
    {
        bonuses_types.push_back(rand_type_of_bonus());
        
    }
}


//losuje rodzaj bonusu
Bonus_type Bonus::rand_type_of_bonus()
{
    //POZMIENIAĆ!!!!!!!!!!!!!!!!!!!
    int number=rand()%10+1;

    if(number==1) return SCHOOL;
    if(number==2) return TYPE_TWO;
    if(number==3) return TYPE_THREE;
    if(number==4) return TYPE_FOUR;
    if(number==5) return TYPE_FIVE;
    if(number==6) return TYPE_SIX;
    if(number==7) return TYPE_SEVEN;
    if(number==8) return TYPE_EIGHT;
    if(number==9) return TYPE_NINE;
    if(number==10) return TYPE_TEN;
   
   exit(-1);
}