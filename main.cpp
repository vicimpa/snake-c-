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
  std::this_thread::sleep_for(
    std::chrono::nanoseconds(nanoseconds*1000));
}

namespace GUI {
  #include <curses.h>
}

void inputHandler(GameSnake *game) {
  using namespace GUI;

  while (true) {
    switch (getch()) {
      case 'w':
      case 'W':
      case KEY_UP:
      {
        game->setDir({ 0, -1 });
      } break;

      case 'a':
      case 'A':
      case KEY_LEFT:
      {
        game->setDir({ -1, 0 });
      } break;

      case 'd':
      case 'D':
      case KEY_RIGHT:
      {
        game->setDir({ 1, 0 });
      } break;

      case 's':
      case 'S':
      case KEY_DOWN:
      {
        game->setDir({ 0, 1 });
      } break;
    }
  }
};

void runGame(GameSnake *game) {
  using namespace GUI;
  
  while (game->tick()) {
    Vector2 size = game->getSize();
    RenderMap out = game->getRenderMap();

    for(int x = 0; x < size.x*2+1; x++ ){
      mvaddstr(0, x, "#");
      mvaddstr(size.y+1, x, "#");
    }

    for(int y = 0; y < size.y+1; y++) {
      mvaddstr(y, 0, "#");
      mvaddstr(y, size.x*2, "#");
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

  GameSnake game;

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
  keypad(stdscr, TRUE);

  thread input(inputHandler, &game);

  runGame(&game);

  nodelay(stdscr, FALSE);
  keypad(stdscr, FALSE);
  getch();
  endwin();
  
  return 0;
}
