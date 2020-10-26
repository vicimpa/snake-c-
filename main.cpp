//
//  main.cpp
//  Snake-C++
//
//  Created by PromiSe#### on 10.06.2020.
//  Copyright © 2020 PromiSe####. All rights reserved.
//

#include <chrono>

#include <iostream>
#include <string>
#include <thread>

#include "lib/GameMap.h"
#include "lib/Vector2.h"
#include "lib/GameSnake.h"

void usleep(int nanoseconds) {
  std::this_thread::sleep_for(std::chrono::nanoseconds(nanoseconds*1000));
}

namespace GUI {
  #include <curses.h>
}

GameSnake game;

void inputHandler() {
  using namespace GUI;
  
  while (true) {
    switch (getch()) {
      case 119: {
        game.setDir({ 0, -1 });
      } break;
      case 97: {
        game.setDir({ -1, 0 });
      } break;
      case 100: {
        game.setDir({ 1, 0 });
      } break;
      case 115: {
        game.setDir({ 0, 1 });
      } break;

      case 0x1b: {
        usleep(100);
        
        switch (getch()) {
          case 0x5b: {
            usleep(100);

            switch (getch()) {
              case 0x41: game.setDir({0, -1}); break;
              case 0x42: game.setDir({0, 1});  break;
              case 0x43: game.setDir({1, 0});  break;
              case 0x44: game.setDir({-1, 0}); break;
            }

          } break;
        }
      } break;
    }
    
    usleep(1000);
  }
};

void runGame() {
  using namespace GUI;
  
  while (game.tick()) {
    Vector2 size = game.getSize();
    RenderMap out = game.getRenderMap();

    for(int y = -1; y < size.y+1; y++) {
      for(int x = 0; x < size.x*2 + 1; x++) {
        if(y == 0) mvaddstr(y, x + 1, "#"); else mvaddstr(y, x + 1, " ");
        if(y == size.y - 1) mvaddstr(y+2, x + 1, "#"); else mvaddstr(y+2, x, " ");
        if(x == 0) mvaddstr(y+1, x, "#"); else mvaddstr(y+1, x, " ");
        if(x == size.x*2) mvaddstr(y+1, x+1, "#"); else mvaddstr(y+1, x+1, " ");
      }
    }

    for(int y = 0; y < out.size(); y++) {
      for(int x = 0; x < out[y].size(); x++) {
        switch (out[y][x]) {
          case RenderObject::APPLE: mvaddstr(y+1, x*2 + 1, "O"); break;
          case RenderObject::BECON: mvaddstr(y+1, x*2 + 1, "$"); break;
          case RenderObject::HEAD:  mvaddstr(y+1, x*2 + 1, "*"); break;
          case RenderObject::BODY:  mvaddstr(y+1, x*2 + 1, "*"); break;
          case RenderObject::TAIL:  mvaddstr(y+1, x*2 + 1, "+"); break;
          default:                  mvaddstr(y+1, x*2 + 1, " "); break;
        }
      }
    }
    
    usleep(150000);
  }
}

int main() {
  using std::thread;

  using namespace GUI;

  game.setSize(38,22);
  game.setDir();
  game.setScore(4);
  game.pushSnake();
  game.pushApple();

  initscr();
  cbreak();
  noecho();

  nodelay(stdscr, TRUE);
  scrollok(stdscr, TRUE);

  thread input(inputHandler);

  runGame();

  nodelay(stdscr, FALSE);
  getch();
  endwin();
  
  return 0;
}
