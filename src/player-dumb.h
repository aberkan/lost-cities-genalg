// player-dumb.h
//
// Lost Cities GenAlg
//
// Author: Adam Berkan
//
// PlayerDumb is a concrete player that plays a pretty dumb game.  It always
// looks at its first card, and either plays it if legal, or discards it.  It
// always draws from the draw pile.
//
// This is obviously a simple algorithm, but because of the sort order it
// actually only plays semi-horribly.  It usually ends up with a slightly
// negative score, but occastionally gets into the +20s.  (It also occasionally
// does very poorly).  The algorithm is easy to counter.
//
#ifndef PLAYER_DUMB_H
#define PLAYER_DUMB_H

#include "card.h"
#include "deck.h"
#include "hand.h"
#include "pile.h"
#include "player.h"
#include "tableau.h"

namespace lostcities {

class PlayerDumb : public Player {
public:
  PlayerDumb(Deck *deck) : Player(deck) {}
  virtual ~PlayerDumb(){};

  virtual PlayMove PlayCard(const Tableau *other_tab,
                            const DiscardPiles &discard_piles);

  virtual DrawMove DrawCard(const Tableau *other_tab,
                            const DiscardPiles &discard_piles);
};

} // end namespace
#endif // PLAYER_DUMB_H
