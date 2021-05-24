#ifndef BONUS_H
#define BONUS_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Pacman.h"
#include "Coronavirus.h"
#include "Board.h"
#include <iostream>
#include <vector>

enum Bonus_type{NONE,SCHOOL,TYPE_TWO,TYPE_THREE,TYPE_FOUR,TYPE_FIVE,TYPE_SIX,TYPE_SEVEN,TYPE_EIGHT,TYPE_NINE,TYPE_TEN };

class Bonus
{
    Pacman & pacman_b;
    Board & board_b;
    std::vector<Bonus_type> bonuses_types;
  Bonus_type rand_type_of_bonus();
    public:
    explicit Bonus(Pacman & pacman_b, Board & board_b);
};


#endif