#include <iostream>
#include <string>

int main() {
  std::string line;
  int count = 0;

  char first = -1;
  char last = -1;
  while (std::getline(std::cin, line)) {
    for (const auto& val : line) {
      if (val >= '0' && val <= '9') {
        last = val;
        if (first < 0) {
          first = val;
        }
      }
    }

    count += ((first - '0') * 10) + (last - '0');
    first = -1;
    last = -1;
  }

  std::cout << count << '\n';
}
