#ifndef SFMLAPP_H
#define SFMLAPP_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>
#include "Pacman.h"
#include "Coronavirus.h"
#include "Board.h"
#include "Manager.h"


class SFMLapp
{
    Pacman & pacman_sfml;
    Board & board_sfml;
    Manager & manager_sfml;
    public:
    SFMLapp(Pacman & pacman_sfml, Board & board_sfml, Manager & manager_sfml);

    void draw(sf::RenderWindow & win);
};


#endif