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

// PlayMove describes a player move.  It names the card, and whether to play
// it to a tableau, or which discard pile.
struct PlayMove {
  enum Type { DISCARD, TABLEAU };

  Type type_;
  Card card_;
  int pile_number_; // unused if type_ == TABLEAU
};

inline PlayMove TableauMove(Card c) { return {PlayMove::TABLEAU, c, 0}; }
inline PlayMove DiscardMove(Card c, int pile_idx) {
  return {PlayMove::DISCARD, c, pile_idx};
}

// DrawMove describes a player draw.  Either they draw from the pile, or select
// a discard pile.
struct DrawMove {
  enum Type { DISCARD, DECK };

  Type type_;
  int pile_number_; // unused if type_ == DECK
};

inline DrawMove DeckDraw() { return {DrawMove::DECK, 0}; }
inline DrawMove DiscardDraw(int pile_idx) {
  return {DrawMove::DISCARD, pile_idx};
}

// This is the parent class of all players.  The game calls PlayCard and
// DrawCard to get moves from the AI.  It calls DoPlayMove and AddCard with
// the results of actions.  Only the parent Player class can actually modify
// the hand and tableau.  Sub-classes can not modify their parent state
// directly.
class Player {
public:
  Player(Deck *deck) : hand_(deck), tableau_() { hand_.Sort(); }
  virtual ~Player(){};

  // Asks the player to choose to play a card from its hand either to its
  // tableau or to a discard pile.
  virtual PlayMove PlayCard(const Tableau *other_tab,
                            const DiscardPiles &discard_piles) = 0;

  // Asks the player to choose either to draw a card from the deck, or from a
  // discard pile.
  virtual DrawMove DrawCard(const Tableau *other_tab,
                            const DiscardPiles &discard_piles) = 0;

  int Score() const { return tableau_.Score(); }

  const Tableau &tableau_view() const { return tableau_; }

  void DoPlayMove(PlayMove playmove, DiscardPiles discard_piles);

  void AddCard(Card c) {
    LearnDrawnCard(c);
    hand_.Add(c);
    hand_.Sort();
  }
  // This is virtual so Players can override it to find out what card they
  // drew.
  virtual void LearnDrawnCard(Card c) {}

protected:
  const Hand &hand() const { return hand_; }
  const Tableau &tableau() const { return tableau_; }

private:
  Hand hand_;
  Tableau tableau_;
};

} // end namespace
#endif // PLAYER_H
