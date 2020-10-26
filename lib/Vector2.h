//
//  Vector2.h
//  Snake-C++
//
//  Created by PromiSe#### on 16.06.2020.
//  Copyright © 2020 PromiSe####. All rights reserved.
//

#pragma once

class Vector2 {
public:
  int x = 0, y = 0;
  
  Vector2();
  Vector2(Vector2 *vec);
  Vector2(int xy);
  Vector2(int nX, int nY);
  
  friend bool operator!=(const int & a, const Vector2 & b);
  friend bool operator!=(const Vector2 & a, const int & b);
  friend bool operator!=(const Vector2 & a, const Vector2 & b);
  
  friend bool operator==(const int & a, const Vector2 & b);
  friend bool operator==(const Vector2 & a, const int & b);
  friend bool operator==(const Vector2 & a, const Vector2 & b);
  
  Vector2& operator++();
  Vector2& operator--();
  Vector2& operator+=(const int& num);
  Vector2& operator+=(const Vector2& vec);
  
  Vector2& operator-=(const int& num);
  Vector2& operator-=(const Vector2& vec);
  
  Vector2& operator*=(const int& num);
  Vector2& operator*=(const Vector2& vec);
  
  Vector2& operator/=(const int& num);
  Vector2& operator/=(const Vector2& vec);
  
  friend Vector2 operator+(const int & a, const Vector2 & b);
  friend Vector2 operator+(Vector2 a, const int & b);
  friend Vector2 operator+(Vector2 a, const Vector2 & b);
  
  friend Vector2 operator-(const int & a, const Vector2 & b);
  friend Vector2 operator-(Vector2 a, const int & b);
  friend Vector2 operator-(Vector2 a, const Vector2 & b);
  
  friend Vector2 operator*(const int & a, const Vector2 & b);
  friend Vector2 operator*(Vector2 a, const int & b);
  friend Vector2 operator*(Vector2 a, const Vector2 & b);
  
  friend Vector2 operator/(const int & a, const Vector2 & b);
  friend Vector2 operator/(Vector2 a, const int & b);
  friend Vector2 operator/(Vector2 a, const Vector2 & b);
  
  Vector2& add(int xy);
  Vector2& add(int nX, int nY);
  Vector2& add(const Vector2& vec);
  
  Vector2& del(int xy);
  Vector2& del(int nX, int nY);
  Vector2& del(const Vector2& vec);
  
  Vector2& mul(int xy);
  Vector2& mul(int nX, int nY);
  Vector2& mul(const Vector2& vec);
  
  Vector2& div(int xy);
  Vector2& div(int nX, int nY);
  Vector2& div(const Vector2& vec);
  
  Vector2& set(int xy);
  Vector2& set(int nX, int nY);
  Vector2& set(const Vector2& vec);
  
  bool equal(int num) const;
  bool equal(const Vector2& vec) const;
  
  Vector2 clone();
};
