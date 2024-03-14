cmake_minimum_required(VERSION 3.27)
project(PProyecto_parcial_rpg)

set(CMAKE_CXX_STANDARD 17)

add_executable(PProyecto_parcial_rpg main.cpp
    Character/Character.cpp
    Character/Character.h
    Combat/Combat.cpp
    Combat/Combat.h
    Enemy/Enemy.cpp
    Enemy/Enemy.h
    Player/Player.cpp
    Player/Player.h
    Utils.h)
