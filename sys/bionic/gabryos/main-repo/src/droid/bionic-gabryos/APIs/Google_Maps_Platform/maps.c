#include "maps.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h> // permite chamadas HTTP reais à API do Google

GMapsMap* gmaps_create_map(const char* api_key, const char* map_name, uint32_t zoom) {
    GMapsMap* map = (GMapsMap*)malloc(sizeof(GMapsMap));
    map->api_key = strdup(api_key);
    map->map_name = strdup(map_name);
    map->zoom_level = zoom;
    map->backend = NULL; // aqui você pode integrar a rede/HTTP real
    printf("[GMAPS] Mapa criado: %s, Zoom: %u\n", map->map_name, map->zoom_level);
    return map;
}

void gmaps_destroy_map(GMapsMap* map) {
    if (map) {
        printf("[GMAPS] Mapa destruído: %s\n", map->map_name);
        free((void*)map->api_key);
        free((void*)map->map_name);
        free(map);
    }
}

GMapsMarker* gmaps_add_marker(GMapsMap* map, double latitude, double longitude, const char* label) {
    GMapsMarker* marker = (GMapsMarker*)malloc(sizeof(GMapsMarker));
    marker->latitude = latitude;
    marker->longitude = longitude;
    marker->label = strdup(label);

    // Aqui você pode adicionar chamada real à Google Maps API usando libcurl
    printf("[GMAPS] Marker adicionado em %s: (%f, %f) Label: %s\n", map->map_name, latitude, longitude, label);

    return marker;
}

void gmaps_remove_marker(GMapsMarker* marker) {
    if (marker) {
        printf("[GMAPS] Marker removido: %s\n", marker->label);
        free((void*)marker->label);
        free(marker);
    }
}

void gmaps_print_map_info(GMapsMap* map) {
    if (map)
        printf("[GMAPS] Info Mapa: %s, Zoom: %u\n", map->map_name, map->zoom_level);
}

void gmaps_print_marker_info(GMapsMarker* marker) {
    if (marker)
        printf("[GMAPS] Info Marker: %s, Latitude: %f, Longitude: %f\n", marker->label, marker->latitude, marker->longitude);
}
