#include "material.hpp"
#include <iostream>
#include <string>

using namespace std;

Material::Material(const string &name_, double price_) : name(name_), price(price_) {}

void Material::print() const {
  cout << "Name: " << name << endl
       << "Price: " << price << endl;
}

Covering::Covering(const string &name, double price, double width_) : Material(name, price), width(width_) {}

void Covering::print() const {
  Material::print();
  cout << "For coverage: " << endl
       << "Width: " << width << endl;
}

Wallpaper::Wallpaper(const string &name, double price, double length_, double width_) : Material(name, price), length(length_), width(width_) {}
void Wallpaper::print() const {
  Material::print();
  cout << "For the wallpaper" << endl
       << "Length of roll: " << length << endl
       << "Width of roll" << width << endl;
}

Paint::Paint(const string &name, double price, int coating_, double liters_per_m2_) : Material(name, price), coating(coating_), liters_per_m2(liters_per_m2_) {}
void Paint::print() const {
  Material::print();
  cout << "For paint" << endl
       << "Number of coatings: " << coating << endl
       << "Liters per m^2: " << liters_per_m2 << endl;
}
