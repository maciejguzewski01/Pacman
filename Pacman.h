#ifndef PACMAN_H
#define PACMAN_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <string>

//TA KLASA JEST MATEMATYCZNĄ REPREZENTACJĄ PACMANA (POSTACI STEROWANEJ PRZEZ GRACZA)
/*Zadania klasy;
1. Zna, modyfikuje i zwraca pozycję pacmana
1b. zna kierunek ruchu pacmana i na jego podstawie sprawdza pozycję nastepnego pola  
2. zna i zwraca imię pacmana 
3. zna i zwraca ilość żyć (a także ustawia żądaną ilość) 
4. zna i zwraca prędkość 

*/
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

 //Funkcje modyfikujące cechy obiektu 
  void set_position_to(int row,int col);
  void move(Move_direction direction);
  void remove_live();
  void set_lives_number(int number);

  //Funkcje zwracające informacje 
    std::string get_name() const ;
    sf::Vector2f get_position() const;
    Move_direction get_move_to() const;
    sf::Vector2f get_next_field_location(Move_direction direction) const;
    double get_pacman_speed() const;
    int get_lives_number() const;
};



#endif