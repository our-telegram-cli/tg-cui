cmake_minimum_required(VERSION 3.0)

project(tg-cui)

find_package(Curses REQUIRED)
if(NOT CURSES_FOUND)
  message(SEND_ERROR "Curses not found.")
  return()
else()
  include_directories(${CURSES_INCLUDE_DIR})
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")
set(SOURCE_DIR src)

include_directories(${SOURCE_DIR})

add_subdirectory(${SOURCE_DIR})

add_executable(${PROJECT_NAME} "")

target_link_libraries(${PROJECT_NAME}
  ${CURSES_LIBRARIES}
  root-tg-cui
)

