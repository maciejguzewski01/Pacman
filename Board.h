#ifndef BOARD_H
#define BOARD_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Pacman.h"
#include "Coronavirus.h"
#include <vector>

//KLASA REPREEZENTUJĄCA PLANSZĘ 
/* Zadania;
1. generuje stan początkowy planszy (w tym ma wektor wirusów i bonusów) 
2. zna i zwraca ilość i prędkość (i ustawia) wirusów 
3. sprawdza czy pacman/wirus może sie ruszyć 
4. wie i sprawdza czy na polu jest pacman/wirus/szczepionka/ściana/bonus
5. sprawdza jaki bonus jest na danym polu 
6. resetuje planszę, usuwa/ dodaje szczepionki 
7. dodaje i usuwa wirusy 
8. zna i zwraca poziom trudności 
*/


struct Field //reprezentuje pole
{
   bool has_wall;
   bool has_vaccine;
   bool has_bonus;
};
enum Level_name {FIRST,SECOND,THIRD};  //poziomy
enum Board_order {RANDOM,ONE,TWO,THREE,FOUR,FIVE}; // układy planszy 
class Board
{
    double virues_speed;
    Pacman & pacman_b;
    Field fields[30][40];
    const Level_name level;
    std::vector<Coronavirus> viruses;
    int total_number_of_vaccine=0;
    const Board_order choosed_board;
   std::vector<sf::Vector2f> bonus_vec;

    //Funkcje generujące stan początkowy
    void generate_viruses();
    void generate_walls();
    void generate_outside_walls();
    void generate_vaccines();
    
    void generate_random();
    void generate_one();
    void generate_two();
    void generate_three();
    void generate_four();
    void generate_five();
    void generate_bonus();
    
    

    public:
    explicit Board(Pacman & pacman_b, Level_name level,Board_order choosed_board);
    
   
    //funkcje modyfikujące stan obiektu 
    void reset();
     
     void delete_bonus(int row, int col);
    
         void add_vaccine(int row,int col);
         void vaccinate(int row,int col);
    

         void add_virus();
         void delete_virus();
         void reset_viruses();
         void set_viruses_speed(double speed);
         void move_virus(int number, Move_direction direction);
  
   //funkcje zwracjące informację 
   bool can_pacman_move(Move_direction direction) const;
   bool can_virus_move(int number,Move_direction direction) const;
   Level_name get_level() const;
   std::vector<sf::Vector2f> get_bonus_vec() const;
   double get_viruses_speed() const;
   int get_number_of_viruses() const;
   int get_number_of_bonus(int row,int col) const;
   sf::Vector2f get_position_of_virus_number(int number) const;
   int get_total_vaccine_number() const;

    bool is_wall_on_field(int row,int col) const;
    bool is_vaccine_on_field(int row,int col) const;
    bool is_pacman_on_field(int row,int col) const;
    bool is_any_virus_on_field(int row,int col) const;
    bool is_bonus_on_field(int row,int col) const;

};


#endif