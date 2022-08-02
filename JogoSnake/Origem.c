#include <stdio.h>
#include "Tela.h"
#include "Menu.h"
#include "Teclas.h"
#include "Cores.h"

int main() {

	redimensionaJanela(LARGURA_TELA, ALTURA_TELA);
	menu();



	_getch();
	return 0;

}