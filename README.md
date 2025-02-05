# Pacman

Pacman is a remake of the classic Pacman game, inspired by the pandemic. It was created using the SFML library.

## Overview of gameplay

The player controls Pacman's movements. Pacman earns points by eating the vaccines. To win, all vaccines must be collected.

The equivalent of the ghosts are viruses. They move randomly across the board – when they encounter Pacman, he loses one life (if the number of lives drops to 0, the game is over) and the board resets.

In addition to the classic Pacman rules, a bonus system has been implemented. Bonuses generate randomly on the board and can either help or hinder the player.

At the beginning of the game, the player can choose the difficulty level, their name, and the board layout (one of five predefined options or random). The game begins with a manual, and at the end, the last 10 rounds are displayed.
## List of classes and other files

Each class consists of a .h and .cpp file. 

### Classes
- Board
- Bonus
- Coronavirus
- Events
- Manager
- Pacman
- SFMLapp
- Start

### Other files
- .replit
- .gitignore
- CMakeLists.txt
- README.md
- wyniki.txt - it stores the results of the last 10 games
- Calibri.ttf, LibreBaskerville-Regular.ttf - fonts
- *.png files in \resources and its subdirectories - textures

## Bonus list
When a bonus is activated, the player receives an announcement with the results (inspired by pandemic events).

Enum name / bonus name / icon / action

- SCHOOL / schools opening / the bell / viruses multiply twice
- PLANE / package from China / the plane / for 20 seconds, Pacman is immune to viruses
- BORDER / borders opening / the open barrier / vaccines reappear in empty fields
- BRITAIN / British tea / the cup / viruses double their speed
- RESPIRATOR / respirator / red cross / number of lives increases to 4
- LOCKDOWN / hard lockdown / the closed padlock / viruses freeze for 20 seconds
- SUMMER / virus in retreat / the sun / viruses return to the starting point
- LITE_LOCKDOWN / light lockdown / the open padlock / viruses reduce their speed
- DEATH / increased mortality / the grave / the number of viruses decreases by half
- ANTIVAXXERS / antivax population increases / the crossed brain / each vaccine counts as two points
