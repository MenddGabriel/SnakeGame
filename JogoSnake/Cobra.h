#pragma once

#include "Direcao.h"
#include "Posicao.h"

#define COBRA_CABECA 219
#define COBRA_CORPO 219

typedef struct COBRA {
	DIRECAO *direcao;
	POSICAO *final;
	POSICAO *cabeca;
} COBRA;

COBRA * criaCobra();

void imprimeCobra(COBRA * cobra);

void atualizaCobra(COBRA * cobra);

void alimentaCobra(COBRA * cobra);
