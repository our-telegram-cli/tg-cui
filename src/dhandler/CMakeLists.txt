cmake_minimum_required(VERSION 3.0)

project(dhandler-tg-cui)

set(TARGET_HEADERS
  model.h
  authorization.h
  interfaces/authorizable.h
)

set(TARGET_SOURCES
  model.cc
  authorization.cc
)


add_library(${PROJECT_NAME} STATIC ${TARGET_HEADERS} ${TARGET_SOURCES})

