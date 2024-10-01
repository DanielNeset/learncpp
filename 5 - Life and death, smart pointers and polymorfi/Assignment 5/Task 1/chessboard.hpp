#pragma once
#include <memory>
#include <string>
#include <vector>

using namespace std;

class ChessBoard {
public:
  enum class Color { WHITE,
                     BLACK };

  class Piece {
  public:
    Piece(Color color_);
    string color_string() const;
    Color get_Color() const { return color; }

    virtual ~Piece();
    virtual string type() const = 0;
    virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;

  protected:
    Color color;
  };

  class King : public Piece {
  public:
    King(Color color);

    string type() const override;
    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override;
  };

  class Knight : public Piece {
  public:
    Knight(Color color);

    string type() const override;
    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override;
  };

  ChessBoard();

  bool move_piece(const string &from, const string &to);

  void place_piece(int x, int y, unique_ptr<Piece> piece);

  const Piece *get_piece(int x, int y) const;

private:
  vector<vector<unique_ptr<Piece>>> squares;
};
