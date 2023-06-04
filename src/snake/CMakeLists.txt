set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(snake snake.cpp snake.h)
target_link_libraries( snake ${CURSES_LIBRARIES} )


