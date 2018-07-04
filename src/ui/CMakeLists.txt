cmake_minimum_required(VERSION 3.0)

project(ui-tg-cui)

set(TARGET_SOURCES
    chat_panel.cc
    dialogs_panel.cc
    main_panel.cc
    view.cc
)

add_library(${PROJECT_NAME} STATIC ${TARGET_SOURCES})

