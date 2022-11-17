cmake_minimum_required(VERSION 3.0.0)
project(maze2 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(maze2 main.cpp queue.h queue.cpp pos.h pos.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
