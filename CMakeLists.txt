cmake_minimum_required(VERSION 3.27)

project(unidade_06)

include_directories(${CMAKE_SOURCE_DIR}/src/include)

set(SOURCES 
    src/main.cpp
    src/tarefa.cpp
)

add_executable(unidade_06 ${SOURCES})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)