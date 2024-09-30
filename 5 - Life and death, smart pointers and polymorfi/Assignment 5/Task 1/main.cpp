#include "chessboard.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

int main() {
  ChessBoard board;

  board.place_piece(4, 0, make_unique<ChessBoard::King>(ChessBoard::Color::WHITE));
}
