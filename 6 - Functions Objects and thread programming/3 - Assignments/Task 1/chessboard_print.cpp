#include "chessboard_print.hpp"
#include <iostream>

using namespace std;

ChessBoardPrint::ChessBoardPrint(ChessBoard &board) : board(board) {
  board.after_piece_move = [this]() { this->print_board(); };
}

void ChessBoardPrint::print_board() const {
  cout << "  a b c d e f g h\n";
  for (int i = 7; i >= 0; --i) {
    cout << i + 1 << " ";
    for (int j = 0; j < 8; ++j) {
      const ChessBoard::Piece *piece = board.get_piece(j, i);
      if (piece) {
        cout << piece->symbol() << " ";
      } else {
        cout << ". ";
      }
    }
    cout << i + 1 << endl;
  }
  cout << "  a b c d e f g h\n"
       << endl;
  ;
}
