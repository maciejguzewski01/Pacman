#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>





int main()
{
    std::cout<<"HELLO WORLD!"<<std::endl;
    /*
	sf::RenderWindow window(sf::VideoMode(800, 600), "Grafika w C++/SFML");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(1);

    MinesweeperBoard board;
	MSSFMLView view(board);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
                window.close();
        }
        
        window.clear();
        view.draw(window);
        window.display();
    }
*/
  return 0;
} 
