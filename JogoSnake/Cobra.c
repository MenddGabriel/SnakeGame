#include <Windows.h>
#include "Cobra.h"
#include "Tela.h"
#include "Mapa.h"
#include "Cores.h"

COBRA *criaCobra() {
	
	int xInicial = 35;
	int yInicial = 20;

	COBRA *cobra = (COBRA*)malloc(sizeof(COBRA));
	cobra->cabeca = (POSICAO*)malloc(sizeof(POSICAO));
	cobra->cabeca->objeto = COBRA_CABECA;
	cobra->cabeca->proximo = NULL;
	cobra->cabeca->posX = xInicial;
	cobra->cabeca->posY = yInicial; 
	cobra->final = cobra->cabeca;
	cobra->direcao = criaDirecao();
	cobra->direcao->incrementaX = 2;
	cobra->direcao->incrementaY = 0;

	return cobra;
}

void imprimeCobra(COBRA *cobra) {
	POSICAO *posicao = cobra->final;

	while (posicao != NULL) {
		posicionaCursorNaTela(posicao->objeto, posicao->posX, posicao->posY);

		posicao = posicao->proximo;
	}
}

void atualizaCobra(COBRA *cobra) {
	POSICAO *fim = cobra->final;
	POSICAO *cab = cobra->cabeca;
	int i;

	for (i = 0; i < 2; i++) {
		posicionaCursorNaTela(NULL, cab->posX + i, cab->posY);
		printf(ANSI_COLOR_VERDE "%c" ANSI_COLOR_RESET, COBRA_CORPO);

		posicionaCursorNaTela(NULL, fim->posX + i, fim->posY);
		printf(ANSI_COLOR_VERDE "%c" ANSI_COLOR_RESET, ESPACO_VAZIO);
	}

	while (fim != NULL) {
		
		if (fim->proximo != NULL) {
			fim->posX = fim->proximo->posX;
			fim->posY = fim->proximo->posY;
		}
		fim = fim->proximo;
	}

	cab->posX += cobra->direcao->incrementaX;
	cab->posY += cobra->direcao->incrementaY;

	for (i = 0; i < 2; i++) {
		posicionaCursorNaTela(NULL, cab->posX + i, cab->posY);
		printf(ANSI_COLOR_VERDE "%c" ANSI_COLOR_RESET, cab->objeto);
	}

}

void alimentaCobra(COBRA *cobra) {

	POSICAO *fim = cobra->final;
	POSICAO *novo = (POSICAO*)malloc(sizeof(POSICAO));

	novo->posX = fim->posX;
	novo->posY = fim->posY;
	novo->objeto = COBRA_CORPO;
	novo->proximo = fim;

	cobra->final = novo;

}