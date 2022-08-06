#include <stdio.h>
#include <windows.h>
#include "Maca.h"
#include "Posicao.h"
#include "Tela.h"
#include "Cores.h"

void * criaMaca() {
	MACA *maca = (MACA*)malloc(sizeof(MACA));
	maca->posicao = (POSICAO*)malloc(sizeof(POSICAO));
	maca->posicao->objeto = MACA_CHAR;
	maca->posicao->proximo = NULL;

	return maca;
}

void imprimeMaca(MACA *maca) {
	POSICAO *posicao = maca->posicao;
	posicionaCursorNaTela(NULL, posicao->posX, posicao->posY);
	printf(ANSI_COLOR_RED "%c" ANSI_COLOR_RESET, posicao->objeto);
}

void atualizaMaca(MACA *maca) {

	maca = sorteiaMaca();

	imprimeMaca(maca);

}

void * sorteiaMaca() {
	MACA *maca = criaMaca();
	DIRECAO *direcao = criaDirecao();
	maca->posicao = sorteiaPosicao(direcao);
	maca->posicao->objeto = MACA_CHAR;

	return maca;
}

BOOL verificaMaca(char objeto) {
	return (objeto == MACA_CHAR);
}