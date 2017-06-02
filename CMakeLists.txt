cmake_minimum_required(VERSION 3.7)
project(pushBox)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Source/game.c)
add_executable(pushBox ${SOURCE_FILES})