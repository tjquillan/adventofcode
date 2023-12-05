#!/bin/bash

set -e
set -o pipefail

BASE_DIR="$(readlink -f "$(dirname "$0")"/..)"

DAY="$1"

mkdir -p "${BASE_DIR}/apps/day${DAY}"

touch "${BASE_DIR}/input/day${DAY}_part1_example.txt" \
  "${BASE_DIR}/input/day${DAY}_part1.txt" \
  "${BASE_DIR}/input/day${DAY}_part2_example.txt" \
  "${BASE_DIR}/input/day${DAY}_part2.txt"

echo "int main() {}" > "${BASE_DIR}/apps/day${DAY}/day${DAY}_part1.cpp"
echo "int main() {}" > "${BASE_DIR}/apps/day${DAY}/day${DAY}_part2.cpp"

cat > "${BASE_DIR}/apps/day${DAY}/CMakeLists.txt" <<- EOM
add_executable(day${DAY}_part1)
target_sources(day${DAY}_part1 PRIVATE day${DAY}_part1.cpp)

add_executable(day${DAY}_part2)
target_sources(day${DAY}_part2 PRIVATE day${DAY}_part2.cpp)
EOM

echo "add_subdirectory(day${DAY})" >> "${BASE_DIR}/apps/CMakeLists.txt"

