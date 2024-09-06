#include <fstream>
#include <iostream>

using namespace std;

void read_temperatures(double temperatures[], int length);

int main() {
  const int length = 5;

  double temperatures[length];

  read_temperatures(temperatures, length);

  int under10 = 0;
  int between10and20 = 0;
  int above20 = 0;

  for (int i = 0; i < length; i++) {
    if (temperatures[i] < 10) {
      under10++;
    } else if (temperatures[i] > 20) {
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

void read_temperatures(double temperatures[], int length) {
  const char filename[] = "temperaturer.dat";
  ifstream file;
  file.open(filename);

  if (!file) {
    cout << "Feil ved åpningen av innfil." << endl;
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < length; i++) {
    file >> temperatures[i];
  }

  file.close();
}
