# Instruções para rodar o programa no Open Enclave SDK

## Instalação

Antes de começar, primeiramente é preciso ter instalado o Open Enclave SDK.

Para isso, basta seguir as instruções do fabricante, disponíveis em:
[https://github.com/openenclave/openenclave/blob/master/docs/GettingStartedDocs/install_oe_sdk-Ubuntu_20.04.md](https://github.com/openenclave/openenclave/blob/master/docs/GettingStartedDocs/install_oe_sdk-Ubuntu_20.04.md)

Também será necessário instalar o ``make`` e o ``gcc``. Que pode ser feito por meio do comando:

```
sudo apt install gcc make
```

Após, executar o comando abaixo para configurar as variáveis de ambiente:

```
source /opt/openenclave/share/openenclave/openenclaverc
```

## Compilação do programa

Para compilar o programa de demonstração, executar o comando:

```
make build
```

## Passos para a demonstração

1. Uma vez que o programa está compilado, ele pode ser executado tanto no modo de simualção (desprotegido) como no modo SGX (usando a proteção de hardware).
No terminal corrente (chamado de terminal **A**), executar o programa.

    Para executar o programa no modo simulação, ou seja, sem efetivamente utilizar a proteção SGX, executar o comando:

    ```
    ./host/autenticador_host ./enclave/enclave.signed --simulate
    ```

    Para executar o programa utilizando a proteção SGX, executar o comando:

    ```
    ./host/autenticador_host ./enclave/enclave.signed
    ```

2. Antes que o programa termine a execução, dentro de um novo terminal na mesma pasta da execução (passo anterior), executar o comando ``dump.sh`` como usuário ``root``:

    ```
    sudo ./dump.sh
    ```

    Ao final do comando será gerado um arquivo de dump.