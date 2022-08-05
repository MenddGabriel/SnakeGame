#include <windows.h>
#include <stdio.h>

#include "Posicao.h"
#include "Direcao.h"
#include "Cores.h"
#include "Tela.h"
#include "Colisao.h"
#include "Mapa.h"


POSICAO *criaPosicao() {

	POSICAO *posicao = (POSICAO*)malloc(sizeof(POSICAO));
	
	posicao->proximo = NULL;
	
	return posicao;
}

POSICAO *sorteiaPosicao(DIRECAO *direcao) {
	POSICAO *posicao = (POSICAO*)malloc(sizeof(POSICAO));
	posicao->proximo = NULL;

	do {
		int x = 5 + rand() % 136;
		int y = 3 + rand() % 34;
		if (x % 2 == 0) {
			x++;
		}

		posicao->posX = x;
		posicao->posY = y;

	} while (verificaObstaculo(posicao, direcao) != ESPACO_VAZIO);

	return posicao;
}

void atualizaPosicaoSnake(POSICAO *posicao, DIRECAO *direcao) {

	int x = posicao->posX += direcao->incrementaX;
	int y = posicao->posY += direcao->incrementaY;
	int apaga_x = x;
	int apaga_y = y;

	posicionaCursorNaTela(NULL, x, y);

	printf(ANSI_COLOR_VERDE "%c%c" ANSI_COLOR_RESET, 219, 219);
	reposicionaCursorNoFinal();

	Sleep(40);

	posicionaCursorNaTela(NULL,x, y);
	printf("  ");

}

