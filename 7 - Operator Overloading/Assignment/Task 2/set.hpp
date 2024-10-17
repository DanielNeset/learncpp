#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Set {

public:
  Set() = default;
  Set(const Set &other) = default;

  Set operator+(const Set &other) const;
  Set &operator+=(int value);
  Set &operator=(const Set &other);

  friend ostream &operator<<(ostream &os, const Set &set);

private:
  vector<int> elements;
  bool contains(int value) const;
};
