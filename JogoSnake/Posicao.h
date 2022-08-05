#pragma once
#include "Direcao.h"

typedef struct POSICAO {
	char objeto;

	int posX;
	int posY;
	struct POSICAO *proximo;
}POSICAO;

POSICAO *criaPosicao();
POSICAO *sorteiaPosicao(DIRECAO *direcao);
void atualizaPosicaoSnake(POSICAO *posicao, DIRECAO *direcao);