cmake_minimum_required(VERSION 3.0)

project(ui-tg-cui)

set(TARGET_SOURCES
  view.cc
  main_panel.cc
  dialogs_panel.cc
  chat_panel.cc
)

add_library(${PROJECT_NAME} STATIC ${TARGET_SOURCES})

