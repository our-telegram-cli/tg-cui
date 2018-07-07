cmake_minimum_required(VERSION 3.0)

project(dhandler-tg-cui)

set(TARGET_SOURCES
  model.cc
  authorization.cc
  interfaces/authorizable.h
)


add_library(${PROJECT_NAME} STATIC ${TARGET_SOURCES})

