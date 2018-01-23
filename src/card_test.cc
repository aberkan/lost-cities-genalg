// card_test.cc
// Lost Cities GenAlg
//
// Author: Adam Berkan
//
#include "card.h"
#include <iostream>

int main() {
  using Color = lostcities::Card::Color;
  lostcities::Card c(Color::WHITE, 3);
  lostcities::Card x(Color::GREEN, 5);
  lostcities::Card w(Color::YELLOW, 0);
  lostcities::Card f(Color::RED, 10);

  std::cout << c.debug_string();
  return 0;
}
