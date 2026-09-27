#ifndef TREINADOR_H
#define TREINADOR_H

#include "Pokelista.h"

typedef struct {
    int x;
    int y;
} Coordenadat;

typedef struct {
    int id;
    char nome [20];
    Coordenadat localizacaot;
    PokeLista poke_treinador;
    int pokebolas;
} Treinador;

void treinador_inicializar (Treinador *t, int id, int pokebolas);

void treinador_movimentacao (Treinador *t, int x, int y);

int treinador_capturar_pokemon (Treinador *t, Pokemon *p);

int treinador_remover_pokemon (Treinador *t, Pokemon *p);

void treinador_imprimir (const Treinador *t);

#endif