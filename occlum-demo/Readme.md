# Instruções para rodar o programa App no Occlum

## Passos

1. Dentro da sub pasta ``occlum-demo``, executar a imagem docker por meio do comando:

    ```
    docker run -it -v ./:/root/occlum-demo \
        --device=/dev/sgx_enclave:/dev/sgx/enclave \
        --device=/dev/sgx_provision:/dev/sgx/provision \
        occlum/occlum:0.30.1-rc-ubuntu20.04 \
        bash
    ```

    Aguardar um pouco e pressionar a tecla ENTER para liberar o terminal.


2. Dentro do container, acessar a pasta ``/root/occlum-demo`` e criar um workspace do occlum por meio do comando:

    ```
    cd occlum-demo
    occlum new occlum-workspace
    ```

3. Acessar a pasta ``occlum-workspace`` recém criada e executar o comando dependendo da experimentação a ser realizada:

    - Versão simulação (desprotegida):
    ``../compile-SIM.sh``

    - Versão hardware (utiliza SGX):
    ``../compile-HW.sh``

4. Abrir um novo terminal na máquina (**B**) e acessar a pasta ``occlum-demo``:

    ``cd occlum-demo``


5. No terminal **A**, executar o programa ``app`` dentro do enclave criado pelo occlum por meio do comando:

    ``occlum run /bin/app``

6. Antes que o programa finalize a executação, no terminal **B**, executar o programa ``dump.sh``:

    ``./dump.sh``

    Um arquivo de dump será gerado na pasta corrente.


