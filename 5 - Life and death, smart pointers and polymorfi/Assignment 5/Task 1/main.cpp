#include "chessboard.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

int main() {
  ChessBoard board;

  board.place_piece(4, 0, make_unique<ChessBoard::King>(ChessBoard::Color::WHITE));
  board.place_piece(1, 0, make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE));
  board.place_piece(6, 0, make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE));

  board.place_piece(4, 7, make_unique<ChessBoard::King>(ChessBoard::Color::BLACK));
  board.place_piece(1, 7, make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK));
  board.place_piece(6, 7, make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK));

  cout << "Invalid moves:" << endl;
  board.move_piece("e3", "e2");
  board.move_piece("e1", "e3");
  board.move_piece("b1", "b2");
  cout << endl;

  cout << "Board setup:" << endl;
  board.print_board();
  cout << endl;

  cout << "A simulated game:" << endl;
  board.move_piece("e1", "e2");
  board.move_piece("g8", "h6");
  board.move_piece("b1", "c3");
  board.move_piece("h6", "g8");
  board.move_piece("c3", "d5");
  board.move_piece("g8", "h6");
  board.move_piece("d5", "f6");
  board.move_piece("h6", "g8");
  board.move_piece("f6", "e8");
  cout << "Board setup:" << endl;
  board.print_board();
  cout << endl;
}
