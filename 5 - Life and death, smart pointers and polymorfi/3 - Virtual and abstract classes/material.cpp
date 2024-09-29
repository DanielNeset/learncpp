#include "material.hpp"
#include <iostream>
#include <string>

using namespace std;

const double limit = 0.02;

Material::Material(const string &name_, double price_) : name(name_), price(price_) {}

void Material::print() const {
  cout << "Name: " << name << endl
       << "Price: " << price << endl;
}
double Material::price_total(const Surface &surface) const {
  return units_needed(surface) * price;
}

Covering::Covering(const string &name, double price, double width_) : Material(name, price), width(width_) {}

void Covering::print() const {
  Material::print();
  cout << "For coverage: " << endl
       << "Width: " << width << endl;
}

double Covering::units_needed(const Surface &surface) const {
  int lengths = surface.get_length() / width;
  double remainder = surface.get_length() - lengths * width;
  if (remainder >= limit)
    ++lengths;
  return lengths * surface.get_width();
}

Wallpaper::Wallpaper(const string &name, double price, double length_, double width_) : Material(name, price), length(length_), width(width_) {}
void Wallpaper::print() const {
  Material::print();
  cout << "For the wallpaper" << endl
       << "Length of roll: " << length << endl
       << "Width of roll" << width << endl;
}

double Wallpaper::units_needed(const Surface &surface) const {
  int lengths = surface.get_length() / width;
  double remainder = surface.get_length() - lengths * width;
  if (remainder >= limit)
    ++lengths;

  int rolls;
  int roll_lengths = length / surface.get_width();
  if (roll_lengths > 0) {
    rolls = lengths / roll_lengths;
    remainder = lengths - rolls * roll_lengths;
    if (remainder >= limit)
      rolls++;
  } else {
    double total = lengths * surface.get_width();
    rolls = total / length;
    if ((total - rolls * length) >= limit)
      rolls++;
  }
  return rolls;
}

Paint::Paint(const string &name, double price, int coating_, double liters_per_m2_) : Material(name, price), coating(coating_), liters_per_m2(liters_per_m2_) {}
void Paint::print() const {
  Material::print();
  cout << "For paint" << endl
       << "Number of coatings: " << coating << endl
       << "Liters per m^2: " << liters_per_m2 << endl;
}
double Paint::units_needed(const Surface &surface) const {
  double liters = surface.get_area() * coating / liters_per_m2;
  int liters_int = liters;
  double remainder = liters - liters_int;
  if (remainder >= 0.5 + limit)
    return liters_int + 1.0;
  else if (remainder >= limit)
    return liters_int + 0.5;
  else
    return liters_int;
}
