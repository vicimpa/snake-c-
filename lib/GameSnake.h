//
//  GameSnake.h
//  Snake-C++
//
//  Created by PromiSe#### on 16.06.2020.
//  Copyright © 2020 PromiSe####. All rights reserved.
//

#pragma once

#include <vector>

enum class RenderObject {
  APPLE = 25565,
  BECON = 25565 - 1,
  CLEAR = 0,
  HEAD = 1,
  BODY = 2,
  TAIL = 3
};

typedef std::vector<RenderObject> RenderRow;
typedef std::vector<RenderRow> RenderMap;

struct GameInfo {
  int score;
  int ticks;
  int cuts;
  int cutsCount;
  int limitEat;
};

class GameSnake
{
  GameMap map;
  
  int score = 4;
  int ticks = 0;
  int cuts = -1;
  int cutsCount = 0;
  int limitEat = 10;
  bool isConvertCut = true;
  
  Vector2 dir;
  Vector2 previewDir;
  
  int rand();
  
  bool isNeedApple();
  
  Vector2 Dicrections[4] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
  
public:
  GameSnake() = default;
  
  GameInfo getInfo();
  
  void setSize(int size);
  void setSize(int width, int height);
  
  void setScore(int newScore);
  
  void setCuts(int newCuts, bool convertCut);
  
  void setCutsLimit(int limit);
  
  void setDir();
  void setDir(Vector2 vec);
  
  void pushSnake();
  
  void pushApple();
  
  Vector2 getSize();
  
  RenderMap getRenderMap();
  
  void deleteBecon();
  
  bool cutTail(int cutScore);
  
  bool tick();
  bool tick(int value, Vector2 newPosition);
  
  void reset();
};

