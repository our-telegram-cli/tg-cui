cmake_minimum_required(VERSION 3.0)

project(root-tg-cui)

add_subdirectory(ui/)

set(TARGET_SOURCES
    main.cc
)

add_library(root-tg-cui ${TARGET_SOURCES})

target_link_libraries(root-tg-cui
    ui-tg-cui
)

