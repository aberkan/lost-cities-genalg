// game-state.cc
//
// Lost Cities GenAlg
//
// Author: Adam Berkan
//
#include <iostream>
#include <memory>

#include "game-state.h"

namespace lostcities {

int GameState::RunGame() {
  int current_player = 0;
  while (deck_.size() > 0) {
    int other_player = (current_player + 1) % 2;
    std::cout << "=============== Player " << current_player + 1
              << "===============\n";
    players_[current_player]->PlayCard(&players_[other_player]->tableau_view(),
                                       discard_piles_);
    players_[current_player]->DrawCard(
        &deck_, &players_[other_player]->tableau_view(), discard_piles_);

    current_player = other_player;
  }
  int score1 = players_[0]->Score();
  int score2 = players_[1]->Score();
  std::cout << "Player 1 score " << score1 << " : "
            << players_[0]->tableau_view().debug_string() << std::endl;
  std::cout << "Player 2 score " << score2 << " : "
            << players_[1]->tableau_view().debug_string() << std::endl;

  // returns 1 or 2 for winning player, or -1 if tied.
  return (score1 > score2) ? 1 : (score2 > score1) ? 2 : -1;
}
} // end namespace
