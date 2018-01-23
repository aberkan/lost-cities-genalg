// deck.cc
// Lost Cities GenAlg
//
// Author: Adam Berkan
//
#include <algorithm>
#include <random>

#include "deck.h"

namespace lostcities {

std::random_device rd;
std::mt19937 mt(rd());

Deck::Deck() : cards_() {
  using Color = Card::Color;
  for (Color c : Card::Colors) {
    for (int r : Card::Ranks) {
      cards_.emplace_back(c, r);
    }
  }
}

void Deck::Shuffle() { std::shuffle(cards_.begin(), cards_.end(), mt); }

Card Deck::Pop() {
  if (cards_.empty()) {
    throw EmptyDeck();
  }
  Card ret = cards_.back();
  cards_.pop_back();
  return ret;
}

std::string Deck::debug_string() {
  std::string ret = "{";
  for (auto c : cards_) {
    ret.append(c.debug_string());
  }
  ret.append("}");
  return ret;
}

} // end namespace
