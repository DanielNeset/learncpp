#include <iostream>
#include <memory>
#include <string>
#include <thread>

using namespace std;

void f() {
  // shared_ptr<string> message(new string("Some message"));
  auto message = make_shared<string>("Some message");

  thread aThread([message] {
    cout << "Message from aThread: " << *message << endl;
  });
  // The thread will execute independently from the rest of the program
  // Even when the thread object aThread goes out of scope.
  aThread.detach();
}

int main() {
  f();

  cout << "From main thread" << endl;

  // Wait 50ms before returning from main().
  this_thread::sleep_for(50ms);
}
