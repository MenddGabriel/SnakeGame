#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "Menu.h"
#include "Tela.h"
#include "Cores.h"
#include "Teclas.h"

/* arte em bits */
int arteSnake[5][8] = { {4080, 12300, 12300, 240, 3840, 12300, 12300, 4080},	/* Letra S */
			{64575,12300,12348,12492,13068,15372,12300,64575},	/* Letra N */
			{960,3120,12300,12300,16380,12300,12300,64575},		/* Letra A */
			{15612,3120,816,240,816,3120,12336,61692},		/* Letra K */
			{16380,12336,48,4080,48,48,12336,16380} };		/* Letra E */


void menu() {

	limpaTela();

	int tecla;
	imprimeBordasDoMenu();
	imprimePalavraSnake();
	int opcao = selecionaOpcao();

	switch (opcao) {
	case 1:
		limpaTela();
		jogar();
		do {
			if (_kbhit) { tecla = teclaPrecionada(); }
		} while (tecla != KEY_ESC);
		break;
	case 2:
		limpaTela();
		printf("AQUI E O RANKING!");
		//ranking();
		do {
			if (_kbhit) { tecla = teclaPrecionada(); }
		} while (tecla != KEY_ESC);
		break;
	case 3:
		posicionaCursorNaTela(NULL, 0, 39);
		printf("Voce pediu para sair, fechando programa...");
		for (tecla = 0; tecla < 10; tecla++) {
			printf(".");
			Sleep(300);
		}
		printf("!\n\n");
		exit(0);
	default:
		break;
	}
	menu();
}

int selecionaOpcao() {

	int tecla;
	int select = 0;
	int selectInicial = select;
	int selectAtual = select;
	int selectFinal = select + 2;

	/* loop para movimentar o menu */
	while (TRUE) {
		imprimeBotoesDoMenu(select);
		reposicionaCursorNoFinal();

		if (_kbhit) { tecla = teclaPrecionada(); }

		if (tecla == ARROW_DOWN) { /* seta p/baixo */
			selectAtual = select;
			select++;
			if (select > selectFinal) { select = selectInicial; }
		}

		if (tecla == ARROW_UP) { /* seta p/cima */
			selectAtual = select;
			select--;
			if (select < selectInicial) { select = selectFinal; }
		}

		if (tecla == KEY_ENTER) { /* se a tecla enter for pressionada */
			return select - (selectInicial - 1);
		}
	}
}


void imprimeBotoesDoMenu(int selecionado) {

	int  botoes = 3;
	int i, n;
	int comprimentoInicial = 67, comprimentoFinal = 87; /* tamanho do botao */
	int alturaInicial = 19, alturaMeio = 20, alturaFinal = 21;

	for (n = 0; n < botoes; n++) {

		for (i = comprimentoInicial; i < comprimentoFinal; i++) {
			posicionaCursorNaTela(NULL, i, alturaInicial);
			printf("%c", n == selecionado ? 205 : 196); /* ═ ou ─ */
			posicionaCursorNaTela(NULL, i, alturaMeio);
			printf("%c", n == selecionado ? 176 : ' '); /* ░ ou ' '*/
			posicionaCursorNaTela(NULL, i, alturaFinal);
			printf("%c", n == selecionado ? 205 : 196); /* ═ ou ─*/
		}

		posicionaCursorNaTela(NULL, comprimentoInicial - 1, alturaInicial);
		printf("%c", n == selecionado ? 201 : 218); /* ╔ ou ┌ */
		posicionaCursorNaTela(NULL, comprimentoInicial - 1, alturaMeio);
		printf("%c", n == selecionado ? 186 : 179); /* ║ ou │ */
		posicionaCursorNaTela(NULL, comprimentoInicial - 1, alturaFinal);
		printf("%c", n == selecionado ? 200 : 192); /* ╚ ou └*/

		posicionaCursorNaTela(NULL, comprimentoFinal, alturaInicial);
		printf("%c", n == selecionado ? 187 : 191); /* ╗ ou ┐ */
		posicionaCursorNaTela(NULL, comprimentoFinal, alturaMeio);
		printf("%c", n == selecionado ? 186 : 179); /* ║ ou │*/
		posicionaCursorNaTela(NULL, comprimentoFinal, alturaFinal);
		printf("%c", n == selecionado ? 188 : 217); /* ╝ ou ┘*/


		if (n == 0) { posicionaCursorNaTela(NULL, 74, alturaMeio); printf("JOGAR"); }
		else if (n == 1) { posicionaCursorNaTela(NULL, 73, alturaMeio); printf("RANKING"); }
		else { posicionaCursorNaTela(NULL, 75, alturaMeio); printf("SAIR"); }

		alturaInicial += 3; alturaMeio += 3; alturaFinal += 3;
	}
}

void imprimeBordasDoMenu() {

	int i;
	int bordaSuperior = 1;
	int bordaInferior = 38;
	int bordaEsquerda = 4;
	int bordaDireita = 145;

	for (i = bordaSuperior + 1; i < bordaInferior; i++) { /* para imprimir as bordas esquerda e direita */
		posicionaCursorNaTela(186, bordaEsquerda, i); //printf("%c", 186); /* ║ */
		posicionaCursorNaTela(186, bordaDireita, i); //printf("%c", 186); /* ║ */
	}
	for (i = bordaEsquerda + 1; i < bordaDireita; i++) {  /* para imprimir as bordas superiores e inferiores */
		posicionaCursorNaTela(205, i, bordaSuperior); //printf("%c", 205); /* ═ */
		posicionaCursorNaTela(205, i, bordaInferior); //printf("%c", 205); /* ═ */
	}
	posicionaCursorNaTela(201, bordaEsquerda, bordaSuperior); //printf("%c", 201); /* ╔ */
	posicionaCursorNaTela(200, bordaEsquerda, bordaInferior); //printf("%c", 200); /* ╚ */
	posicionaCursorNaTela(187, bordaDireita, bordaSuperior); //printf("%c", 187); /* ╗ */
	posicionaCursorNaTela(188, bordaDireita, bordaInferior); //printf("%c", 188); /* ╝ */

}

void imprimePalavraSnake() {

	int tamanhoDaLetraEmBits = 16;
	int numeroDeLetras = 5;
	int linha = 34;
	int coluna = 7;
	int linhaInicial = linha;
	int colunaInicial = coluna;
	int nLetra, b, j, c, i;

	for (nLetra = 0; nLetra < numeroDeLetras; nLetra++) { /* Cinco de letras */

		if (nLetra == 2) { linha = linha + 2; }

		for (j = 0; j < 8; j++) { /* O caractere e de 8 linhas */

			posicionaCursorNaTela(NULL, linha, coluna);
			c = arteSnake[nLetra][j];

			for (b = 0; b < tamanhoDaLetraEmBits; b++) { /* 16 bits */

				if (c % 2) { /* Se bit=1 coloca espaço invertido se não coloca espaço normal */
					printf(ANSI_COLOR_AZUL "%c" ANSI_COLOR_RESET, 219);/* █ */
				}
				else {
					printf(" ");
				}
				c = c / 2;
			}
			coluna++;
		}
		linha = linha + 16;
		coluna = colunaInicial;
	}

	printf(ANSI_COLOR_AZUL " %c" ANSI_COLOR_RESET, 'R');

}
