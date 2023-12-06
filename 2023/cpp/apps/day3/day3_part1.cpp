#include <fmt/core.h>

#include <cstddef>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

constexpr bool is_num(char item) { return item >= '0' && item <= '9'; }

constexpr bool is_symbol(char item) { return item != '.' && !is_num(item); }

int main() {
  std::string line;
  std::vector<std::vector<std::pair<char, bool>>> field;

  // Build the field
  while (std::getline(std::cin, line)) {
    field.emplace_back(line.length());
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
      if (j > 0) {
        item.second |= is_symbol(row[j - 1].first);
      }
      if (j < row.size() - 1) {
        item.second |= is_symbol(row[j + 1].first);
      }
      if (i > 0) {
        item.second |= is_symbol(field[i - 1][j].first);
        if (j > 0) {
          item.second |= is_symbol(field[i - 1][j - 1].first);
        }
        if (j < row.size() - 1) {
          item.second |= is_symbol(field[i - 1][j + 1].first);
        }
      }
      if (i < field.size() - 1) {
        item.second |= is_symbol(field[i + 1][j].first);
        if (j > 0) {
          item.second |= is_symbol(field[i + 1][j - 1].first);
        }
        if (j < row.size() - 1) {
          item.second |= is_symbol(field[i + 1][j + 1].first);
        }
      }
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
      } else if (adj) {  // If not a number, flush number if adjacent
        sum += num;
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
