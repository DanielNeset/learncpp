#include "covering.hpp"
#include "surface.hpp"
#include <string>

using namespace std;

Covering::Covering(string name_, double price_, double width_) : name(name_), price(price_), width(width_) {}

double Covering::get_meters(const Surface &surface) const {
  double surface_length = surface.get_length();
  double surface_width = surface.get_width();

  int lengths = surface_length / width;
  double remainder = surface_length - lengths * width;
  if (remainder >= limit)
    lengths++;
  return lengths * surface_width;
}

double Covering::get_price(const Surface &surface) const {
  return get_meters(surface) * price;
}
