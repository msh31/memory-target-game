cmake_minimum_required(VERSION 3.13)  
project(memory-game)               
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

set(SOURCE_FILES 
    main.cpp 
    game.cpp
    player.cpp
    enemy.cpp 
)

add_executable(memory-game ${SOURCE_FILES})
