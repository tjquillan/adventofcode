add_executable(day3_part1)
target_sources(day3_part1 PRIVATE day3_part1.cpp)
target_link_libraries(day3_part1 PRIVATE fmt::fmt scn::scn)

add_executable(day3_part2)
target_sources(day3_part2 PRIVATE day3_part2.cpp)
target_link_libraries(day3_part2 PRIVATE fmt::fmt scn::scn)
