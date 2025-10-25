#ifndef GABRYOS_GOOGLE_MAPS_H
#define GABRYOS_GOOGLE_MAPS_H

#include <stdint.h>
#include <stddef.h>

// Estruturas básicas
typedef struct {
    const char* api_key;
    const char* map_name;
    uint32_t zoom_level;
    void* backend; // ponteiro para futuras implementações reais de API
} GMapsMap;

typedef struct {
    double latitude;
    double longitude;
    const char* label;
} GMapsMarker;

// Funções principais
GMapsMap* gmaps_create_map(const char* api_key, const char* map_name, uint32_t zoom);
void gmaps_destroy_map(GMapsMap* map);

GMapsMarker* gmaps_add_marker(GMapsMap* map, double latitude, double longitude, const char* label);
void gmaps_remove_marker(GMapsMarker* marker);

void gmaps_print_map_info(GMapsMap* map);
void gmaps_print_marker_info(GMapsMarker* marker);

#endif // GABRYOS_GOOGLE_MAPS_H
