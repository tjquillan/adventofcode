#include <array>
#include <cstddef>
#include <format>
#include <iostream>
#include <map>
#include <optional>
#include <string>

const std::map<std::string, char> num_map{
    {"one", '1'}, {"two", '2'},   {"three", '3'}, {"four", '4'}, {"five", '5'},
    {"six", '6'}, {"seven", '7'}, {"eight", '8'}, {"nine", '9'}};
const auto nums = std::to_array<std::string>({
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
});

std::size_t get_max_num_length() {
  std::size_t len = 0;
  for (const auto& [key, val] : num_map) {
    const std::size_t cur_len = key.length();
    if (cur_len > len) {
      len = cur_len;
    }
  }
  return len;
}

void regress_match(std::string& str) {
  while (!str.empty()) {
    bool match = false;
    for (const auto& entry : nums) {
      if (entry.find(str) == 0) {
        match = true;
        break;
      }
    }
    if (!match) {
      str.erase(str.begin());
    } else {
      break;
    }
  }
}

int main() {
  const std::size_t max_str_len = get_max_num_length();

  std::string line;
  std::string num_str;
  int count = 0;

  char first = -1;
  char last = -1;

  while (std::getline(std::cin, line)) {
    for (const auto& val : line) {
      if (val >= '0' && val <= '9') {
        last = val;
        if (first < 0) {
          first = last;
        }
      } else if (num_str.size() > max_str_len) {
        num_str.clear();
      } else {
        num_str += val;
        const auto entry = num_map.find(num_str);

        if (entry != num_map.cend()) {
          last = entry->second;
          if (first < 0) {
            first = last;
          }
        }

        regress_match(num_str);
      }
    }

    std::cout << std::format("first: {}, last: {}\n", first, last);

    count += ((first - '0') * 10) + (last - '0');
    first = -1;
    last = -1;
  }

  std::cout << count << '\n';
}
