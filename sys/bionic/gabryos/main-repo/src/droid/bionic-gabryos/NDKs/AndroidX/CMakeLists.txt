cmake_minimum_required(VERSION 3.10)
project(GABRYOS LANGUAGES C CXX)

# Padrão C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Incluir diretórios principais
include_directories(
    ${PROJECT_SOURCE_DIR}/kernel
    ${PROJECT_SOURCE_DIR}/API_not_supported
    ${PROJECT_SOURCE_DIR}/NDKs/AndroidX/include
)

# Adicionar subdiretórios
add_subdirectory(kernel)
add_subdirectory(API_not_supported)
add_subdirectory(NDKs/AndroidX)

# Executável principal (simulação)
add_executable(gabryos_main
    test.py
)

# Linkar bibliotecas do sistema
target_link_libraries(gabryos_main
    gabryos_kernel
    androidx_ndk
)
