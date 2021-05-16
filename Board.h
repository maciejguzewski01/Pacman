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
    double virues_speed;
    Pacman & pacman_b;
    Field fields[30][40];
    Level_name level;
    std::vector<Coronavirus> viruses;
    int total_number_of_vaccine=0;

    void generate_viruses();
    void generate_walls();
    void generate_outside_walls();
    void generate_vaccines();
    
    
    
 

    public:
    Board(Pacman & pacman_b, Level_name level);
    int get_total_vaccine_number();
    bool can_pacman_move(Move_direction direction);
    bool can_virus_move(int number,Move_direction direction);

    bool is_wall_on_field(int row,int col);
    bool is_vaccine_on_field(int row,int col);
    bool is_pacman_on_field(int row,int col);
    bool is_any_virus_on_field(int row,int col);
    sf::Vector2f get_position_of_virus_number(int number);
    int get_number_of_viruses();
    
    void vaccinate(int row,int col);
    void reset();

    double get_viruses_speed();
};


#endif