set(KERNEL_SRC
    kernl_main.cc
    kernl_drivers.cc
    kernl_memory.cc
)

add_library(gabryos_kernel STATIC ${KERNEL_SRC})
