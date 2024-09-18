#pragma once

#include "surface.hpp"
#include <string>

using namespace std;

const double limit = 0.02;

class Covering {
public:
  Covering(string name_, double price_, double width_);
  string get_name() const { return name; }
  double get_price() const { return price; }
  double get_width() const { return width; }

  double get_meters(const Surface &surface) const;
  double get_price(const Surface &surface) const;

private:
  string name;
  double price;
  double width;
};
