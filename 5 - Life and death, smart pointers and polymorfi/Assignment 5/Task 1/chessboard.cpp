#include "chessboard.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

// Piece class
ChessBoard::Piece::Piece(Color color_) : color(color_) {}
ChessBoard::Piece::~Piece() {}
string ChessBoard::Piece::color_string() const {
  if (color == Color::WHITE) {
    return "white";
  } else {
    return "black";
  }
}

ChessBoard::King::King(Color color) : Piece(color) {}
// ChessBoard::King::~King() {}
string ChessBoard::King::type() const {
  return color_string() + " King";
}

ChessBoard::ChessBoard() {
  squares.resize(8);
  for (auto &square_column : squares) {
    square_column.resize(8);
  }
}

void ChessBoard::place_piece(int x, int y, unique_ptr<Piece> piece) {
  squares[x][y] = std::move(piece);
}

bool ChessBoard::King::valid_move(int from_x, int from_y, int to_x, int to_y) const {
  // A king can move one square in any direction
  int dx = abs(to_x - from_x);
  int dy = abs(to_y - from_y);
  return (dx <= 1 && dy <= 1);
}
