// tableau_test.cc
// Lost Cities GenAlg
//
// Author: Adam Berkan
//
#include <iostream>

#include "tableau.h"

#include "card.h"

int main() {
  using Tableau = lostcities::Tableau;
  using Card = lostcities::Card;
  Tableau tab;

  assert(tab.IsPlayable(Card(Card::RED, 0)));

  assert(tab.Score() == 0);

  tab.Play(Card(Card::RED, 0));

  assert(tab.Score() == -40);

  tab.Play(Card(Card::RED, 10));

  assert(tab.Score() == -20);

  assert(!tab.IsPlayable(Card(Card::RED, 9)));

  assert(tab.IsPlayable(Card(Card::WHITE, 0)));

  return 0;
}
