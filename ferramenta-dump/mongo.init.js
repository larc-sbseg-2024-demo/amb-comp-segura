db = connect( 'mongodb://localhost/autenticador' );

db.createUser(
  {
    user: "autenticadorUser",
    pwd: "asdQWE!", 
    roles: [ { role: "readWrite", db: "autenticador" }]
  }
);


db.createCollection('usuarios');

db.usuarios.insertMany([
 {
    usuario: 'asilva',
    hash: '3002c2b042cd33a1dc9b123bcbb9850c64981e60', // Minha senha super secreta
  },
  {
    usuario: 'rmello',
    hash: '659f7c26d9c29aed29b35032083e99471f506d49', // Absurdo
  },
  {
    usuario: 'gborges',
    hash: '2f7a8ecd3cb8685f3785a99f994ede9e0dddf998', // agorasim
  }  
]);
