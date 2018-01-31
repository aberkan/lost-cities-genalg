// deck.h
// Lost Cities GenAlg
//
// Author: Adam Berkan
//
// A deck is a stack of cards.  Initially in each of the 5 colors it contains
// 2-10 and 3 doublers.
//
#ifndef DECK_H
#define DECK_H

#include <string>
#include <vector>

#include "src/card.h"

namespace lostcities {

class Deck {
public:
  Deck();

  void Shuffle();

  Card Pop();

  int size() const { return cards_.size(); }

  std::string debug_string() const;

private:
  std::vector<Card> cards_;
};

class EmptyDeck {};

} // end namespace
#endif // DECK_H
