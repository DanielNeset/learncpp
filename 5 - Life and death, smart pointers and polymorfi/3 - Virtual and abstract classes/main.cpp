#include "material.hpp"
#include "surface.hpp"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

int main() {
  vector<unique_ptr<Material>> materials;
  materials.emplace_back(new Covering("Ull-Gull", 450, 5));
  materials.emplace_back(new Wallpaper("Brokade", 500, 12, 0.6));
  materials.emplace_back(new Paint("Heimdal XX-Supre", 200, 2, 10));

  Surface surface("wall", 4, 5);

  for (auto &material : materials) {
    cout << material->get_name() << ": "
         << " Need: " << material->units_needed(surface)
         << " amount, price: " << material->price_total(surface) << std::endl;
  }

  return 0;
}
