#include "material.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<unique_ptr<Material>> materials;
  materials.emplace_back(new Covering("Super Duper Dux", 433.50, 4));
  materials.emplace_back(new Wallpaper("Soldogg", 200, 12, 0.6));
  materials.emplace_back(new Paint("Extra", 125, 2, 12));

  cout << "Paint stored in the Material vector:" << endl;
  for (auto &material : materials) {
    if (dynamic_cast<Paint *>(material.get()))
      material->print();
  }

  int coatings_total = 0;
  for (auto &material : materials) {
    if (auto paint = dynamic_cast<Paint *>(material.get()))
      coatings_total += paint->get_coating();
  }
  cout << "Coatings: " << coatings_total << endl;
}
