#include <boost/asio.hpp>
#include <iostream>

using namespace std;
using namespace boost::asio::ip;

class EchoServer {
private:
  class Connection {
  public:
    tcp::socket socket;
    Connection(boost::asio::io_service &io_service) : socket(io_service) {}
  };
  boost::asio::io_service io_service;

  tcp::endpoint endpoint;
  tcp::acceptor acceptor;

  void handle_request(shared_ptr<Connection> connection) {
    auto read_buffer = make_shared<boost::asio::streambuf>();

    async_read_until(connection->socket, *read_buffer, "r\n", [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
      if (!ec) {
        istream read_stream(read_buffer.get());
        std::string message;
        getline(read_stream, message);
        // Remove "\r" at the end of the message
        message.pop_back();

        if (message == "exit") {
          return;
        }

        cout << "Message from a connected client: " << message << endl;

        auto write_buffer = make_shared<boost::asio::streambuf>();
        ostream write_stream(write_buffer.get());

        write_stream << message << "\r\n";

        async_write(connection->socket, *write_buffer, [this, connection, write_buffer](const boost::system::error_code &ec, size_t) {
          if (!ec) {
            handle_request(connection);
          }
        });
      }
    });
  }

  void accept() {
    auto connection = make_shared<Connection>(io_service);

    acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
      if (!ec) {
        handle_request(connection);
      }
    });
  }

public:
  EchoServer() : endpoint(tcp::v4(), 8080), acceptor(io_service, endpoint) {}

  void start() {
    accept();

    io_service.run();
  }
};

int main() {
  EchoServer echoServer;

  cout << "Starting echo server" << endl
       << "Connect in a terminal with: telnet localhost 8080. Type 'exit' to end the connection." << endl;

  echoServer.start();
}
