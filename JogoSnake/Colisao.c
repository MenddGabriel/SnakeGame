#include <windows.h>
#include "Colisao.h"
#include "Posicao.h"

char verificaObstaculo(POSICAO *posicao, DIRECAO *direcao) {
	int novaPosX = posicao->posX + direcao->incrementaX;
	int novaPosY = posicao->posY + direcao->incrementaY;

	return lerCaractereDaTela(novaPosX, novaPosY);
}

BOOL verificarColisao(char cabecaSnake) {

	return (cabecaSnake != ' ' && cabecaSnake != '@');

}