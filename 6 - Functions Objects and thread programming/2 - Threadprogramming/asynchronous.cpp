#include <boost/asio.hpp>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

class Workers {
public:
  // Provide asynchronous service
  boost::asio::io_service service;

private:
  boost::asio::io_service::work work;
  vector<thread> threads;

public:
  Workers(size_t number_of_threads) : work(service) {
    for (size_t i = 0; i < number_of_threads; ++i) {
      threads.emplace_back([this] {
        service.run();
      });
    }
  }
  void stop() {
    service.stop();
    for (auto &thread : threads) {
      thread.join();
    }
  }
};

int main() {
  Workers workers(4);

  cout << "Press enter to exit" << endl;

  workers.service.post([&workers] {
    cout << "Task A is being performed by a worker." << endl;

    workers.service.post([] {
      cout << "Task B is begin performed by a worker." << endl;
    });
  });
  workers.service.post([] {
    cout << "Task C is begin performed by a worker." << endl;
  });

  string line;
  getline(cin, line);
  workers.stop();
}
