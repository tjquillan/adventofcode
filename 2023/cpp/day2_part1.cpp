#include <array>
#include <cstdio>
#include <format>
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

struct game {
  int id;
  int red;
  int green;
  int blue;
};

constexpr int MAX_RED = 12;
constexpr int MAX_GREEN = 13;
constexpr int MAX_BLUE = 14;

int main() {
  std::string line;
  std::vector<game> games;
  while (std::getline(std::cin, line)) {
    int game_id;
    int used;
    std::sscanf(line.c_str(), "Game %d: %n", &game_id, &used);
    line.erase(0, used);

    game cur_game{game_id, 0, 0, 0};

    for (const auto& hand :
         std::views::split(std::string_view{line}, std::string_view{"; "})) {
      for (const auto& cube : std::views::split(hand, std::string_view(", "))) {
        std::string const cube_str(cube.begin(), cube.end());
        int count;
        std::array<char, 20> temp;

        std::sscanf(cube_str.c_str(), "%d %s", &count, temp.data());
        std::string const color = temp.data();

        if (color == "red" && count > cur_game.red) {
          cur_game.red = count;
        } else if (color == "green" && count > cur_game.green) {
          cur_game.green = count;
        } else if (color == "blue" && count > cur_game.blue) {
          cur_game.blue = count;
        }
      }
    }

    if (cur_game.red > MAX_RED || cur_game.green > MAX_GREEN ||
        cur_game.blue > MAX_BLUE) {
      continue;
    }

    games.push_back(cur_game);
  }

  int id_sum = 0;
  for (const auto& entry : games) {
    id_sum += entry.id;
  }
  std::cout << id_sum << '\n';
}
