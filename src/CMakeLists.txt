cmake_minimum_required(VERSION 3.0)

project(root-tg-cui)

set(DHANDLER_DIR dhandler)
set(DHANDLER_LIB dhandler-tg-cui)

set(UI_DIR ui)
set(UI_LIB ui-tg-cui)

set(CONTROLLER_DIR controller)
set(CONTROLLER_LIB controller-tg-cui)

add_subdirectory(${DHANDLER_DIR})
add_subdirectory(${UI_DIR})
add_subdirectory(${CONTROLLER_DIR})

set(DEPENDENCIES
  ${DHANDLER_LIB}
  ${UI_LIB}
  ${CONTROLLER_LIB}
)

set(TARGET_SOURCES
  main.cc
)

add_library(${PROJECT_NAME} ${TARGET_SOURCES})

add_dependencies(${PROJECT_NAME} ${DEPENDENCIES})

target_link_libraries(root-tg-cui ${DEPENDENCIES})

