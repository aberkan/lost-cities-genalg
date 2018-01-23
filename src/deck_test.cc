// deck_test.cc
// Lost Cities GenAlg
//
// Author: Adam Berkan
//
#include "deck.h"
#include <iostream>

int main() {
  lostcities::Deck d;
  std::cout << d.debug_string() << std::endl;
  assert(d.size() == 60);
  d.Shuffle();
  assert(d.size() == 60);
  lostcities::Card c = d.Pop();
  assert(d.size() == 59);
  std::cout << d.debug_string() << std::endl;
  std::cout << c.debug_string() << std::endl;

  return 0;
}
