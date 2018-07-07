cmake_minimum_required(VERSION 3.0)

project(tg-cui)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")
set(SOURCE_DIR src)

include_directories(${SOURCE_DIR})

add_subdirectory(${SOURCE_DIR})

add_executable(${PROJECT_NAME} "")

target_link_libraries(${PROJECT_NAME}
  root-tg-cui
)

