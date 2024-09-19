#include "materiale.hpp"
#include <iostream>

using namespace std;

int main() {
  Covering covering("Super Duper Dux", 433.50, 4);

  cout << "Name: " << covering.get_name() << ", Price: "
       << covering.get_price() << endl;

  covering.print();

  return 0;
}
