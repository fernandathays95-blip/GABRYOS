menu = {
__element option_reboot = "reboot";
__element option_reboottobootloader = "reboot to bootloader";
__element option_update = "update";
__element option_wipecache = "wipe cache";
__element option_reset = "wipe data/ or factory reset";
__element option_power = "power off";
};
reset = """
#!/bin/bash

# Nome da pasta
DIR="data"

# Apaga a pasta e todo o conteúdo (incluindo arquivos ocultos)
if [ -d "$DIR" ]; then
    rm -rf "$DIR"
fi

# Recria a pasta vazia
mkdir "$DIR"

# Cria o arquivo .gitkeep dentro da pasta
touch "$DIR/.gitkeep"

echo "Reset concluido"
"""
