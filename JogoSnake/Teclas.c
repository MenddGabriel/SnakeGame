#include "Teclas.h"

int teclaPrecionada() {
	int ch = _getch();
	if (ch == 0 || ch == 224)
		ch = _getch();
	return ch;
}