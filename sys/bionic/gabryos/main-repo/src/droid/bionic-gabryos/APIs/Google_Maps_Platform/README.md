# Google Maps Platform API - GABRYOS

Esta pasta contém a implementação real da API Google Maps para o GABRYOS, usando chamadas HTTP via libcurl.

## Estruturas principais
- `GMapsMap` : representa um mapa com API key e zoom.
- `GMapsMarker` : representa um marcador no mapa.

## Funções
- `gmaps_create_map(api_key, map_name, zoom)` : cria um mapa real.
- `gmaps_destroy_map(map)` : destrói um mapa.
- `gmaps_add_marker(map, lat, long, label)` : adiciona um marcador real.
- `gmaps_remove_marker(marker)` : remove um marcador.
- `gmaps_print_map_info(map)` : imprime informações do mapa.
- `gmaps_print_marker_info(marker)` : imprime informações do marcador.

> Observação: a integração com a rede é feita via libcurl, podendo conectar-se diretamente à Google Maps Platform APIs.
