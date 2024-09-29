#include "material.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
  Covering covering("Super Duper Dux", 433.50, 4);
  Wallpaper wallpaper("Soldogg", 200, 12, 0.6);
  Paint paint("Extra", 125, 2, 12.0);

  vector<Material *> materials;
  materials.emplace_back(&covering);
  materials.emplace_back(&wallpaper);
  materials.emplace_back(&paint);

  for (auto &material : materials) {
    material->print();
    cout << endl;
  }
}
