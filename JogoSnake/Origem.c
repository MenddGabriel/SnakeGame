#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>


#include "Tela.h"
#include "Menu.h"
#include "Teclas.h"
#include "Direcao.h"
#include "Posicao.h"
#include "Mapa.h"
#include "Colisao.h"
#include "Maca.h"


void jogar() {

	iniciaMapa();
	DIRECAO *direcao = criaDirecao();
	POSICAO *cobraPosicao = sorteiaPosicao(direcao);
	MACA *maca = criaMaca();

	atualizaMaca(maca);


	int tecla = teclaPrecionada;
	while (tecla != KEY_ESC) {

		if (_kbhit()) {
			tecla = teclaPrecionada();
			atualizaDirecao(tecla, direcao);
		}

		char cabecaColisao = verificaObstaculo(cobraPosicao, direcao);

		if (verificarColisao(cabecaColisao)) {
			break;
		}
		
		if (verificaMaca(cabecaColisao)) {
			atualizaMaca(maca);
		}


			atualizaPosicaoSnake(cobraPosicao, direcao);
		


	}

	posicionaCursorNaTela(NULL, 0, 39);
	printf("Ocorreu uma colisao!");
}


int main() {

	redimensionaJanela(LARGURA_TELA, ALTURA_TELA);
	srand(time(NULL));
	menu();





	_getch();
	return 0;

}
