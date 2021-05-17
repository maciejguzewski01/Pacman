#ifndef MANAGER_H
#define MANAGER_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Board.h"
#include "Pacman.h"
#include "Coronavirus.h"
#include <vector>

class Manager
{
    int score;
   
   Pacman & pacman_m;
   Board & board_m;
   bool is_pacman_alive();

   sf::Clock clk_pacman;
   sf::Clock clk_viruses;

   void move_pacman(Move_direction direction);
   bool pacman_meet_virus();
   std::vector<Move_direction> viruses_directions;

   void move_viruses();

   void generate_first_directions();

  public:
  Manager(Pacman pacman_m,Board & board_m);
  
  void play(Move_direction direction);

  int get_score() const;

};

#endif