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
#include "Cobra.h"


void jogar() {

	iniciaMapa();
	COBRA *cobra = criaCobra();
	MACA *maca = criaMaca();

	imprimeCobra(cobra);
	atualizaMaca(maca);

	int tecla = teclaPrecionada;
	_getch();
	while (tecla != KEY_ESC) {

		if (_kbhit()) {
			tecla = teclaPrecionada();
			atualizaDirecao(tecla, cobra->direcao);
		}

		char cabecaColisao = verificaObstaculo(cobra->cabeca, cobra->direcao);

		if (verificarColisao(cabecaColisao)) {
			break;
		}
		
		if (verificaMaca(cabecaColisao)) {
			Beep(400, 100);
			alimentaCobra(cobra);
			atualizaMaca(maca);
		}

		atualizaCobra(cobra);
		reposicionaCursorNoFinal();
		Sleep(40);

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
