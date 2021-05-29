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
   bool has_bonus;
};
enum Level_name {FIRST,SECOND,THIRD};
enum Board_order {RANDOM,ONE,TWO,THREE,FOUR,FIVE};
class Board
{
    double virues_speed;
    Pacman & pacman_b;
    Field fields[30][40];
    const Level_name level;
    std::vector<Coronavirus> viruses;
    int total_number_of_vaccine=0;

    void generate_viruses();
    void generate_walls();
    void generate_outside_walls();
    void generate_vaccines();
    
    const Board_order choosed_board;
    

    void generate_random();
    void generate_one();
    void generate_two();
    void generate_three();
    void generate_four();
    void generate_five();
    void generate_bonus();
    
    std::vector<sf::Vector2f> bonus_vec;

    public:
    explicit Board(Pacman & pacman_b, Level_name level,Board_order choosed_board);
    int get_total_vaccine_number();
    bool can_pacman_move(Move_direction direction);
    bool can_virus_move(int number,Move_direction direction);

    bool is_wall_on_field(int row,int col);
    bool is_vaccine_on_field(int row,int col);
    bool is_pacman_on_field(int row,int col);
    bool is_any_virus_on_field(int row,int col);
    bool is_bonus_on_field(int row,int col);
    sf::Vector2f get_position_of_virus_number(int number);
    int get_number_of_viruses();
    int get_number_of_bonus(int row,int col);
    void vaccinate(int row,int col);
    void reset();

    double get_viruses_speed();

    void move_virus(int number, Move_direction direction);

   std::vector<sf::Vector2f> get_bonus_vec();

   void delete_bonus(int row, int col);

   void add_virus();
   void delete_virus();
   void reset_viruses();

   void set_viruses_speed(double speed);
   void add_vaccine(int row,int col);
   Level_name get_level() const;
};


#endif