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

/// King Implementation --------------------------------
ChessBoard::King::King(Color color) : Piece(color) {}
// ChessBoard::King::~King() {}
string ChessBoard::King::type() const {
  return color_string() + " King";
}

bool ChessBoard::King::valid_move(int from_x, int from_y, int to_x, int to_y) const {
  // A king can move one square in any direction
  int dx = abs(to_x - from_x);
  int dy = abs(to_y - from_y);
  return (dx <= 1 && dy <= 1);
}

char ChessBoard::King::symbol() const {
  return (color == Color::WHITE) ? 'K' : 'k';
}

/// Knight Implementation --------------------------------
ChessBoard::Knight::Knight(Color color) : Piece(color) {}
// ChessBoard::King::~King() {}
string ChessBoard::Knight::type() const {
  return color_string() + " Knight";
}

bool ChessBoard::Knight::valid_move(int from_x, int from_y, int to_x, int to_y) const {
  int dx = abs(from_x - to_x);
  int dy = abs(from_y - to_y);
  return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}

char ChessBoard::Knight::symbol() const {
  return (color == Color::WHITE) ? 'N' : 'n';
}

/// Chessboard Implementation --------------------------------

ChessBoard::ChessBoard() {
  squares.resize(8);
  for (auto &square_column : squares) {
    square_column.resize(8);
  }
}

void ChessBoard::place_piece(int x, int y, unique_ptr<Piece> piece) {
  squares[x][y] = std::move(piece);
}

const ChessBoard::Piece *ChessBoard::get_piece(int x, int y) const {
  return squares[x][y].get();
}

bool ChessBoard::move_piece(const std::string &from, const std::string &to) {
  int from_x = from[0] - 'a';
  int from_y = stoi(string() + from[1]) - 1;
  int to_x = to[0] - 'a';
  int to_y = stoi(string() + to[1]) - 1;

  auto &piece_from = squares[from_x][from_y];
  if (piece_from) {
    if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
      cout << piece_from->type() << " is moving from " << from << " to " << to << endl;
      auto &piece_to = squares[to_x][to_y];
      if (piece_to) {
        if (piece_from->color_string() != piece_to->color_string()) {
          cout << piece_to->type() << " is being removed from " << to << endl;
          if (auto king = dynamic_cast<King *>(piece_to.get())) {
            cout << king->color_string() << " lost the game" << endl;
          }
        } else {
          cout << "Cannot move " << piece_from->type() << " from " << from << " to " << to << endl;
          return false;
        }
      }
      piece_to = std::move(piece_from);
      return true;
    } else {
      cout << "Cannot move " << piece_from->type() << " from " << from << " to " << to << endl;
      return false;
    }
  } else {
    cout << "No piece at " << from << endl;
    return false;
  }
}

void ChessBoard::print_board() const {
  cout << "  a b c d e f g h\n";
  for (int i = 7; i >= 0; --i) {
    cout << i + 1 << " ";
    for (int j = 0; j < 8; ++j) {
      if (squares[j][i]) {
        cout << squares[j][i]->symbol() << " ";
      } else {
        cout << ". ";
      }
    }
    cout << i + 1 << endl;
  }
  cout << "  a b c d e f g h\n";
}
