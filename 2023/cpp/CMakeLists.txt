cmake_minimum_required(VERSION 3.27)

project(
  adventofcode
  VERSION 0.1.0
  LANGUAGES C CXX)

# Export compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable clang-tidy
find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
set(CLANG_TIDY_COMMAND "${CLANG_TIDY_EXE}")

include(CTest)
enable_testing()

add_executable(day1_part1)
target_sources(
  day1_part1
  PRIVATE day1_part1.cpp
  PRIVATE adventofcode.hpp)
target_compile_features(day1_part1 PUBLIC cxx_std_20)
# set_target_properties(day1_part1 PROPERTIES CXX_CLANG_TIDY
# "${CLANG_TIDY_COMMAND}")

add_executable(day1_part2)
target_sources(
  day1_part2
  PRIVATE day1_part2.cpp
  PRIVATE adventofcode.hpp)
target_compile_features(day1_part2 PUBLIC cxx_std_20)
# set_target_properties(day1_part2 PROPERTIES CXX_CLANG_TIDY
# "${CLANG_TIDY_COMMAND}")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
