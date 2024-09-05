from pymongo import MongoClient

class ConexaoDB:

    def __init__(self):
        self.client = MongoClient('mongodb://autenticadorUser:asdQWE!@localhost/autenticador')
        self.collection = self.client['autenticador']['usuarios']


    def obter_usuario(self, usuario):
        usuarioObj = self.collection.find_one({"usuario":usuario})
        if usuarioObj:
            return usuarioObj
        
        return None

