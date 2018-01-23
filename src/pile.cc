// pile.cc
// Lost Cities GenAlg
//
// Author: Adam Berkan
//
#include <algorithm>
#include <cassert>

#include "pile.h"

#include "card.h"

namespace lostcities {

Pile::Pile() : cards_() {}

Card Pile::Pop() {
  Card c = cards_.back();
  cards_.pop_back();
  return c;
}

std::string Pile::debug_string() const {
  std::string ret = "{";
  for (Card c : cards_) {
    ret.append(c.debug_string());
  }
  return ret.append("}");
}

} // end namespace
