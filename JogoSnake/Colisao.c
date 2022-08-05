#include <Windows.h>
#include "Colisao.h"
#include "Posicao.h"
#include "Mapa.h"
#include "Maca.h"

char verificaObstaculo(POSICAO *posicao, DIRECAO *direcao) {
	int novaPosX = posicao->posX + direcao->incrementaX;
	int novaPosY = posicao->posY + direcao->incrementaY;

	return lerCaractereDaTela(novaPosX, novaPosY);
}

BOOL verificarColisao(char objeto) {

	return (objeto != ESPACO_VAZIO && objeto != MACA_CHAR);

}