cmake_minimum_required(VERSION 3.0)
project(controller-tg-cui)

set(TARGET_SOURCES
  controller.cc
)

add_library(${PROJECT_NAME} STATIC ${TARGET_SOURCES})
