find_program(CPPCHECK_PROGRAM NAMES cppcheck)
if(CPPCHECK_PROGRAM)
  set(CMAKE_CXX_CPPCHECK "${CPPCHECK_PROGRAM}")
  set(CPPCHECK_BUILD_DIR "${PROJECT_BINARY_DIR}/cppcheck")
  file(MAKE_DIRECTORY "${CPPCHECK_BUILD_DIR}")
  list(
    APPEND
    CMAKE_CXX_CPPCHECK
    "--enable=all"
    "--std=c++20"
    "--inline-suppr"
    "--cppcheck-build-dir=${CPPCHECK_BUILD_DIR}"
    "--suppress=missingIncludeSystem"
    "--suppress=unmatchedSuppression")
  if(FETCHCONTENT_BASE_DIR)
    list(APPEND CMAKE_CXX_CPPCHECK "-i${FETCHCONTENT_BASE_DIR}"
         "--suppress=*:${FETCHCONTENT_BASE_DIR}/*")
  endif()
endif()
