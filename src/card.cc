// Lost Cities GenAlg
//
// Author: Adam Berkan
//
#include "card.h"

#include <string>
#include <vector>

#include "absl/strings/str_join.h"

namespace lostcities {
// static
const std::array<int, 12> Card::Ranks = {0, 0, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10};
const std::array<Card::Color, Card::kNumColors> Card::Colors = {
    Card::RED, Card::GREEN, Card::BLUE, Card::YELLOW, Card::WHITE};

std::vector<std::string> kColorNames = {"Red", "Green", "Blue", "Yellow",
                                        "White"};
std::string Card::debug_string() {
  return absl::StrCat("[", ColorName(), " ", rank_, "]");
}

// static
absl::string_view Card::ColorName(Color color) {
  return kColorNames[int(color)];
}

} // end namespace
