cmake_minimum_required(VERSION 3.0)

project(root-tg-cui)

set(CORE_DIR core)
set(CORE_LIB core-tg-cui)

set(UI_DIR ui)
set(UI_LIB ui-tg-cui)

add_subdirectory(${CORE_DIR})
add_subdirectory(${UI_DIR})

set(DEPENDENCIES
    ${CORE_LIB}
    ${UI_LIB}
)

set(TARGET_SOURCES
    main.cc
)

add_library(${PROJECT_NAME} ${TARGET_SOURCES})

add_dependencies(${PROJECT_NAME} ${DEPENDENCIES})

target_link_libraries(root-tg-cui ${DEPENDENCIES})

