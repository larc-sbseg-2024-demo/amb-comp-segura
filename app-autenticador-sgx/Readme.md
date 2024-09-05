# Programa Autenticador C++

## Observações Gerais
Criado a partir de um exemplo fornecido pela Intel.

Antes de compilar, é necessário ter instalado o SGX SDK.

Neste exemplo, o sdk utilizado foi o: ``sgx_linux_x64_sdk_2.24.100.3.bin``

Dicas de instalação do SDK:

- Instalar como **root**

- Ao instalar, quando o instalador perguntar em qual pasta instalar, indicar: ``/opt/intel``

Dica de utilização:

- Executar ``source /opt/intel/sgxsdk/environment`` para carregar as variáveis de ambiente necessárias para que o make funcione corretamente.

## Compilando o autenticador

Para compilar a versão de simulador (sem proteção SGX), executar:

```
make clean
make SGX_MODE=SIM SGX_DEBUG=0
```

Para compilar a versão que utiliza SGX, executar:

```
make clean
make SGX_PRERELEASE=1 SGX_DEBUG=0
```

Obs.: ``SGX_PRERELEASE`` significa que o hardware SGX deve ser utilizado, contudo uma chave para assinar não é necessária.