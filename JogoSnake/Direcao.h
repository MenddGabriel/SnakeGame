#pragma once

typedef struct DIRECAO {
	int incrementaX;
	int incrementaY;
}DIRECAO;

DIRECAO *criaDirecao();
void atualizaDirecao(int tecla, DIRECAO *direcao);