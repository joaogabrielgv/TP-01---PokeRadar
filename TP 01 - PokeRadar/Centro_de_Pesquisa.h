#ifndef CENTRO_DE_PESQUISA_H
#define CENTRO_DE_PESQUISA_H

#include "Treinador.h"

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

void centro_insercao_fugitivos (CentroPesquisa *c, Pokemon p);

void centro_remover_fugitivos (CentroPesquisa *c, int id); 

void centro_imprimir_fugitivos (const CentroPesquisa *c);

void centro_recebimento_recuperados (CentroPesquisa *c, Pokemon p);

void centro_recarga_pokebolas (Treinador *t);

#endif