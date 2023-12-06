cmake_minimum_required(VERSION 3.27)

project(
  adventofcode
  VERSION 0.1.0
  LANGUAGES C CXX)

# Export compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_EXPORT_COMPILE_COMMANDS)
  set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES
      ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})
endif()

# Only do these if this is the main project, and not if it is included through
# add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  # Let's ensure -std=c++xx instead of -std=g++xx
  set(CMAKE_CXX_EXTENSIONS OFF)

  # Let's nicely support folders in IDE's
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  # Target C++ 20
  set(CMAKE_CXX_STANDARD 20)

  # Use stricter warnings
  if(MSVC)
    add_compile_options(/W4)
  else()
    add_compile_options(-Wall -Wextra -Wpedantic)
  endif()

  # Set warnings as errors
  set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

  # Enable CTest
  include(CTest)
  enable_testing()
endif()

# Enable clang-tidy
find_program(CLANG_TIDY_PROGRAM NAMES "clang-tidy")
set(CLANG_TIDY_COMMAND "${CLANG_TIDY_PROGRAM}")

# Enable CCache
find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  set(CMAKE_C_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")
  set(CMAKE_CXX_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")
  set(CMAKE_CUDA_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")
endif()

# Add dependencies
include(FetchContent)
FetchContent_Declare(
  fmtlib
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG f5e54359df4c26b6230fc61d38aa294581393084)
FetchContent_Declare(
  scnlib
  GIT_REPOSITORY https://github.com/eliaskosunen/scnlib.git
  GIT_TAG eac40e8e7fcaf73f06ea2ffb8a1aaf34f90994f4)
FetchContent_MakeAvailable(fmtlib scnlib)

find_program(CPPCHECK_PROGRAM NAMES cppcheck)
if(CPPCHECK_PROGRAM)
  set(CMAKE_CXX_CPPCHECK "${CPPCHECK_PROGRAM}")
  list(
    APPEND
    CMAKE_CXX_CPPCHECK
    "--enable=all"
    "--std=c++20"
    "--inline-suppr"
    "--cppcheck-build-dir=${PROJECT_BINARY_DIR}"
    "--suppress=missingIncludeSystem"
    "--suppress=unmatchedSuppression")
  if(FETCHCONTENT_BASE_DIR)
    list(APPEND CMAKE_CXX_CPPCHECK "-i${FETCHCONTENT_BASE_DIR}"
         "--suppress=*:${FETCHCONTENT_BASE_DIR}/*")
  endif()
endif()

# Include apps
add_subdirectory(apps)
