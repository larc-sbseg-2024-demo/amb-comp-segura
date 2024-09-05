#!/bin/bash

echo "Removendo pasta image ..."
rm -rf image/

echo "Executando copy_bom"
copy_bom -f ../app-occlum.yaml --root image --include-dir /opt/occlum/etc/template

echo "occlum build"
occlum build --sgx-mode SIM
