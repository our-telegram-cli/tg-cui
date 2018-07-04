cmake_minimum_required(VERSION 3.0)

project(ui-tg-cui)

set(TARGET_SOURCES
    view.cc
    main_panel.cc
    chat_panel.cc
    dialogs_panel.cc
)

add_library(ui-tg-cui STATIC ${TARGET_SOURCES})

