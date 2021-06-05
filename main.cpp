#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Start.h"

#include <iostream>
#include "Pacman.h"
#include "Coronavirus.h"
#include "Board.h"
#include "Manager.h"
#include <cstdlib>
#include <ctime>
#include "SFMLapp.h"
#include "Events.h"
#include "Bonus.h"

int main()
{
    srand(time(0));
   
sf::RenderWindow window(sf::VideoMode(800, 600), "PACMAN");
window.setVerticalSyncEnabled(false);
window.setFramerateLimit(100);


sf::RenderWindow window_start(sf::VideoMode(800, 600), "PACMAN");
window_start.setVerticalSyncEnabled(false);
window_start.setFramerateLimit(5);

Start start_test;

while (window_start.isOpen())
    {
        sf::Event event;
        while (window_start.pollEvent(event))
        {               
            if (event.type == sf::Event::Closed) 
            {
              window_start.close();
              window.close();
            }   
            else if(event.type == sf::Event::MouseButtonPressed)
              {
                start_test.mouse_was_pressed(event);
              }
              else if(event.type == sf::Event::TextEntered )
            {
              start_test.text_was_entered(event);
            }       
           
        }    
        window_start.clear(sf::Color(209,162,6));
        
       start_test.draw(window_start);
        
        window_start.display(); 

    }


Pacman pacman_test(start_test.get_choosed_name());
   
Board board_test(pacman_test,start_test.get_choosed_level(),start_test.get_choosed_board());
    
Bonus bonus_test(pacman_test,board_test);
   
Manager manager_test(pacman_test,board_test,bonus_test);

SFMLapp sfml_test(pacman_test,board_test,bonus_test,manager_test);

Events events_test(pacman_test,board_test,bonus_test,manager_test,sfml_test);

while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
            {
              window.close();
            }   
            else if(event.type == sf::Event::KeyPressed) 
              {
                events_test.key_was_pressed(event);
              }
              else if(event.type == sf::Event::MouseButtonPressed)
              {
                events_test.mouse_was_pressed(event);
              }   
        }    
        window.clear();
        
        sfml_test.draw(window);
        
        window.display(); 
    
        
    }
  return 0;
} 
  
