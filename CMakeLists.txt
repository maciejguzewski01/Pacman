cmake_minimum_required (VERSION 3.10)
  
project (PACMAN)

set ( SOURCES main.cpp  Pacman.cpp Coronavirus.cpp Board.cpp Manager.cpp SFMLapp.cpp Events.cpp Bonus.cpp Start.cpp)

add_compile_options(-Wall -Wextra -g)
include_directories( include SFML-2.5.1/include )
link_directories ( SFML-2.5.1/lib )

add_executable(main ${SOURCES} )

set_target_properties(main PROPERTIES
  CXX_STANDARD 11
  CXX_EXTENSIONS OFF
)

target_link_libraries (main sfml-graphics sfml-window sfml-system)


