#include "Direcao.h"
#include "Teclas.h"


DIRECAO *criaDirecao() {

	DIRECAO *direcao = (DIRECAO*)malloc(sizeof(DIRECAO));

	direcao->incrementaX = 0;
	direcao->incrementaY = 0;

	return direcao;

}

void atualizaDirecao(int tecla, DIRECAO *direcao) {

	switch ((int)tecla)
	{
	case ARROW_UP:
		if (direcao->incrementaY > 0)
			return;
		direcao->incrementaX = 0;
		direcao->incrementaY = -1;
		break;
	case ARROW_DOWN:
		if (direcao->incrementaY < 0)
			return;
		direcao->incrementaX = 0;
		direcao->incrementaY = 1;
		break;
	case ARROW_LEFT:
		if (direcao->incrementaX > 0)
			return;
		direcao->incrementaX = -2;
		direcao->incrementaY = 0;
		break;
	case ARROW_RIGHT:
		if (direcao->incrementaX < 0)
			return;
		direcao->incrementaX = +2;
		direcao->incrementaY = 0;
		break;
	}
}