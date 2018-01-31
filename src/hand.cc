// hand.cc
// Lost Cities GenAlg
//
// Author: Adam Berkan
//
#include <algorithm>
#include <cassert>

#include "hand.h"

namespace lostcities {

Hand::Hand(Deck *d) : cards_() {
  for (int i = 0; i < kHandSize; ++i) {
    cards_.push_back(d->Pop());
  }
}

void Hand::Add(Card c) { cards_.push_back(c); }

Card Hand::At(int i) const {
  if (i < 0 || i > size()) {
    throw OutOfHandIndex();
  }
  return cards_[i];
}

Card Hand::RemoveAt(int i) {
  if (i < 0 || i > size()) {
    throw OutOfHandIndex();
  }
  Card ret = cards_[i];
  cards_.erase(cards_.begin() + i);
  return ret;
}

void Hand::Remove(Card c) {
  auto it = std::remove(cards_.begin(), cards_.end(), c);
  assert(it != cards_.end());
  cards_.erase(it, cards_.end());
}
void Hand::Sort() { std::sort(cards_.begin(), cards_.end()); }

std::string Hand::debug_string() const {
  std::string ret = "{";
  for (Card c : cards_) {
    ret.append(c.debug_string());
  }
  ret.append("}");
  return ret;
}
} // end namespace
