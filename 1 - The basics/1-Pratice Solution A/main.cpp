#include <iostream>

using namespace std;

int main() {

  const int length = 5;

  int under10 = 0;
  int between10and20 = 0;
  int above20 = 0;

  double temperature;

  cout << "Du skal skrive inn " << length << " temperaturer." << endl;

  for (size_t i = 1; i <= length; i++) {

    cout << "Temperatur nr " << i << ": ";
    cin >> temperature;

    if (temperature < 10) {
      under10++;
    } else if (temperature > 20) {
      above20++;
    } else {
      between10and20++;
    }
  }

  cout << "Antall under 10 er " << under10 << endl;
  cout << "Antall mellom 10 og 20 er " << between10and20 << endl;
  cout << "Antall over 20 er " << above20 << endl;

  return 0;
}
