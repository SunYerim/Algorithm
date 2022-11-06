cmake_minimum_required(VERSION 3.0.0)
project(MusicLibraryProgram VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(MusicLibraryProgram code.cpp library.cpp library.h string_tools.h string_tools.cpp haha.txt)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
