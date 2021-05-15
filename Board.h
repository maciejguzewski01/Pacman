#ifndef BOARD_H
#define BOARD_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Pacman.h"
#include "Coronavirus.h"
#include <vector>

struct Field
{
   bool has_wall;
   bool has_vaccine;
   //bool has_bonus;
};
enum Level_name {FIRST,SECOND,THIRD};

class Board
{
    Field fields[30][40];
    Level_name level;
    std::vector<Coronavirus> viruses;
    void generate_viruses();
    void generate_walls();
    void generate_outside_walls();
    
    
 

    public:
    Board(Level_name level);
};


#endif