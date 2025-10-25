#include "vulkan.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

VulkanInstance* vulkan_create_instance(const char* app_name, uint32_t version) {
    VulkanInstance* instance = (VulkanInstance*)malloc(sizeof(VulkanInstance));
    instance->name = strdup(app_name);
    instance->version = version;
    printf("[VULKAN] Instância criada: %s (v%u)\n", instance->name, instance->version);
    return instance;
}

void vulkan_destroy_instance(VulkanInstance* instance) {
    if (instance) {
        printf("[VULKAN] Instância destruída: %s\n", instance->name);
        free((void*)instance->name);
        free(instance);
    }
}

VulkanDevice* vulkan_create_device(VulkanInstance* instance, const char* device_name) {
    VulkanDevice* device = (VulkanDevice*)malloc(sizeof(VulkanDevice));
    device->name = strdup(device_name);
    device->instance = instance;
    printf("[VULKAN] Dispositivo criado: %s para instância %s\n", device->name, instance->name);
    return device;
}

void vulkan_destroy_device(VulkanDevice* device) {
    if (device) {
        printf("[VULKAN] Dispositivo destruído: %s\n", device->name);
        free((void*)device->name);
        free(device);
    }
}

void vulkan_info_instance(VulkanInstance* instance) {
    if (instance)
        printf("[VULKAN] Info Instância: %s (v%u)\n", instance->name, instance->version);
}

void vulkan_info_device(VulkanDevice* device) {
    if (device)
        printf("[VULKAN] Info Dispositivo: %s ligado à instância %s\n",
               device->name, device->instance->name);
}
