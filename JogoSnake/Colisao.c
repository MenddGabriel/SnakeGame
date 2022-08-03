#include <windows.h>
#include "Colisao.h"
#include "Posicao.h"

BOOL verificarColisao(POSICAO *posicao) {

	if (posicao->posX > 5 && posicao->posX < 144 && posicao->posY > 2 && posicao->posY < 38) {
		return TRUE;
	}

	return FALSE;
}