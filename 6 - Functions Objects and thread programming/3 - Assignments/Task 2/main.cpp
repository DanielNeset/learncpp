#include <boost/asio.hpp>
#include <iostream>
#include <memory>

using namespace std;
using namespace boost::asio::ip;

class WebServer {
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

    // Read from client until newline "\r\n"
    async_read_until(connection->socket, *read_buffer, "\r\n",
                     [connection, read_buffer](const boost::system::error_code &ec, size_t) {
                       // If there's no error:
                       if (!ec) {
                         // Retrieve the request message from the client:
                         istream read_stream(read_buffer.get());
                         std::string request_line;
                         getline(read_stream, request_line);
                         request_line.pop_back(); // Remove "\r" at the end of the message

                         cout << "Request: " << request_line << endl;

                         // Parse the request to get the method and path (e.g., "GET / HTTP/1.1")
                         string method, path, http_version;
                         istringstream request_stream(request_line);
                         request_stream >> method >> path >> http_version;

                         auto write_buffer = make_shared<boost::asio::streambuf>();
                         ostream write_stream(write_buffer.get());

                         string response_body;

                         if (method == "GET") {
                           // Handle different paths
                           if (path == "/") {
                             response_body = "Dette er hovedsiden\r\n";
                           } else if (path == "/en_side") {
                             response_body = "Dette er en side\r\n";
                           } else {
                             response_body = "404 Not Found\r\n";
                           }

                           write_stream << "HTTP/1.1 200 OK\r\n";
                           write_stream << "Content-Type: text/plain\r\n";
                           write_stream << "Content-Length: " << response_body.size() << "\r\n";
                           write_stream << "Connection: close\r\n\r\n";
                           write_stream << response_body;
                         } else {
                           // Method not allowed
                           response_body = "405 Method Not Allowed\r\n";
                           write_stream << "HTTP/1.1 405 Method Not Allowed\r\n";
                           write_stream << "Content-Length: " << response_body.size() << "\r\n";
                           write_stream << "Content-Type: text/plain\r\n";
                           write_stream << "Connection: close\r\n\r\n";
                           write_stream << response_body;
                         }

                         // Write the response to the client
                         async_write(connection->socket, *write_buffer,
                                     [connection, write_buffer](const boost::system::error_code &ec, size_t) {
                                       if (!ec) {
                                         // Close the connection after response
                                         connection->socket.close();
                                       }
                                     });
                       }
                     });
  }

  void accept() {
    auto connection = make_shared<Connection>(io_service);

    // Accept a new client connection
    acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
      accept(); // Continue accepting new connections

      if (!ec) {
        handle_request(connection);
      }
    });
  }

public:
  WebServer() : endpoint(tcp::v4(), 8080), acceptor(io_service, endpoint) {}

  void start() {
    accept();
    io_service.run();
  }
};

int main() {
  WebServer web_server;

  cout << "Starting web server" << endl
       << "Visit http://localhost:8080 or http://localhost:8080/en_side in a browser" << endl;

  web_server.start();
}
