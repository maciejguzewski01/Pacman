#ifndef START_H
#define START_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include "Board.h"


enum App_screen{HELLO,LEVEL, BOARD_TYPE,NAME,INSTRUCTION};
class Start
{
    sf::Font font1,font2;
    sf::Text txt,txt2;
    sf::Sprite virus;
    sf::Texture virus_t;
    sf::Sprite wave;
    sf::Texture wave_t;
    
    App_screen state;
    sf::RectangleShape rect;

    sf::Sprite cube;
    sf::Texture cube_t;
    sf::Sprite one;
    sf::Texture one_t;
    sf::Sprite two;
    sf::Texture two_t;
    sf::Sprite three;
    sf::Texture three_t;
    sf::Sprite four;
    sf::Texture four_t;
    sf::Sprite five;
    sf::Texture five_t;

    void draw_hello_state(sf::RenderWindow & win);
    void draw_level_state(sf::RenderWindow & win);
    void draw_board_type_state(sf::RenderWindow & win);
    void draw_name_state(sf::RenderWindow & win);

    Level_name choosed_level;
    Board_order choosed_board;
    std::string choosed_name;
    
    void mouse_hello_state(sf::Event event);
    void mouse_level_state(sf::Event event);
    void mouse_board_type_state(sf::Event event);
    void mouse_name_state(sf::Event event);

    public:
    explicit Start();
    void draw(sf::RenderWindow & win);
    void mouse_was_pressed(sf::Event event);
    void text_was_entered(sf::Event event);
    
};



#endif