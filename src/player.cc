// player.cc
//
// Lost Cities GenAlg
//
// Author: Adam Berkan
//
#include "player.h"

namespace lostcities {

void Player::DoPlayMove(PlayMove playmove, DiscardPiles discard_piles) {
  assert(hand_.Contains(playmove.card_));
  hand_.Remove(playmove.card_);
  if (playmove.type_ == PlayMove::TABLEAU) {
    assert(tableau_.IsPlayable(playmove.card_));
    tableau_.Play(playmove.card_);
  } else {
    assert(playmove.type_ == PlayMove::DISCARD);
    discard_piles[playmove.pile_number_].Push(playmove.card_);
  }
}
} // end namespace
