cmake_minimum_required(VERSION 3.20)
project(cpp-mini-project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(app src/main.cpp)

enable_testing()
find_package(GTest REQUIRED)

add_executable(test_LRUCache test/test_LRUCache.cpp)
target_link_libraries(test_LRUCache GTest::GTest GTest::Main)

add_test(NAME LRUCacheTest COMMAND test_LRUCache)