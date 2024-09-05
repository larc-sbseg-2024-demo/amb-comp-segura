/*
 * Autenticacao.cpp
 *
 *  Created on: Mar 12, 2024
 *      Author: devel
 */
#include "Autenticacao.h"
#include <string.h>

const int USUARIOS = 3;
const char* usuarios[3] = {"joao", "marcela", "renata"};
const char* hashes[3] = {"hash-12345678", "hash-abcde678", "hash-12354abced"};


void autenticar(const char* usuario, const char* senhaHash, int* resultado){
	*resultado = -4;
	int indice=0;

	while(*resultado != 0 && indice < USUARIOS){
		if (strcmp(usuario, usuarios[indice]) == 0){
			*resultado = strcmp(senhaHash, hashes[indice]);
		}//if
		indice++;
	}//while

	return;
}

