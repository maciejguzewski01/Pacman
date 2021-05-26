#ifndef MANAGER_H
#define MANAGER_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Board.h"
#include "Pacman.h"
#include "Coronavirus.h"
#include "Bonus.h"
#include <vector>

class Manager
{
    int score;
   
   Pacman & pacman_m;
   Board & board_m;
   Bonus & bonus_m;

   sf::Clock clk_pacman;
   sf::Clock clk_viruses;

   void move_pacman(Move_direction direction);
   bool did_pacman_meet_virus();
   void pacman_meet_virus();

   std::vector<Move_direction> viruses_directions;
   std::vector<int> rand_number_of_moves;
   std::vector<int> steps;
    void randomize(int i);

   void move_viruses();

   void generate_first_directions();
   void do_something(Bonus_type type);
  

  public:
  explicit Manager(Pacman & pacman_m,Board & board_m,Bonus & bonus_m);
  
  void play(Move_direction direction);

  int get_score() const;
bool is_pacman_alive();
};

#endif