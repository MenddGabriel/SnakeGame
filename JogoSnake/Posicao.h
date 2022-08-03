#pragma once
#include "Direcao.h"

typedef struct POSICAO {
	int posX;
	int posY;
}POSICAO;

POSICAO *criaPosicao();
void atualizaPosicaoSnake(POSICAO *posicao, DIRECAO *direcao);