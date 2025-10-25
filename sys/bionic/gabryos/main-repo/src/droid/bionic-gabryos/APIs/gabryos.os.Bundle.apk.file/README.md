# gabryos.os.Bundle.apk.file API - GABRYOS (Real)

Esta pasta contém a implementação real da API para manipulação de bundles APK no GABRYOS.

## Estrutura principal
- `GabryosBundleAPK` : representa um arquivo APK com pacote, versão e tamanho.

## Funções
- `bundle_load(apk_path)` : carrega um APK real, extrai informações do AndroidManifest.xml.
- `bundle_unload(bundle)` : libera a memória do bundle.
- `bundle_print_info(bundle)` : imprime informações reais do APK.

> Observação: utiliza **libzip** para abrir o arquivo APK e ler o `AndroidManifest.xml`. Não há simulação.
