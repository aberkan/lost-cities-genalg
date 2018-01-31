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
  int current_player_index = 0;
  while (deck_.size() > 0) {
    Player *current_player = players_[current_player_index].get();
    int other_player_index = (current_player_index + 1) % 2;
    Player *other_player = players_[other_player_index].get();
    std::cout << "=============== Player " << current_player_index + 1
              << "===============\n";
    PlayMove pmove =
        current_player->PlayCard(&other_player->tableau_view(), discard_piles_);
    current_player->DoPlayMove(pmove, discard_piles_);
    DrawMove dmove =
        current_player->DrawCard(&other_player->tableau_view(), discard_piles_);
    if (dmove.type_ == DrawMove::DECK) {
      current_player->AddCard(deck_.Pop());
    } else {
      current_player->AddCard(discard_piles_[dmove.pile_number_].Pop());
    }

    current_player_index = other_player_index;
    std::cout << "Deck Size: " << deck_.size() << "\n";
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
