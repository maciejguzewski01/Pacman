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
   
    Board board_test(pacman_test,FIRST);
   
    Manager manager_test(pacman_test,board_test);

    SFMLapp sfml_test(pacman_test,board_test,manager_test);

    std::cout<<"HELLO WORLD!"<<std::endl;

sf::RenderWindow window(sf::VideoMode(800, 600), "TEST");
window.setVerticalSyncEnabled(false);
window.setFramerateLimit(20);

     while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
            {
              window.close();
            }   
        }    
        window.clear();
        sfml_test.draw(window);
        window.display(); 
    }
  return 0;
} 
  
