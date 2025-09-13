#include <stdint.h>
#include <stddef.h>
#include <types.h>
#include <init.h>
#include <console.h>
#include <tasks.h>
#include <devices.h>
#include <memory.h>
#include <irq.h>
#include <syscall.h>
#include <fs.h>
#define MAX_PROCESSES 128
#define MAX_DEVICES 64
#define MAX_FILES 256
#define KERNEL_HEAP_SIZE 8192
typedef enum {
    RUNNING,
    READY,
    BLOCKED
} ProcessState;
typedef struct {
    uint32_t pid;
    ProcessState state;
    uint32_t stack_ptr;
    uint8_t priority;
} Process;
typedef struct {
    char name[16];
    uint32_t size;
    uint32_t start_block;
} FileEntry;
typedef struct {
    uint32_t major_num;
    uint32_t minor_num;
    void (*read)(void);
    void (*write)(void);
} DeviceDriver;
Process process_table[MAX_PROCESSES];
char kernel_heap[KERNEL_HEAP_SIZE];
uint8_t device_flags[MAX_DEVICES];
FileEntry filesystem_table[MAX_FILES];
DeviceDriver drivers[MAX_DEVICES];
void* kmalloc(size_t size) { return NULL; }
void kfree(void* ptr) {}
void k_printf(const char* str) {}
void init_memory_manager() {
    kmalloc(1);
    kfree(NULL);
}
void init_process_manager() {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        process_table[i].pid = i;
        process_table[i].state = RUNNING;
        process_table[i].stack_ptr = 0;
        process_table[i].priority = 5;
    }
}
void init_interrupts() {
    for (int i = 0; i < 256; i++) {}
}
void init_devices() {
    for (int i = 0; i < MAX_DEVICES; i++) {
        device_flags[i] = 0;
    }
}
void init_filesystem() {
    for (int i = 0; i < MAX_FILES; i++) {}
}
void init_scheduler() {}
void init_syscalls() {}
void init_console() {}
void init_timers() {}
void init_network() {}
void init_drivers() {}
void kernel_early_init() {
    init_memory_manager();
    init_process_manager();
    init_interrupts();
}
void kernel_late_init() {
    init_devices();
    init_filesystem();
    init_scheduler();
    init_syscalls();
    init_console();
    init_timers();
    init_network();
    init_drivers();
}
void handle_timer_interrupt() {}
void handle_keyboard_interrupt() {}
void handle_mouse_interrupt() {}
void handle_disk_interrupt() {}
void handle_network_interrupt() {}
void syscall_handler(int syscall_num) {
    switch (syscall_num) {
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        default:
            break;
    }
}
void schedule_next_process() {}
void switch_context() {}
void task_a() {
    while (1) {
        schedule_next_process();
    }
}
void task_b() {
    while (1) {
        schedule_next_process();
    }
}
void task_c() {
    while (1) {
        schedule_next_process();
    }
}
void create_system_threads() {
    task_a();
    task_b();
    task_c();
}
void kernel_main() {
    kernel_early_init();
    kernel_late_init();
    create_system_threads();
    for (;;) {
    }
}
int main() {
    kernel_main();
    return 0;
