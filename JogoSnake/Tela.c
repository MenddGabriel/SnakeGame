#include <Windows.h>

#include "Tela.h"

void reposicionaCursor() {
	gotoxy(149, 39);
}

void gotoxy(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/* LIMPA O CONSOLE */
void limpaTela() {

	DWORD n;  						/* N�mero de caracteres escritos */
	DWORD size;						/* n�mero de caracteres vis�veis */
	COORD coord = { 0, 0 };			/* Posi��o superior esquerda da tela */
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	/* Obter um identificador para o console */
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(h, &csbi);

	/* Encontre o n�mero de caracteres a serem sobrescritos */
	size = csbi.dwSize.X * csbi.dwSize.Y;

	/* Sobrescrever o buffer de tela com espa�os em branco */
	FillConsoleOutputCharacter(h, TEXT(' '), size, coord, &n);
	GetConsoleScreenBufferInfo(h, &csbi);
	FillConsoleOutputAttribute(h, csbi.wAttributes, size, coord, &n);

	/* Redefine o cursor para a posi��o superior esquerda */
	SetConsoleCursorPosition(h, coord);

}

/* TAMANHO DO CONSOLE */
void redimensionaJanela(int Width, int Height)
{
	COORD coord;
	coord.X = Width;
	coord.Y = Height;

	SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}