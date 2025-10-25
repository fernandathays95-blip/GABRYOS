cmake_minimum_required(VERSION 3.10)
project(gabryskernl)

add_library(gabryskernl SHARED
    kernl_main.cc
    kernl_drivers.cc
    kernl_memory.cc
    kernl_jni.cc
)

find_library(log-lib log)
target_include_directories(gabryskernl PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(gabryskernl ${log-lib})
