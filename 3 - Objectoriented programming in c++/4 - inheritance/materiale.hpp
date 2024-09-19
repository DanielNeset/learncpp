#pragma once

#include <iostream>
#include <string>

using namespace std;

class Material {
public:
  const string &get_name() const { return name; }
  double get_price() const { return price; }

protected:
  Material(const string &name_, double price_);
  void print() const;

private:
  string name;
  double price;
};

class Covering : public Material {
public:
  Covering(const string &name_, double price_, double width_);
  double get_width() const { return width; }
  void print() const;

private:
  double width;
};
