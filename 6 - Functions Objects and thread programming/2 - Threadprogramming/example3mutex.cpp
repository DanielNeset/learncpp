#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

using namespace std;

int main() {
  string message;

  vector<thread> threads;
  for (int i = 0; i < 4; ++i) {
    threads.emplace_back([i, &message] {
      // We can declare the mutex as static if it is not needed elsewhere.
      // The message_mutex is locked upon construction of lock, and the mutex is unlocked when lock is destroyed at the end of scope,
      // including when an exception is thrown.
      static mutex message_mutex;
      lock_guard<mutex> lock(message_mutex);
      message += "Thread " + to_string(i) + " says hello \n";
    });
  }

  for (auto &thread : threads) {
    thread.join();
  }

  cout << message << endl;
}
