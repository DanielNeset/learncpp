#include "fraction.hpp"
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int numberator, int denominator) {
  set(numberator, denominator);
}

void Fraction::set(int numberator_, int denominator_) {
  if (denominator_ != 0) {
    numerator = numberator_;
    denominator = denominator_;
    reduce();
  } else {
    throw "nevneren ble null";
  }
}

Fraction Fraction::operator+(const Fraction &other) const {
  Fraction fraction = *this;
  fraction += other;
  return fraction;
}

Fraction Fraction::operator+(int integer) const {
  Fraction fraction;
  fraction.set(integer);
  fraction += *this;
  return fraction;
}

Fraction operator+(int integer, const Fraction &other) {
  Fraction fraction;
  fraction = other + integer;
  return fraction;
}

Fraction &Fraction::operator+=(const Fraction &other) {
  set(numerator * other.denominator + denominator * other.numerator, denominator * other.denominator);
  return *this;
}

Fraction &Fraction::operator++() {
  numerator += denominator;
  return *this;
}

// Fraction this - fraction other
Fraction Fraction::operator-(const Fraction &other) const {
  Fraction fraction = *this;
  fraction -= other;
  return fraction;
}

// Fraction - 1
Fraction Fraction::operator-(int integer) const {
  Fraction integerFraction(integer, 1);
  Fraction result = *this;
  result -= integerFraction;
  return result;
}

// Takes integer - fraction
Fraction operator-(int integer, const Fraction &other) {
  Fraction integerFraction(integer, 1);
  return integerFraction - other;
}

Fraction &Fraction::operator-=(const Fraction &other) {
  set(numerator * other.denominator - denominator * other.numerator, denominator * other.denominator);
  return *this;
}

Fraction &Fraction::operator--() {
  numerator -= denominator;
  return *this;
}

Fraction Fraction::operator-() const {
  Fraction fraction;
  fraction.numerator = -numerator;
  fraction.denominator = denominator;
  return fraction;
}

Fraction Fraction::operator*(const Fraction &other) const {
  Fraction fraction = *this;
  fraction *= other;
  return fraction;
}

Fraction &Fraction::operator*=(const Fraction &other) {
  set(numerator * other.numerator, denominator * other.denominator);
  return *this;
}

Fraction Fraction::operator/(const Fraction &other) const {
  Fraction fraction = *this;
  fraction /= other;
  return fraction;
}

Fraction &Fraction::operator/=(const Fraction &other) {
  set(numerator * other.denominator, denominator * other.numerator);
  return *this;
}

Fraction &Fraction::operator=(const Fraction &other) {
  numerator = other.numerator;
  denominator = other.denominator;
  return *this;
}

bool Fraction::operator==(const Fraction &other) const {
  return (compare(other) == 0) ? true : false;
}

bool Fraction::operator!=(const Fraction &other) const {
  return (compare(other) != 0) ? true : false;
}

bool Fraction::operator<=(const Fraction &other) const {
  return (compare(other) <= 0) ? true : false;
}

bool Fraction::operator>=(const Fraction &other) const {
  return (compare(other) >= 0) ? true : false;
}

bool Fraction::operator<(const Fraction &other) const {
  return (compare(other) < 0) ? true : false;
}

bool Fraction::operator>(const Fraction &other) const {
  return (compare(other) > 0) ? true : false;
}

void Fraction::reduce() {
  if (denominator < 0) {
    numerator = -numerator;
    denominator = -denominator;
  }
  int a = numerator;
  int b = denominator;
  int c;
  if (a < 0)
    a = -a;

  while (b > 0) {
    c = a % b;
    a = b;
    b = c;
  }
  numerator /= a;
  denominator /= a;
}

int Fraction::compare(const Fraction &other) const {
  Fraction fraction = *this - other;
  if (fraction.numerator > 0)
    return 1;
  else if (fraction.numerator == 0)
    return 0;
  else
    return -1;
}
