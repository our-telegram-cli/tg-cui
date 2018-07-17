cmake_minimum_required(VERSION 3.0)

project(tg-cui)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")
set(SOURCE_DIR src)

include_directories(${SOURCE_DIR})
include_directories(tdlib)

add_subdirectory(tdlib)

add_executable(${PROJECT_NAME} ${SOURCE_DIR}/main.cc)
add_dependencies(${PROJECT_NAME} TdStatic)

target_link_libraries(${PROJECT_NAME} TdStatic)

