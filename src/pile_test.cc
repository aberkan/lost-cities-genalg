// pile_test.cc
// Lost Cities GenAlg
//
// Author: Adam Berkan
//
#include <iostream>

#include "pile.h"

#include "card.h"

int main() {
  using Pile = lostcities::Pile;
  using Card = lostcities::Card;
  Pile p;

  const Card red_0(Card::RED, 0);

  assert(p.size() == 0);
  p.Push(red_0);
  assert(p.size() == 1);
  Card c = p.Pop();
  assert(p.size() == 0);

  assert(c == red_0);

  lostcities::DiscardPiles discard_piles;

  discard_piles[0].Push(red_0);
  discard_piles[0].Pop();

  return 0;
}
