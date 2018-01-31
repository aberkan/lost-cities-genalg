// player-dumb.cc
//
// Lost Cities GenAlg
//
// Author: Adam Berkan
//
#include "player-dumb.h"

namespace lostcities {

PlayMove PlayerDumb::PlayCard(const Tableau *other_tab,
                              const DiscardPiles &discard_piles) {
  // Dumb Player always plays his first card if possible, otherwise discards
  // it to the first pile.
  Hand h = hand();
  h.Sort();

  Card card = h.At(0);

  if (tableau().IsPlayable(card)) {
    return TableauMove(card);
  } else {
    return DiscardMove(card, 0);
  }
}

DrawMove PlayerDumb::DrawCard(const Tableau *other_tab,
                              const DiscardPiles &discard_piles) {
  // Dumb Player always draw from the deck
  return DeckDraw();
}

} // end namespace
