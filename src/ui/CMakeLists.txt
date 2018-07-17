cmake_minimum_required(VERSION 3.0)

project(ui-tg-cui)

find_package(Curses REQUIRED)
if (NOT CURSES_FOUND)
  message(SEND_ERROR "Curses not found.")
  return()
else ()
  include_directories(${CURSES_INCLUDE_DIR})
endif ()

set(TARGET_HEADERS
  view.h
  interact.h
  widgets.h
  main_panel.h
  dialogs_panel.h
  chat_panel.h
)

set(TARGET_SOURCES
  view.cc
  interact.cc
  widgets.cc
  main_panel.cc
  dialogs_panel.cc
  chat_panel.cc
)

add_library(${PROJECT_NAME} ${TARGET_HEADERS} ${TARGET_SOURCES})

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})
