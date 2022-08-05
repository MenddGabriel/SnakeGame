#include "Mapa.h"

void iniciaMapa() {

	int i;
	int bordaSuperior = 2;
	int bordaInferior = 38;
	int bordaEsquerda = 4;
	int bordaDireita = 145;

	/* imprime as bordas inferior e superior do mapa */
	for (i = bordaSuperior; i <= bordaInferior; i++) {
		posicionaCursorNaTela(PAREDE, bordaEsquerda, i);
		posicionaCursorNaTela(PAREDE, bordaEsquerda - 1, i);
		posicionaCursorNaTela(PAREDE, bordaDireita, i);
		posicionaCursorNaTela(PAREDE, bordaDireita + 1, i);

	}

	/* imprime as bordas esquerda e direita do mapa */
	for (i = bordaEsquerda; i <= bordaDireita; i++) {
		posicionaCursorNaTela(PAREDE, i, bordaSuperior);
		posicionaCursorNaTela(PAREDE, i, bordaInferior);
	}

	reposicionaCursorNoFinal();
}