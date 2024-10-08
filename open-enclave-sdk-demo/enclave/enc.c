
#include <stdio.h>
#include <string.h>
#include "autenticador_t.h"

const int USUARIOS = 3;
const char* usuarios[3] = {"joao", "marcela", "renata"};
const char* hashes[3] = {"hash-12345678", "hash-abcde678", "hash-12354abced"};

// Funcao de autenticacao
void enclave_autenticar(const char* usuario, const char* senhaHash, int* resultado)
{
    //fprintf(stdout, "Usuario recebido: %s\n", usuario);

	*resultado = -4;
	int indice=0;

	while(*resultado != 0 && indice < USUARIOS){
		if (strcmp(usuario, usuarios[indice]) == 0){
			*resultado = strcmp(senhaHash, hashes[indice]);
		}//if
		indice++;
	}//while

    // Aguardar para facilitar captura
    oe_result_t result = host_sleep(10);
    if (result != OE_OK)
    {
        fprintf(
            stderr,
            "Call to host_sleep failed: result=%u (%s)\n",
            result,
            oe_result_str(result));
    }
}
