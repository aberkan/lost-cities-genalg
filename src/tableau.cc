// tableau.cc
// Lost Cities GenAlg
//
// Author: Adam Berkan
//
#include <algorithm>
#include <cassert>

#include "tableau.h"

#include "card.h"

#include "absl/strings/str_join.h"

namespace lostcities {

Tableau::Tableau() : sets_() {}

bool Tableau::IsPlayable(Card c) const {
  if (sets_[c.color()].size() == 0) {
    return true;
  }
  return sets_[c.color()].back().rank() <= c.rank();
}

void Tableau::Play(Card c) {
  assert(IsPlayable(c));
  sets_[c.color()].push_back(c);
}

std::string Tableau::debug_string() const {
  std::string ret = "(";
  for (Card::Color col : Card::Colors) {
    ret.append(absl::StrCat("[", Card::ColorName(col), ":"));
    for (const Card &c : Set(col)) {
      ret.append(absl::StrCat(" ", c.rank()));
    }
    ret.append("]");
  }
  return ret;
}

int Tableau::Score() const {
  int ret = 0;
  for (auto s : sets_) {
    if (s.size() == 0) {
      continue;
    }
    int mult = 1;
    int points = -20; // You lose 20 points for starting a color
    for (auto card : s) {
      if (card.IsDoubler()) {
        mult++; // Each doubler gives you +1 multiplier
        continue;
      }
      points += card.rank();
    }
    ret += mult * points;
    if (s.size() >= 8) {
      ret += 20;
    }
  }
  return ret;
}

} // end namespace
