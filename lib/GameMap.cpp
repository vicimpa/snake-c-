//
//  GameMap.cpp
//  Snake-C++
//
//  Created by PromiSe#### on 10.06.2020.
//  Copyright © 2020 PromiSe####. All rights reserved.
//

#include "GameMap.h"

void GameMap::initializeMap(int w, int h)
{
  width = w;
  height = h;
  map = VectorMap(width * height);
}

GameMap::GameMap() {
  initializeMap(10, 10);
}
GameMap::GameMap(int size) {
  initializeMap(size, size);
}
GameMap::GameMap(int w, int h) {
  initializeMap(w, h);
}

int GameMap::size() {
  return int(map.size());
}

Vector2 GameMap::getSize() {
  return Vector2(width, height);
}

Vector2 GameMap::getPosition(int index) {
  int x = index % width;
  int y = (index - x) / width;
  return Vector2(x, y);
}

int GameMap::getIndex(int x, int y) {
  (x %= width) < 0 ? x+= width : 0;
  (y %= height) < 0 ? y+= height : 0;

  return y * width + x;
}
int GameMap::getIndex(Vector2 vec) {
  return getIndex(vec.x, vec.y);
}

int GameMap::getValueIndex(int value, int of) {
  for (int i = of; i < size(); i++)
    if (map[i] == value)
      return i;

  return -1;
}

Vector2 GameMap::getValuePosition(int value, int of) {
  int index = getValueIndex(value, of);

  if(index != -1)
    return getPosition(index);

  return Vector2(-1, -1);
}

VectorMap GameMap::getVelueIndexes(int value) {
  VectorMap out;

  for(int i = 0; i < size(); i++)
    if(map[i] == value)
      out.push_back(i);

  return out;
}

Vector2Array GameMap::getValuePositions(int value) {
  Vector2Array out;

  for(int i = 0; i < size(); i++)
    if(map[i] == value)
      out.push_back(getPosition(i));

  return out;
}

int GameMap::getValue(int index) {
  return map[index];
}
int GameMap::getValue(int x, int y) {
  return getValue(getIndex(x, y));
}
int GameMap::getValue(Vector2 vec) {
  return getValue(getIndex(vec));
}

void GameMap::setValue(int index, int value) {
  map[index] = value;
}
void GameMap::setValue(int x, int y, int value) {
  setValue(getIndex(x, y), value);
}
void GameMap::setValue(Vector2 vec, int value) {
  setValue(getIndex(vec), value);
}

void GameMap::moveValue(int indexA, int indexB) {
  std::swap(map[indexA], map[indexB]);
}
void GameMap::moveValue(int xA, int yA, int xB, int yB) {
  moveValue(getIndex(xA, yA), getIndex(xB, yB));
}
void GameMap::moveValue(Vector2 vecA, Vector2 vecB) {
  moveValue(getIndex(vecA), getIndex(vecB));
}
