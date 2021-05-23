#ifndef SFMLAPP_H
#define SFMLAPP_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>
#include "Pacman.h"
#include "Coronavirus.h"
#include "Board.h"
#include "Manager.h"
#include <cstring>


class SFMLapp
{
    Pacman & pacman_sfml;
    Board & board_sfml;
    Manager & manager_sfml;


    // sf::CircleShape pacman;
   sf::RectangleShape wall;
  
   void draw_board(sf::RenderWindow & win);

   sf::Text txt;
   sf::Font font1;
   
   sf::Texture virus_t;
   sf::Sprite virus;
   sf::Texture vaccine_t;
   sf::Sprite vaccine;
   sf::Texture heart_t;
   sf::Sprite heart;
sf::Clock clk;
bool test=1;
void pacman_icon_movment();
sf::Texture pacman_static;
sf::Texture pacman_north;
sf::Texture pacman_south;
sf::Texture pacman_east;
sf::Texture pacman_west;
sf::Sprite pacman;
    public:
    SFMLapp(Pacman & pacman_sfml, Board & board_sfml, Manager & manager_sfml);

    void draw(sf::RenderWindow & win);
};


#endif