#ifndef SFMLAPP_H
#define SFMLAPP_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>
#include "Pacman.h"
#include "Coronavirus.h"
#include "Board.h"
#include "Manager.h"
#include "Bonus.h"
#include <cstring>
#include <vector>

enum SFML_state {GAME,BONUS,DIED,RESULTS};

class SFMLapp
{
    Pacman & pacman_sfml;
    Board & board_sfml;
    Bonus & bonus_sfml;
    Manager & manager_sfml;
    SFML_state state;
  
   sf::RectangleShape wall;
   sf::RectangleShape back;
  
   void draw_board(sf::RenderWindow & win);

   sf::Text txt;
   sf::Font font1;
   sf::Text txt2;
   sf::Font font2;
   
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

void draw_game_over(sf::RenderWindow & win);
void draw_game_results(sf::RenderWindow & win);
 
std::vector<std::string> results;
int nr=0;
 sf::RectangleShape rect;
bool end=false;

void draw_bonus(int row,int col, sf::RenderWindow & win);
   sf::Texture bell_t;
   sf::Sprite bell;
   sf::Texture sun_t;
   sf::Sprite sun;
   sf::Texture red_cross_t;
   sf::Sprite red_cross;
   sf::Texture lite_lockdown_t;
   sf::Sprite lite_lockdown;
   sf::Texture lockdown_t;
   sf::Sprite lockdown;
   sf::Texture tea_t;
   sf::Sprite tea;
   sf::Texture antivaxx_t;
   sf::Sprite antivaxx;
   sf::Texture grave_t;
   sf::Sprite grave;
   sf::Texture barrier_t;
   sf::Sprite barrier;
   sf::Texture plane_t;
   sf::Sprite plane;
   sf::Texture pacman_uniform_t;
   sf::Sprite pacman_uniform;

   void draw_bonus_info(sf::RenderWindow & win);


   void draw_bonus_one_info(sf::RenderWindow & win);
   void draw_bonus_two_info(sf::RenderWindow & win);
   void draw_bonus_three_info(sf::RenderWindow & win);
   void draw_bonus_four_info(sf::RenderWindow & win);
   void draw_bonus_five_info(sf::RenderWindow & win);
   void draw_bonus_six_info(sf::RenderWindow & win);
   void draw_bonus_seven_info(sf::RenderWindow & win);
   void draw_bonus_eight_info(sf::RenderWindow & win);
   void draw_bonus_nine_info(sf::RenderWindow & win);
   void draw_bonus_ten_info(sf::RenderWindow & win);

    public:
    explicit SFMLapp(Pacman & pacman_sfml, Board & board_sfml,Bonus & bonus_sfml, Manager & manager_sfml);

    void draw(sf::RenderWindow & win);
    SFML_state get_sfml_app_state();
    void end_bonus();
    void set_app_state(SFML_state new_state);
    void end_game();

};


#endif