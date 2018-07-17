cmake_minimum_required(VERSION 3.0)

project(tg-cui)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")

include_directories(tdlib)
add_subdirectory(tdlib)

add_executable(${PROJECT_NAME}
    src/main.cc
    src/view.cc
    src/interact.cc
    src/widgets.cc
    src/main_panel.cc
    src/dialogs_panel.cc
    src/chat_panel.cc
    )

add_dependencies(${PROJECT_NAME} TdStatic)
target_link_libraries(${PROJECT_NAME} TdStatic)

find_package(Curses REQUIRED)
if (NOT CURSES_FOUND)
  message(SEND_ERROR "Curses not found.")
  return()
else ()
  include_directories(${CURSES_INCLUDE_DIR})
endif ()

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})
