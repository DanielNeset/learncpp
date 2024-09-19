#pragma once

#include <string>

using namespace std;

const double sale_tax = 0.25;

class Commodity {
public:
  Commodity(const string &name_, int id_, double price_);

  const string &get_name() const;
  int get_id() const;
  double get_price() const;
  double get_price(double quantity) const;
  double get_price_with_sale_tax(double quantity) const;
  void set_price(double new_price);

private:
  string name;
  int id;
  double price;
};
