# sys/bionic/gabryos/main-repo/src/droid/bionic-gabryos/NDKs/AndroidX/CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(AndroidX_NDK LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SRC_FILES
    src/androidx_core.cc
    src/androidx_ui.cc
    src/androidx_system.cc
)

add_library(androidx_ndk STATIC ${SRC_FILES})
