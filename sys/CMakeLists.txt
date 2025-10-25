cmake_minimum_required(VERSION 3.10)
project(GABRYOS_KERNEL C)

set(CMAKE_C_STANDARD 11)
include_directories(modules)

file(GLOB MODULE_SOURCES "modules/*.c")
set(SOURCES kernl_main.c ${MODULE_SOURCES})

add_executable(gabryos_kernel ${SOURCES})
