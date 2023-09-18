cmake_minimum_required(VERSION 3.24)
project(othello)

set(CMAKE_CXX_STANDARD 17)

add_executable(othello main.cpp othello.h)


set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include/SFML)
target_link_libraries(othello sfml-system sfml-window sfml-graphics sfml-audio)