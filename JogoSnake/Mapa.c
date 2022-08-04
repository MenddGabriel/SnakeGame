#include "Mapa.h"

void iniciaMapa() {

	int i;
	int bordaSuperior = 2;
	int bordaInferior = 38;
	int bordaEsquerda = 4;
	int bordaDireita = 145;

	for (i = bordaSuperior; i <= bordaInferior; i++) {
		gotoxy(219, bordaEsquerda, i);
		gotoxy(219, bordaEsquerda - 1, i);
		gotoxy(219, bordaDireita, i);
		gotoxy(219, bordaDireita + 1, i);

	}

	for (i = bordaEsquerda; i <= bordaDireita; i++) {
		gotoxy(219, i, bordaSuperior);
		gotoxy(219, i, bordaInferior);
	}

	reposicionaCursor();
}