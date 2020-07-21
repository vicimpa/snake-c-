//
//  GameMap.h
//  Snake-C++
//
//  Created by PromiSe#### on 16.06.2020.
//  Copyright © 2020 PromiSe####. All rights reserved.
//

#pragma once

#include <vector>
#include "Vector2.h"

//using VectorMap = std::vector<int>;
//using Vector2Array = std::vector<Vector2>;

typedef std::vector<int> VectorMap;
typedef std::vector<Vector2> Vector2Array;

class GameMap
{
  VectorMap map;

  int width;
  int height;

  void initializeMap(int w, int h);

public:
  GameMap();
  GameMap(int size);
  GameMap(int w, int h);

  int size();

  Vector2 getSize();
  
  Vector2 getPosition(int index);

  int getIndex(int x, int y);
  int getIndex(Vector2 vec);

  int getValueIndex(int value, int of = 0);

  Vector2 getValuePosition(int value, int of = 0);

  VectorMap getVelueIndexes(int value);

  Vector2Array getValuePositions(int value);

  int getValue(int index);
  int getValue(int x, int y);
  int getValue(Vector2 vec);

  void setValue(int index, int value);
  void setValue(int x, int y, int value);
  void setValue(Vector2 vec, int value);

  void moveValue(int indexA, int indexB);
  void moveValue(int xA, int yA, int xB, int yB);
  void moveValue(Vector2 vecA, Vector2 vecB);
};
