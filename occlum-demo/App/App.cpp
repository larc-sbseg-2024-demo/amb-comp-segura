/*
 * Autenticacao.cpp
 *
 *  Created on: Mar 12, 2024
 *      Author: devel
 */
#include "Autenticacao.h"
#include <cstdio>
#include <unistd.h>


int main(int argc, char *argv[]) {
    /* Resultado */
    int resultado = -1;

    printf("Realizando autenticação ...\n");
    autenticar("joao", "hash-12345678", &resultado);

    printf("Resultado da autenticação: %d\n", resultado);

    sleep(10);
    return 0;
}





