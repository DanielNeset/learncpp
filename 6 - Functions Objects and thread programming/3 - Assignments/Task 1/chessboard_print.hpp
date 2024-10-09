#pragma once
#include "chessboard.hpp"

class ChessBoardPrint {
public:
  ChessBoardPrint(ChessBoard &board);
  void print_board() const;

private:
  ChessBoard &board;
};
