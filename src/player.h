// player.h
//
// Lost Cities GenAlg
//
// Author: Adam Berkan
//
// Player is an abstract base class for Human and AI players
//
#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include "deck.h"
#include "hand.h"
#include "pile.h"
#include "tableau.h"

namespace lostcities {

class Player {
public:
  Player(Deck *deck) : hand_(deck), tab_() {}
  virtual ~Player(){};

  // Makes the player play a card from its hand either to its tableau,
  // or to a discard pile.
  // TODO: Instead of having the player actually play the card, have it
  // return its choice, and have the game logic exectute the move.
  virtual void PlayCard(const Tableau *other_tab,
                        DiscardPiles discard_piles) = 0;

  // Makes the player either draw a card from the deck, or from a
  // discard pile.
  // TODO: Instead of having the player actually draw a card, have it
  // return its choice, and have the game logic exectute the move.
  virtual void DrawCard(Deck *deck, const Tableau *other_tab,
                        DiscardPiles discard_piles) = 0;

  int Score() const { return tab_.Score(); }

  const Tableau &tableau_view() const { return tab_; }

protected:
  Hand &hand() { return hand_; }
  const Hand &hand() const { return hand_; }
  Tableau &tableau() { return tab_; }
  const Tableau &tableau() const { return tab_; }

private:
  Hand hand_;
  Tableau tab_;
};

} // end namespace
#endif // PLAYER_H
