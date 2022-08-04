#pragma once

#define ALTURA_TELA 40
#define LARGURA_TELA 150

void reposicionaCursor();
void gotoxy(char c, int x, int y);
char lerCaractereDaTela(int x, int y);
void limpaTela();
void redimensionaJanela(int Width, int Height);