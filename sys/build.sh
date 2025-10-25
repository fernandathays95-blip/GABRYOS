#!/bin/bash
# Script de build para GABRYOS Kernel com módulos automáticos

# Cria pasta de build
mkdir -p build
cd build

# Gera os arquivos de compilação
cmake ..

# Compila o kernel
make

echo "=============================="
echo "GABRYOS Kernel compilado com sucesso!"
echo "Executável: build/gabryos_kernel"
echo "=============================="
