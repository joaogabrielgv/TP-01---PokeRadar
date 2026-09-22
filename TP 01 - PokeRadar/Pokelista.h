#ifndef POKELISTA_H
#define POKELISTA_H

#include "pokemons.h"

typedef struct celula Celula;

typedef struct {
    Celula *primeiro;
    Celula *ultimo;
} PokeLista;

void pokelista_inicializar(PokeLista *lista);

void pokelista_inserir(PokeLista *lista, Pokemon p);

int pokelista_remover(PokeLista *lista, int id);

Pokemon* pokelista_buscar(const PokeLista *lista, int id);

void pokelista_imprimir(const PokeLista *lista);

#endif