cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(snake)

add_executable(snake snake.c snake.h)
target_sources(snake PRIVATE map.c)

find_package(Curses)
target_link_libraries( snake ${CURSES_LIBRARIES} )
