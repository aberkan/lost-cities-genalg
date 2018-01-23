// game-state.h
//
// Lost Cities GenAlg
//
// Author: Adam Berkan
//
// This contains the state for the game:
// 1 deck, 2 players, and the discard piles.
//
// The constructor creates the objects including the players.  Today the
// players are always chosen as dumb players, but that will improve.
//
// The Run method plays the players against each other until the game is done.
//
#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <memory>

#include "card.h"
#include "deck.h"
#include "hand.h"
#include "pile.h"
#include "player-console.h"
#include "player-dumb.h"
#include "player.h"
#include "tableau.h"

namespace lostcities {

class GameState {
public:
  GameState() {
    deck_.Shuffle();
    players_[0] = std::make_unique<PlayerConsole>(&deck_);
    players_[1] = std::make_unique<PlayerDumb>(&deck_);
  }

  // Returns winning player 1 or 2, or -1 if tied.
  int RunGame();

private:
  Deck deck_;
  std::unique_ptr<Player> players_[2];
  DiscardPiles discard_piles_;
};

} // end namespace

#endif // GAME_STATE_H
