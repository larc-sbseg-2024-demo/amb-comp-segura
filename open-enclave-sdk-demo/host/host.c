// Copyright (c) Open Enclave SDK contributors.
// Licensed under the MIT License.

#include <openenclave/host.h>
#include <stdio.h>
#include <unistd.h>

// Include the untrusted autenticador header that is generated
// during the build. This file is generated by calling the
// sdk tool oeedger8r against the autenticador.edl file.
#include "autenticador_u.h"

bool check_simulate_opt(int* argc, const char* argv[])
{
    for (int i = 0; i < *argc; i++)
    {
        if (strcmp(argv[i], "--simulate") == 0)
        {
            fprintf(stdout, "Running in simulation mode\n");
            memmove(&argv[i], &argv[i + 1], (*argc - i) * sizeof(char*));
            (*argc)--;
            return true;
        }
    }
    return false;
}

// Funcao oferecida ao enclave para aguardar pelo tempo especificado em segundos.
void host_sleep(unsigned int segundos)
{
    fprintf(stdout, "Aguardando %d segundos...\n", segundos);
    sleep(segundos);
}

// Funcao principal do programa (cria o enclave e tenta autenticar um usuario)
int main(int argc, const char* argv[])
{
    oe_result_t result;
    int ret = 1;
    oe_enclave_t* enclave = NULL;

    uint32_t flags = OE_ENCLAVE_FLAG_DEBUG;
    if (check_simulate_opt(&argc, argv))
    {
        flags |= OE_ENCLAVE_FLAG_SIMULATE;
    }

    if (argc != 2)
    {
        fprintf(
            stderr, "Usage: %s enclave_image_path [ --simulate  ]\n", argv[0]);
        goto exit;
    }

    // Create the enclave
    result = oe_create_autenticador_enclave(
        argv[1], OE_ENCLAVE_TYPE_AUTO, flags, NULL, 0, &enclave);
    if (result != OE_OK)
    {
        fprintf(
            stderr,
            "oe_create_autenticador_enclave(): result=%u (%s)\n",
            result,
            oe_result_str(result));
        goto exit;
    }

    // Call into the enclave
    int resultado = -1;
    result = enclave_autenticar(enclave, "joao", "hash-incorreto", &resultado);
    if (result == OE_OK){
        fprintf(stdout,"Resultado da autenticação: %d\n", resultado);
    }else{
        fprintf(
            stderr,
            "calling into enclave_autenticar failed: result=%u (%s)\n",
            result,
            oe_result_str(result));
        goto exit;
    }

    ret = 0;

exit:
    // Clean up the enclave if we created one
    if (enclave)
        oe_terminate_enclave(enclave);

    return ret;
}
