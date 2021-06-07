#ifndef MANAGER_H
#define MANAGER_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Board.h"
#include "Pacman.h"
#include "Coronavirus.h"
#include "Bonus.h"
#include <cstring>
#include <errno.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>

//Zarządza grą 
/*Zadania;
1. zna, liczy i zwraca punkty oraz ilość zjedzonych szczepiomek 
2. wykonuje ruchy (w szczególności algorytm ruchu wirusów) i obsługuje ich ewentualne konswkwencje (śmierć, zjedzenie szczepionki/bonusu)
3. reaguje na aktywacje bonusu

*/
class Manager
{
    int score;
   int vaccines=0;

   Pacman & pacman_m;
   Board & board_m;
   Bonus & bonus_m;

   sf::Clock clk_pacman;
   sf::Clock clk_viruses;

   sf::Clock clk_lockdown;
   sf::Clock clk_uniform;
   bool uniform=false;

   void move_pacman(Move_direction direction);
   bool did_pacman_meet_virus() const;
   void pacman_meet_virus();

   std::vector<Move_direction> viruses_directions;
   std::vector<int> rand_number_of_moves;
   std::vector<int> steps;
    void randomize(int i);

   void move_viruses();

   void generate_first_directions();
   void do_something(Bonus_type type);
   bool antivaxx=false;

   void pacman_died();
   std::vector <std::string> results;
   void vec_not_full();
   void vec_full();
   int idx=0;
   
   bool is_bonus=false;
   Bonus_type type_of_bonus=NONE;


  public:
  explicit Manager(Pacman & pac,Board & boa,Bonus & bon);
  
  void play(Move_direction direction);

void end_bonus();
void  reset_clk_lockdown();
void reset_clk_uniform();


bool is_pacman_alive() const;
int get_score() const;
int get_done_vaccine_number() const;
bool get_uniform_state() const;
bool get_is_bonus_state() const;
Bonus_type get_active_bonus_type() const;
bool  all_vaccine_taken() const;

 
};

#endif