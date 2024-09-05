# Passos para demonstração

1) Criar o ambiente python (se já tiver feito, proseguir para o próximo passo)

    ``
    python3 -m venv venv
    ``

2) Ativar o ambiente python

    ``
    source venv/bin/activate
    ``

3) Instalar dependências (se já tiver feito, proseguir para o próximo passo)

    ``
    pip install -r requirements.txt
    ``

4) Executar o Database MongoDB

    ``
    docker run -d --rm --network host --name mongo-vitima  \
        -v ./mongo.init.js:/docker-entrypoint-initdb.d/mongo.init.js \
        -e MONGO_INITDB_ROOT_USERNAME=root \
        -e MONGO_INITDB_ROOT_PASSWORD=abcdef \
        mongo:6.0.14
    ``

5) Executar o servidor de testes

    ``
    python vitima.py
    ``

6) Realizar o dump de memória com o script disponibilizado. É necessário executar como **root**.

    O script realizará uma tentativa de autenticação com hash incorreto,  mas usando um dos usuário cadastrados: asilva, rmello ou gborges.
    No caso, será utilizado o usuário asilva.

    ``
    sudo ./dump-vitima.sh
    ``


Após esse passo, estarão disponíveis arquivos contendo os dados da memória RAM do programa.

Buscas podem ser realizadas utilizando ferramentas como o "Hex Edit" para Windows ou outro.

Observações:

- Pelo fato dos dados do usuário serem carregados em variáveis atreladas ao call stack, nem sempre é possível obter a informação confidencial;

- Por vezes, é preciso repetir a execução para obter os dados.