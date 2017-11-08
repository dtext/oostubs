cmake_minimum_required(VERSION 3.0)
project(oostubs)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cc
        Makefile
        startup.asm)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories("${PROJECT_SOURCE_DIR}/device")
include_directories("${PROJECT_SOURCE_DIR}/guard")
include_directories("${PROJECT_SOURCE_DIR}/machine")
include_directories("${PROJECT_SOURCE_DIR}/object")
include_directories("${PROJECT_SOURCE_DIR}/user")

add_executable(oostubs3 ${SOURCE_FILES})
