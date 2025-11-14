cmake_minimum_required(VERSION 3.10)
project(contact_manager C)

set(CMAKE_C_STANDARD 11)

add_executable(contact_manager
    src/main.c
)

target_include_directories(contact_manager PRIVATE include)