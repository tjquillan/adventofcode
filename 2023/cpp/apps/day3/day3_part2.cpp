#include <fmt/core.h>

#include <cstddef>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

constexpr bool is_num(char item) { return item >= '0' && item <= '9'; }

constexpr bool is_symbol(char item) { return item != '.' && !is_num(item); }

void check_adjacency(std::vector<std::vector<std::pair<char, bool>>>& field,
                     std::size_t row, std::size_t col) {
  auto& item = field[row][col];

  const std::size_t col_base = col > 0 ? col - 1 : col;
  const std::size_t row_base = row > 0 ? row - 1 : row;

  for (std::size_t i = row_base; i <= row + 1 && i < field.size(); i++) {
    for (std::size_t j = col_base; j <= col + 1 && j < field[row].size(); j++) {
      if (is_symbol(field[i][j].first)) {
        item.second = true;
        break;
      }
    }
  }
}

int main() {
  std::string line;
  std::vector<std::vector<std::pair<char, bool>>> field;

  // Build the field
  while (std::getline(std::cin, line)) {
    field.emplace_back();
    for (const auto& entry : line) {
      field.back().emplace_back(std::make_pair(entry, false));
    }
  }

  // Determin numbers adjacent to symbols
  for (std::size_t i = 0; i < field.size(); i++) {
    auto& row = field[i];
    for (std::size_t j = 0; j < row.size(); j++) {
      auto& item = row[j];
      if (!is_num(item.first)) {
        continue;
      }
      check_adjacency(field, i, j);
    }
  }

  // Construct and sum full numbers
  int sum = 0;
  for (const auto& row : field) {
    bool adj = false;
    int num = 0;
    for (const auto& item : row) {
      if (is_num(item.first)) {
        num = (num * 10) + (item.first - '0');
        adj |= item.second;
      } else {
        if (adj) {
          sum += num;
        }
        num = 0;
        adj = false;
      }
    }
    if (adj) {
      sum += num;
    }
  }

  fmt::println("{}", sum);
}
