#include "covering.hpp"
#include "surface.hpp"
#include <iostream>
#include <string>

using namespace std;
int main() {
  Surface surface("Berits golv", 5, 6);
  Covering covering("Vegg-til-vegg teppe", 243.50, 5);
  double meters = covering.get_meters(surface);
  double price = covering.get_price(surface);
  cout << "Du trenger " << meters << " meter, pris kr. " << price << endl;
}
