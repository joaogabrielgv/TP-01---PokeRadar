#ifndef POKELISTA_H
#define POKELISTA_H

#include "pokemons.h"

typedef struct Celula {
    Pokemon pokemon;
    struct Celula *pProx;
} PokeCelula;

typedef struct{
    struct Celula *pPrimeiro;
    struct Celula *pUltimo;
}PokeLista;

void pokelista_inicializar(PokeLista *lista);

void pokelista_inserir(PokeLista *lista, Pokemon* p);

int pokelista_remover(PokeLista *lista, Pokemon* p);

Pokemon* pokelista_buscar(PokeLista *lista, Pokemon *p); //busca por id, mas isso aqui ta considerando que vai encontrar o pokemon pelo id

void pokelista_imprimir(PokeLista *lista);

#endif
