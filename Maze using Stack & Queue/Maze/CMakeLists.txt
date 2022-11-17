cmake_minimum_required(VERSION 3.0.0)
project(MazeRoute VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(MazeRoute main.cpp  pos.cpp pos.h stack.cpp stack.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
