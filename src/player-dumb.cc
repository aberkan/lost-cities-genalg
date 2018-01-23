// player-dumb.cc
//
// Lost Cities GenAlg
//
// Author: Adam Berkan
//
#include "player-dumb.h"

namespace lostcities {

void PlayerDumb::PlayCard(const Tableau *other_tab,
                          DiscardPiles discard_piles) {
  // Dumb Player always plays his first card if possible, otherwise discards
  // it to the first pile.
  hand().Sort();

  Card card = hand().RemoveAt(0);

  if (tableau().IsPlayable(card)) {
    tableau().Play(card);
  } else {
    discard_piles[0].Push(card);
  }
}

void PlayerDumb::DrawCard(Deck *deck, const Tableau *other_tab,
                          DiscardPiles discard_piles) {
  // Dumb Player always draw from the deck
  hand().Add(deck->Pop());
}

} // end namespace
