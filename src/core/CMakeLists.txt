cmake_minimum_required(VERSION 3.0)

project(core-tg-cui)

set(TARGET_SOURCES
    model.cc
)

add_library(${PROJECT_NAME} STATIC ${TARGET_SOURCES})

