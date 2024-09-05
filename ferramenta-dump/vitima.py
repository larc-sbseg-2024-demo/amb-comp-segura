# Programa de demonstração de vítima
#
# Esse programa mimetiza o carregamento (load) de dados de um database na memória RAM
# para manipulação e/ou comparação.
#
# Em dado instante que existem dados na memória, há a ocorrência de um ataque (dump)
# para obtenção de informações confidenciais (usuário) e seu hash

from db import ConexaoDB
#from fastapi import FastAPI
from flask import Flask

app = Flask(__name__)

conexao = ConexaoDB()

@app.route("/", methods=['POST', 'GET'])
def read_root():
    return {"Hello": "World"}


@app.route("/autenticar/<usuario>/<hash>", methods=['POST', 'GET'])
def read_item(usuario, hash):
    global conexao
    usuarioVO = conexao.obter_usuario(usuario)
    #print(f'Autenticando usuário: {usuarioVO}')
    return {"Sucesso": f'{usuarioVO["hash"] == hash}'}


if __name__ == '__main__':
    app.run(debug=False, host='0.0.0.0')

