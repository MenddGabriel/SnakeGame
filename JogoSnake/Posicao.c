#include <windows.h>
#include <stdio.h>

#include "Posicao.h"
#include "Direcao.h"
#include "Cores.h"
#include "Tela.h"


POSICAO *criaPosicao() {

	POSICAO *posicao = (POSICAO*)malloc(sizeof(POSICAO));
	
	int x = 5 + rand() % 136;
	int y = 3 + rand() % 34;
	if (x % 2 == 0) {
		x++;
	}
		
	posicao->posX = x;
	posicao->posY = y;

	return posicao;

}

void atualizaPosicaoSnake(POSICAO *posicao, DIRECAO *direcao) {

	int x = posicao->posX += direcao->incrementaX;
	int y = posicao->posY += direcao->incrementaY;
	int apaga_x = x;
	int apaga_y = y;

	gotoxy(NULL, x, y);

	printf(ANSI_COLOR_VERDE "%c%c" ANSI_COLOR_RESET, 219, 219);
	reposicionaCursor();

	Sleep(40);

	gotoxy(NULL,x, y);
	printf("  ");

}