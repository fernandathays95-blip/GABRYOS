#!/bin/bash
mkdir -p build
cd build
cmake ..
make
echo "=============================="
echo "GABRYOS Kernel compilado com sucesso!"
echo "Executável: build/gabryos_kernel"
echo "=============================="
