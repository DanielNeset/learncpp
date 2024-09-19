#include "materiale.hpp"

Material::Material(const string &name_, double price_) : name(name_), price(price_) {}

void Material::print() const {
  cout << endl
       << "Name: " << name << endl
       << "Price: " << price << endl;
}

Covering::Covering(const string &name_, double price_, double width_) : Material(name_, price_), width(width_) {}

void Covering::print() const {
  Material::print();
  cout << "For covering: " << endl
       << "Width: " << width << endl;
}
