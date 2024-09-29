#pragma once
#include <string>

using namespace std;

class Material {
public:
  Material(const string &name_, double price_);

  const string get_name() const { return name; }
  double get_price() const { return price; }
  void print() const;

protected:
  string name;
  double price;
};

class Covering : public Material {
public:
  Covering(const string &name, double price, double width_);
  void print() const;

protected:
  double width;
};

class Wallpaper : public Material {
public:
  Wallpaper(const string &name, double price, double length_, double width_);
  void print() const;

protected:
  double length;
  double width;
};

class Paint : public Material {
public:
  Paint(const string &name, double price, int coating_, double liters_per_m2_);
  void print() const;

protected:
  int coating;
  double liters_per_m2;
};
