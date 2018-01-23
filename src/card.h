// Lost Cities GenAlg
//
// Author: Adam Berkan
//
// A Card is an object with one of 5 Colors, and a Rank.  Rank is either in
// the range [2, 10] or is a doubler, which is represented as rank == 0.
//
#ifndef CARD_H
#define CARD_H

#include <algorithm>
#include <array>
#include <cassert>
#include <string>

#include "absl/strings/string_view.h"

namespace lostcities {

class Card {
public:
  enum Color { RED, GREEN, BLUE, YELLOW, WHITE };

  static const int kNumColors = 5;

  static const std::array<Color, kNumColors> Colors;

  static const std::array<int, 12> Ranks;

  Card(Color c, int r) : color_(c), rank_(r) {
    assert(std::find(Ranks.begin(), Ranks.end(), r) != Ranks.end());
  }

  Card(const Card &) = default;

  bool operator==(const Card &rhs) const {
    return color_ == rhs.color_ && rank_ == rhs.rank_;
  }

  bool operator<(const Card &rhs) const {
    return color_ != rhs.color_ ? color_ < rhs.color_ : rank_ < rhs.rank_;
  }

  bool IsDoubler() const { return rank_ == 0; }

  std::string debug_string();

  Color color() const { return color_; }
  int rank() const { return rank_; }

  static absl::string_view ColorName(Color c);
  absl::string_view ColorName() { return Card::ColorName(color_); }

private:
  Color color_;
  int rank_;
};

} // end namespace
#endif // CARD_H
