cmake_minimum_required(VERSION 3.0)

project(tg-cui)

find_package(Curses REQUIRED)
if(NOT CURSES_FOUND)
  message(SEND_ERROR "Curses not found.")
  return()
else()
  include_directories(${CURSES_INCLUDE_DIR})
endif()

include_directories(src/)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")

set(TARGET_SOURCES src/main.cpp)

add_executable(tg-cui ${TARGET_SOURCES})

target_link_libraries(tg-cui ${CURSES_LIBRARIES})

