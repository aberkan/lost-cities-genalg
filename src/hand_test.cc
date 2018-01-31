// hand_test.cc
// Lost Cities GenAlg
//
// Author: Adam Berkan
//
#include <iostream>

#include "hand.h"

#include "card.h"
#include "deck.h"

int main() {
  lostcities::Deck d;
  using Hand = lostcities::Hand;
  Hand h(&d);

  assert(h.size() == Hand::kHandSize);

  auto c1 = h.At(3);
  assert(h.size() == Hand::kHandSize);
  auto c2 = h.RemoveAt(3);

  assert(c1 == c2);
  assert(h.size() == Hand::kHandSize - 1);

  lostcities::Card c = h.At(2);

  h.Remove(c);

  assert(h.size() == Hand::kHandSize - 2);

  return 0;
}
