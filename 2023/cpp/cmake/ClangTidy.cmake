find_program(CLANG_TIDY_PROGRAM NAMES "clang-tidy")
if(CLANG_TIDY_PROGRAM)
  set(CLANG_TIDY_COMMAND "${CLANG_TIDY_PROGRAM}")
endif()
