cmake_minimum_required(VERSION 3.27)

project(
  adventofcode
  VERSION 0.1.0
  LANGUAGES C CXX)

# Export compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_EXPORT_COMPILE_COMMANDS)
  set(CMAKE_C_STANDARD_INCLUDE_DIRECTORIES
      ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
endif()

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

add_executable(day1_part2)
target_sources(
  day1_part2
  PRIVATE day1_part2.cpp
  PRIVATE adventofcode.hpp)
target_compile_features(day1_part2 PUBLIC cxx_std_20)

add_executable(day2_part1)
target_sources(
  day2_part1
  PRIVATE day2_part1.cpp
  PRIVATE adventofcode.hpp)
target_compile_features(day2_part1 PUBLIC cxx_std_20)

add_executable(day2_part2)
target_sources(
  day2_part2
  PRIVATE day2_part2.cpp
  PRIVATE adventofcode.hpp)
target_compile_features(day2_part2 PUBLIC cxx_std_20)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
