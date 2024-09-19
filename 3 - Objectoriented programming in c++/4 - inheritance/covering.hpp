#pragma once

#include "materiale.hpp"

using namespace std;

class Covering : public Material {
public:
  Covering(const string &name_, double price_, double width_);
  double getWidth() const { return width; }
  void println() const override; // Not good pratice to use override

private:
  double width;
};
