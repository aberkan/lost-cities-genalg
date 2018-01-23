// tableau.h
// Lost Cities GenAlg
//
// Author: Adam Berkan
//
// The tableau represents each players played cards.  In each color they can
// only play cards that are larger than the last played card.
//
// A tableau's score is determined by summing the score for each color.  If
// no cards are played in a color, it is 0.  Otherwise the base score is the
// sum of all ranks played in the color, -20.  The base score is multiplied by
// 1 + # of doublers.  Finally, if 8 or more cards are played in a color, a
// +20 bonus is applied.
//
#ifndef TABLEAU_H
#define TABLEAU_H

#include <vector>

#include "card.h"

namespace lostcities {

class Tableau {
public:
  Tableau();

  void Play(Card c);

  bool IsPlayable(Card c) const;

  int Score() const;

  const std::vector<Card> &Set(Card::Color c) const { return sets_[c]; }

  std::string debug_string() const;

private:
  std::array<std::vector<Card>, Card::kNumColors> sets_;
};

} // end namespace

#endif // TABLEAU_H
