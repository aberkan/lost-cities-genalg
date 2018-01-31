// player-console.h
//
// Lost Cities GenAlg
//
// Author: Adam Berkan
//
// PlayerConsole is a concrete player that asks the console for its moves.
//
#ifndef PLAYER_CONSOLE_H
#define PLAYER_CONSOLE_H

#include "card.h"
#include "deck.h"
#include "hand.h"
#include "pile.h"
#include "player.h"
#include "tableau.h"

namespace lostcities {

class PlayerConsole : public Player {
public:
  PlayerConsole(Deck *deck) : Player(deck) {}
  virtual ~PlayerConsole() {}

  virtual PlayMove PlayCard(const Tableau *other_tab,
                            const DiscardPiles &discard_piles);

  virtual DrawMove DrawCard(const Tableau *other_tab,
                            const DiscardPiles &discard_piles);

  virtual void LearnDrawnCard(Card c) override;

private:
  // Print out the current state of the game.
  void PrintState(const Tableau *other_tab,
                  const DiscardPiles discard_piles) const;
};

} // end namespace
#endif // PLAYER_CONSOLE_H
