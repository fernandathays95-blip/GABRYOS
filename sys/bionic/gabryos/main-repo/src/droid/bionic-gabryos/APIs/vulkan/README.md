# Vulkan API - GABRYOS

Esta pasta contém a implementação simulada da API Vulkan para o GABRYOS.

## Estruturas principais
- `VulkanInstance` : representa uma instância Vulkan.
- `VulkanDevice` : representa um dispositivo ligado a uma instância.

## Funções
- `vulkan_create_instance(app_name, version)` : cria uma instância Vulkan.
- `vulkan_destroy_instance(instance)` : destrói uma instância.
- `vulkan_create_device(instance, device_name)` : cria um dispositivo Vulkan.
- `vulkan_destroy_device(device)` : destrói um dispositivo.
- `vulkan_info_instance(instance)` : exibe informações da instância.
- `vulkan_info_device(device)` : exibe informações do dispositivo.
