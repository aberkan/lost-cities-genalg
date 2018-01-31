// player-console.cc
//
// Lost Cities GenAlg
//
// Author: Adam Berkan
//
#include "player-console.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>

namespace lostcities {

// Reads a single character from stdin, but also any extra trailing \n.  If
// the whole line is empty, return \n.
char ReadChar() {
  char c = getchar();
  if (c == '\n') {
    return c;
  }
  char r = getchar();
  if (r != '\n') {
    ungetc(r, stdin);
  }
  return c;
}

void PlayerConsole::PrintState(const Tableau *other_tab,
                               const DiscardPiles discard_piles) const {
  using std::cout;

  cout << "Hand :" << hand().debug_string() << "\n";
  cout << "Discard Piles: ";
  for (int i = 0; i < kNumDiscardPiles; ++i) {
    cout << discard_piles[i].debug_string();
  }
  cout << "\n";
  cout << "Player Tableau: " << tableau().debug_string() << "\n";
  cout << "Other Tableau: " << other_tab->debug_string() << "\n";
  cout << "Scores You " << tableau().Score() << ", Them " << other_tab->Score()
       << "\n";
}

PlayMove PlayerConsole::PlayCard(const Tableau *other_tab,
                                 const DiscardPiles &discard_piles) {
  using std::cout;

  Hand h = hand();
  h.Sort();

  for (;;) {
    PrintState(other_tab, discard_piles);
    cout << "\n";
    cout << "Select [P]lay or [D]iscard\n";
    char input;
    input = ReadChar();
    input = std::toupper(input);
    if (input != 'P' && input != 'D') {
      cout << "Invalid input: " << input << "\n";
      continue;
    }

    if (input == 'P') {
      // Play a card
      cout << "Select a card to play [1-8]\n";
      input = ReadChar();
      if (input < '1' || input > '8') {
        cout << "Invalid index: " << input << "\n";
        continue;
      }
      Card card = h.At(input - '1');
      if (!tableau().IsPlayable(card)) {
        cout << "Card " << card.debug_string() << " cannot be played.\n";
        continue;
      }
      cout << "Played " << card.debug_string() << " to the tableau\n";
      return TableauMove(card);
    }
    // Discard a card
    cout << "Select a card to discard [1-8]\n";
    input = ReadChar();
    if (input < '1' || input > '8') {
      cout << "Invalid index: " << input << "\n";
      continue;
    }
    int index = input - '1';
    cout << "Select a pile to discard too [1-5]\n";
    input = ReadChar();
    if (input < '1' || input > '5') {
      cout << "Invalid pile index: " << input << "\n";
      continue;
    }
    Card card = h.At(index);
    int discard_index = input - '1';
    cout << "Discarded " << card.debug_string() << " to pile " << discard_index
         << "\n";
    return DiscardMove(card, discard_index);
  }
}

DrawMove PlayerConsole::DrawCard(const Tableau *other_tab,
                                 const DiscardPiles &discard_piles) {
  using std::cout;

  for (;;) {
    cout << "Enter discard pile to draw from [1-5] or press enter to draw from "
            "the pile.\n";
    char input;
    input = ReadChar();
    if (input == '\n') {
      cout << "Drew from the deck.\n";
      return DeckDraw();
    }
    if (input < '1' || input > '5') {
      cout << "Invalid pile " << input;
      continue;
    }
    int index = input - '1';
    // Draw from discard
    const Pile &pile = discard_piles[index];
    if (pile.size() == 0) {
      cout << "Pile " << index << " is empty.\n";
      continue;
    }
    cout << "Drew from pile " << index << ".\n";
    return DiscardDraw(index);
  }
}

void PlayerConsole::LearnDrawnCard(Card c) {
  std::cout << "Got Card: " << c.debug_string() << "\n";
}

} // end namespace
