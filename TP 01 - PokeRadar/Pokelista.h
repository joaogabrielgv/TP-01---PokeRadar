#ifndef POKELISTA_H
#define POKELISTA_H

#include "Pokemons.h"

typedef struct Celula {
    Pokemon pokemon;
    struct Celula *pProx;
} PokeCelula;

typedef struct{
    struct Celula *pPrimeiro;
    struct Celula *pUltimo;
}PokeLista;

void pokelista_inicializar(PokeLista *lista);

int pokelista_inserir(PokeLista *lista, Pokemon* p);

int pokelista_remover(PokeLista *lista, Pokemon* p);

Pokemon* pokelista_buscar(PokeLista *lista, int id);

void pokelista_imprimir(PokeLista *lista);

#endif
