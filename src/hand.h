// hand.h
// Lost Cities GenAlg
//
// Author: Adam Berkan
//
#ifndef HAND_H
#define HAND_H

#include <string>
#include <vector>

#include "card.h"
#include "deck.h"

namespace lostcities {

class Hand {
public:
  static const int kHandSize = 8;

  Hand(Deck *d);

  int size() const { return cards_.size(); }

  void Sort();

  Card At(int rank) const;
  Card RemoveAt(int rank);

  void Add(Card c);

  std::string debug_string() const;

private:
  std::vector<Card> cards_;
};

class OutOfHandIndex {};

} // end namespace
#endif // HAND_H
