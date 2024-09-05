/*
 * Autenticacao.cpp
 *
 *  Created on: Mar 12, 2024
 *      Author: devel
 */
#include "../App.h"
#include "Enclave_u.h"
#include <unistd.h>


void ecall_autenticacao_functions(void) {
    /* Resultado */
    int resultado = -1;
    sgx_status_t ret = SGX_ERROR_UNEXPECTED;

    printf("Realizando autenticação ...\n");
    ret = ecall_sgx_autenticar(global_eid, "joao", "hash-12345678", &resultado);
    if (ret != SGX_SUCCESS)
    	abort();

    printf("Resultado da autenticação: %d\n", resultado);
}


void ocall_autenticacao_sleep(unsigned int seconds){
	sleep(seconds);
}




