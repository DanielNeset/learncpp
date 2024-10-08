#include <iostream>
#include <thread>

using namespace std;

int main() {
  thread athread([] {
    cout << "From athread" << endl;
  });

  cout << "From main thread" << endl;

  // Waits for athread to finish
  athread.join();
}
