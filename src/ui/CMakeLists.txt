cmake_minimum_required(VERSION 3.0)

project(ui-tg-cui)

find_package(Curses REQUIRED)
if (NOT CURSES_FOUND)
  message(SEND_ERROR "Curses not found.")
  return()
else ()
  include_directories(${CURSES_INCLUDE_DIR})
endif ()

set(TARGET_SOURCES
  view.cc
  main_panel.cc
  dialogs_panel.cc
  chat_panel.cc
)

add_library(${PROJECT_NAME} STATIC ${TARGET_SOURCES})

target_link_libraries(${PROJECT_NAME} STATIC ${CURSES_LIBRARIES})
