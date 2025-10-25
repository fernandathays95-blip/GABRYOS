#ifndef GABRYOS_VULKAN_H
#define GABRYOS_VULKAN_H

#include <stdint.h>
#include <stddef.h>

// Estruturas básicas Vulkan simuladas
typedef struct {
    const char* name;
    uint32_t version;
} VulkanInstance;

typedef struct {
    const char* name;
    VulkanInstance* instance;
} VulkanDevice;

// Funções principais da API Vulkan para GABRYOS
VulkanInstance* vulkan_create_instance(const char* app_name, uint32_t version);
void vulkan_destroy_instance(VulkanInstance* instance);

VulkanDevice* vulkan_create_device(VulkanInstance* instance, const char* device_name);
void vulkan_destroy_device(VulkanDevice* device);

void vulkan_info_instance(VulkanInstance* instance);
void vulkan_info_device(VulkanDevice* device);

#endif // GABRYOS_VULKAN_H
