#pragma once
#include "Posicao.h"


#define MACA_CHAR '@'

typedef struct MACA {
	POSICAO *posicao;
}MACA;

void * criaMaca();

void imprimeMaca(MACA * maca);

void atualizaMaca(MACA * maca);

void * sorteiaMaca();

BOOL verificaMaca(char objeto);
