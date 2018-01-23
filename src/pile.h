// pile.h
// Lost Cities GenAlg
//
// Author: Adam Berkan
//
// A pile is just a simplified stack of Cards.
//
#ifndef PILE_H
#define PILE_H

#include <vector>

#include "card.h"

namespace lostcities {

class Pile {
public:
  Pile();

  void Push(Card c) { cards_.push_back(c); }

  Card Pop();

  int size() const { return cards_.size(); }

  std::string debug_string() const;

private:
  std::vector<Card> cards_;
};

const int kNumDiscardPiles = 5;

using DiscardPiles = Pile[kNumDiscardPiles];

} // end namespace

#endif // PILE_H
