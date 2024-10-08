# Programas de Demonstração do minicurso "Ambientes de Computação Segura" - SBSeg 2024

A seguir estão as instruções básicas para as demonstrações com ataques de 'dump' realizadas no minicurso.

Os slides apresentados estão disponíveis no arquivo: [Minicurso-SBSeg2024-Apresentado.pdf](Minicurso-SBSeg2024-Apresentado.pdf)

## Preparação

Inicialmente, verificar se possui o programa ``gcore`` instalado.
Ele será utilizado em todas demonstrações.

Caso não possua, no Ubuntu é possível instalar por meio do comando:

```    
sudo apt install gdb
```

Também será necessário possuir o Docker instalado [Instalar Docker](https://docs.docker.com/engine/install/).

## Organização

Dentro de cada uma das pastas há uma demonstração.

Para as demonstrações ``app-autenticador-sgx`` e ``occlum-demo`` será necessária a utilização de uma máquina com processador Intel que possua as instruções **SGX** e, também, **FLC**.