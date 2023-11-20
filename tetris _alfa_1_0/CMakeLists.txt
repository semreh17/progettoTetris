cmake_minimum_required(VERSION 3.26)
project(tetris)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(NCURSESW REQUIRED)
include_directories(${NCURSESW_INCLUDE_DIR})

add_executable(tetris main.cpp
                      funz_array.cpp
                      classe_matrice.cpp
                      classe_tetramino.cpp
        classe_griglia.h)

target_link_libraries(tetris ${NCURSESW_LIBRARY})










