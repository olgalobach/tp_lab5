cmake_minimum_required(VERSION 3.4)

include_directories("${CMAKE_SOURCE_DIR}/banking")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(
  HUNTER_CACHE_SERVERS
  "https://github.com/bmstu-iu8-cpp-sem-3/hunter-cache"
  CACHE STRING "Default cache server"
)

include("cmake/HunterGate.cmake")

huntergate(
  URL "https://github.com/cpp-pm/hunter/archive/v0.23.314.tar.gz"
  SHA1 "95c47c92f68edb091b5d6d18924baabe02a6962a"
)

project(banking)
hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)
find_package(Threads)

add_executable(
  tests
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp
)

target_link_libraries(
  tests
  ${CMAKE_THREAD_LIBS_INIT}
  GTest::gtest
  GTest::gtest_main
  banking
)

enable_testing()
add_test(NAME unit_tests COMMAND tests)

add_subdirectory(banking)

target_include_directories(banking
   PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(tests
   PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
