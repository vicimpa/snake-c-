#!/bin/sh

#  Script.sh
#  Snake-C++
#
#  Created by PromiSe#### on 12.06.2020.
#  Copyright © 2020 PromiSe####. All rights reserved.

g++ -Os -std=c++17 -c lib/Vector2.cpp -o lib/Vector2.o
g++ -Os -std=c++17 -c lib/GameMap.cpp -o lib/GameMap.o
g++ -Os -std=c++17 -c lib/GameSnake.cpp -o lib/GameSnake.o

g++ -o launch_snake.exe \
  main.cpp \
  lib/Vector2.o \
  lib/GameSnake.o \
  lib/GameMap.o \
  -Os -std=c++17 -pthread -lncurses

rm lib/*.o
