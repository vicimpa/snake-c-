//
//  Vector2.cpp
//  Snake-C++
//
//  Created by PromiSe#### on 10.06.2020.
//  Copyright © 2020 PromiSe####. All rights reserved.
//

#include "Vector2.h"

Vector2::Vector2() { x = 0; y = 0; }
Vector2::Vector2(Vector2 *vec){ set(vec); }
Vector2::Vector2(int xy){ set(xy); }
Vector2::Vector2(int nX, int nY) { set(nX, nY); }

bool operator!=(const int & a, const Vector2 & b) {
  return !b.equal(a);
}
bool operator!=(const Vector2 & a, const int & b) {
  return !a.equal(b);
}
bool operator!=(const Vector2 & a, const Vector2 & b) {
  return !a.equal(b);
}

bool operator==(const int & a, const Vector2 & b) {
  return b.equal(a);
}
bool operator==(const Vector2 & a, const int & b) {
  return a.equal(b);
}
bool operator==(const Vector2 & a, const Vector2 & b) {
  return a.equal(b);
}

Vector2& Vector2::operator++(){
  return this->add(1);
}

Vector2& Vector2::operator--(){
  return this->add(-1);
}

Vector2& Vector2::operator+=(const int& num){
  return this->add(num);
}
Vector2& Vector2::operator+=(const Vector2& vec){
  return this->add(vec);
}

Vector2& Vector2::operator-=(const int& num){
  return this->del(num);
}
Vector2& Vector2::operator-=(const Vector2& vec){
  return this->del(vec);
}

Vector2& Vector2::operator*=(const int& num){
  return this->mul(num);
}
Vector2& Vector2::operator*=(const Vector2& vec){
  return this->mul(vec);
}

Vector2& Vector2::operator/=(const int& num){
  return this->div(num);
}
Vector2& Vector2::operator/=(const Vector2& vec){
  return this->div(vec);
}

Vector2 operator+(const int & a, const Vector2 & b) {
  return Vector2(a).add(b);
}
Vector2 operator+(const Vector2 & a, const int & b) {
  return Vector2(a).add(b);
}
Vector2 operator+(const Vector2 & a, const Vector2 & b) {
  return Vector2(a).add(b);
}

Vector2 operator-(const int & a, const Vector2 & b) {
  return Vector2(a).del(b);
}
Vector2 operator-(const Vector2 & a, const int & b) {
  return Vector2(a).del(b);
}
Vector2 operator-(const Vector2 & a, const Vector2 & b) {
  return Vector2(a).del(b);
}

Vector2 operator*(const int & a, const Vector2 & b) {
  return Vector2(a).mul(b);
}
Vector2 operator*(const Vector2 & a, const int & b) {
  return Vector2(a).mul(b);
}
Vector2 operator*(const Vector2 & a, const Vector2 & b) {
  return Vector2(a).mul(b);
}

Vector2 operator/(const int & a, const Vector2 & b) {
  return Vector2(a).div(b);
}
Vector2 operator/(const Vector2 & a, const int & b) {
  return Vector2(a).div(b);
}
Vector2 operator/(const Vector2 & a, const Vector2 & b) {
  return Vector2(a).div(b);
}

bool operator&&(const Vector2 & a, const Vector2 & b) {
  return a != 0 && b != 0;
}

Vector2& Vector2::add(int xy) { x += xy; y += xy; return *this; }
Vector2& Vector2::add(int nX, int nY) { x += nX; y += nY; return *this; }
Vector2& Vector2::add(Vector2 vec) { x+= vec.x; y += vec.y; return *this; }

Vector2& Vector2::del(int xy) { x -= xy; y -= xy; return *this; }
Vector2& Vector2::del(int nX, int nY) { x -= nX; y -= nY; return *this; }
Vector2& Vector2::del(Vector2 vec) { x-= vec.x; y -= vec.y; return *this; }

Vector2& Vector2::mul(int xy) { x *= xy; y *= xy; return *this; }
Vector2& Vector2::mul(int nX, int nY) { x *= nX; y *= nY; return *this; }
Vector2& Vector2::mul(Vector2 vec) { x*= vec.x; y *= vec.y; return *this; }

Vector2& Vector2::div(int xy) { x /= xy; y /= xy; return *this; }
Vector2& Vector2::div(int nX, int nY) { x /= nX; y /= nY; return *this; }
Vector2& Vector2::div(Vector2 vec) { x/= vec.x; y /= vec.y; return *this; }

Vector2& Vector2::set(int xy) { x = xy; y = xy; return *this; }
Vector2& Vector2::set(int nX, int nY) { x = nX; y = nY; return *this; }
Vector2& Vector2::set(Vector2 vec) { x= vec.x; y = vec.y; return *this; }

bool Vector2::equal(int num) const {  return x == num && y == num; }
bool Vector2::equal(Vector2 vec) const { return x == vec.x && y == vec.y; }

Vector2 Vector2::clone() { return Vector2(x, y); }
