#include "Mapa.h"

void iniciaMapa() {

	int i;
	int bordaSuperior = 2;
	int bordaInferior = 38;
	int bordaEsquerda = 4;
	int bordaDireita = 145;

	for (i = bordaSuperior; i < bordaInferior; i++) {
		gotoxy(bordaEsquerda, i); printf("%c", 219); /* █ */
		gotoxy(bordaDireita, i); printf("%c", 219); /* █ */

	}

	for (i = bordaEsquerda; i <= bordaDireita; i++) {
		gotoxy(i, bordaSuperior); printf("%c", 220); /* ▄ */
		gotoxy(i, bordaInferior); printf("%c", 223); /* ▀ */
	}

	reposicionaCursor();
}