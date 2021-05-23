#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>
#include "Pacman.h"
#include "Coronavirus.h"
#include "Board.h"
#include "Manager.h"
#include <cstdlib>
#include <ctime>
#include "SFMLapp.h"
#include "Events.h"






int main()
{
    srand(time(0));
   
    Pacman pacman_test("nazwa");
   
    Board board_test(pacman_test,FIRST,RANDOM);
   
    Manager manager_test(pacman_test,board_test);

    SFMLapp sfml_test(pacman_test,board_test,manager_test);

    Events events_test(pacman_test,board_test,manager_test,sfml_test);

    std::cout<<"HELLO WORLD!"<<std::endl;

sf::RenderWindow window(sf::VideoMode(800, 600), "TEST");
window.setVerticalSyncEnabled(false);
window.setFramerateLimit(40);

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
        }    
        window.clear();
        
        sfml_test.draw(window);
        
        window.display(); 
    
        
    }
  return 0;
} 
  
