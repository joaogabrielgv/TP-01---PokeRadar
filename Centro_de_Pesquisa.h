#ifndef CENTRO_DE_PESQUISA_H
#define CENTRO_DE_PESQUISA_H

#include "Treinador.h"

// TAD 4 - CENTRO DE PESQUISA (HEADER) 

typedef struct {
    int x;
    int y;
} Coordenadac;

typedef struct {
    Coordenadac localizacaoc;
    PokeLista fugitivos;
    PokeLista recuperados;
} CentroPesquisa;

void centro_inicializar (CentroPesquisa *c);

int centro_insercao_fugitivos (CentroPesquisa *c, Pokemon *p);

int centro_remover_fugitivos (CentroPesquisa *c, Pokemon *p);

void centro_imprimir_fugitivos (const CentroPesquisa *c);

int centro_recebimento_recuperados (CentroPesquisa *c, Pokemon *p);

void centro_recarga_pokebolas (Treinador *t);

#endif