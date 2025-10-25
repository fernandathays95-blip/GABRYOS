cmake_minimum_required(VERSION 3.10)
project(GABRYOS_KERNEL C)

set(CMAKE_C_STANDARD 11)

# Inclui a pasta de módulos
include_directories(modules)

# Adiciona todos os .c da pasta modules automaticamente
file(GLOB MODULE_SOURCES "modules/*.c")

# Arquivo principal do kernel
set(SOURCES
    kernl_main.c
    ${MODULE_SOURCES}
)

add_executable(gabryos_kernel ${SOURCES})
