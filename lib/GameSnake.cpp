//
//  GameSnake.cpp
//  Snake-C++
//
//  Created by PromiSe#### on 10.06.2020.
//  Copyright © 2020 PromiSe####. All rights reserved.
//

#include <cstdlib>
#include <time.h>

#include "GameMap.h"
#include "Vector2.h"
#include "GameSnake.h"

int GameSnake::rand() {
  using std::srand;
  srand(int(time(NULL)));
  return std::rand();
}

bool GameSnake::isNeedApple() {
  VectorMap apples = map.getVelueIndexes(int(RenderObject::APPLE));
  VectorMap becons = map.getVelueIndexes(int(RenderObject::BECON));
  return apples.size() + becons.size() < 1;
}

GameInfo GameSnake::getInfo() {
  GameInfo out;
  
  out.score = score;
  out.ticks = ticks;
  out.cuts = cuts;
  out.cutsCount = cutsCount;
  out.limitEat = limitEat;
  
  return out;
}

void GameSnake::setSize(int size) {
  map = GameMap(size, size);
}
void GameSnake::setSize(int width, int height) {
  map = GameMap(width, height);
}

void GameSnake::setScore(int newScore) {
  score = newScore;
}

void GameSnake::setCuts(int newCuts, bool convertCut) {
  cuts = newCuts;
  isConvertCut = convertCut;
}
void GameSnake::setCutsLimit(int limit) {
  limitEat = limit;
}

void GameSnake::setDir() {
  int randIndex = rand() % 4;
  setDir(Dicrections[randIndex]);
}
void GameSnake::setDir(Vector2 vec) {
  if(vec + previewDir != 0)
    dir.set(vec);
}

void GameSnake::pushSnake() {
  Vector2 start = map.getSize() / 2;
  
  int d = score;
  
  while (d > 0) {
    Vector2 delta = dir * (score - d) * -1;
    map.setValue(delta + start, d--);
  }
}

void GameSnake::pushApple() {
  VectorMap clear = map.getVelueIndexes(0);
  int randIndex = clear[rand() % clear.size()];
  map.setValue(randIndex, int(RenderObject::APPLE));
}

Vector2 GameSnake::getSize() {
  return map.getSize();
}

RenderMap GameSnake::getRenderMap() {
  Vector2 size = map.getSize();
  RenderMap out(size.y, RenderRow(size.x, RenderObject::CLEAR));
  
  for(int y = 0; y < size.y; y++ ) {
    for(int x = 0; x < size.x; x++) {
      int value = map.getValue(x, y);
      RenderObject now = RenderObject::BODY;
      
      if(value == 0) now = RenderObject::CLEAR;
      else if(value == int(RenderObject::BECON)) now = RenderObject::BECON;
      else if(value == int(RenderObject::APPLE)) now = RenderObject::APPLE;
      else if(value == 1) now = RenderObject::TAIL;
      else if(value == score) now = RenderObject::HEAD;
      
      out[y][x] = now;
    }
  }
  
  return out;
}

void GameSnake::deleteBecon() {
  if(limitEat == 0)
    return;
  
  if(ticks % limitEat != 0)
    return;
  
  Vector2Array becons = map.getValuePositions(int(RenderObject::BECON));
  
  if(becons.size() == 0)
    return;
  
  map.setValue(becons[rand() % becons.size()], 0);
}

bool GameSnake::cutTail(int cutScore) {
  if(cuts == 0)
    return false;
  
  if(cuts != -1 && cuts - (cutsCount++) <= 0)
    return false;
  
  for(int i = 1; i <= score; i++) {
    Vector2 pos = map.getValuePosition(i);
    
    if(i < cutScore)
      map.setValue(pos, isConvertCut ? int(RenderObject::BECON) : int(RenderObject::CLEAR));
    else if(i == cutScore)
      map.setValue(pos, int(RenderObject::BECON));
    else
      map.setValue(pos, i - cutScore);
  }
  
  score -= cutScore;
  
  return tick();
}

bool GameSnake::tick() {
  Vector2 nowPosition = map.getValuePosition(score);
  Vector2 newPosition = nowPosition + dir;

  int nextValue = map.getValue(newPosition);
  
  if(isNeedApple())
    pushApple();

  ticks++;
  previewDir.set(dir);

  if(nextValue == 0)
    return tick(score, newPosition);
  
  if(nextValue == int(RenderObject::APPLE) || nextValue == int(RenderObject::BECON)) {
    score++; map.setValue(newPosition, score);
    return true;
  }
  
  return cutTail(nextValue);
}

bool GameSnake::tick(int value, Vector2 newPosition) {
  if(value == score && isConvertCut)
    deleteBecon();
  
  Vector2 nowPosition = map.getValuePosition(value);
  
  map.moveValue(nowPosition, newPosition);
  
  if(value - 1 > 0)
    return tick(value - 1, nowPosition);
  
  return true;
}

void GameSnake::reset() {
  Vector2 size = map.getSize();
  score = 0;
  map = GameMap(size.x, size.y);
}
