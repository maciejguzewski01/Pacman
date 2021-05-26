#ifndef PACMAN_H
#define PACMAN_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <string>

//TA KLASA JEST MATEMATYCZNĄ REPREZENTACJĄ PACMANA (POSTACI STEROWANEJ PRZEZ GRACZA)
enum Move_direction{ANY,NORTH,SOUTH,WEST,EAST};

class Pacman
{
  const std::string name;
  sf::Vector2f position;
  int lives;
  double speed;
  Move_direction move_to;

  public:
  explicit Pacman(std::string name);
  std::string get_name() const ;
  sf::Vector2f get_position() const;
  void move(Move_direction direction);
  sf::Vector2f get_next_field_location(Move_direction direction);

  int get_lives_number();
  double get_pacman_speed();
  void remove_live();
  void set_position_to(int row,int col);
  Move_direction get_move_to();
  void set_lives_number(int number);
};



#endif