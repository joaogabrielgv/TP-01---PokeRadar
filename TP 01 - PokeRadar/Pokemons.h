#ifndef POKEMONS_H
#define POKEMONS_H

typedef struct {
    int x;
    int y;
} Coordenadap;

typedef struct {
    int id;
    int numpoke;
    char nome[20];
    char tipo[15];
    Coordenadap localizacaop;
} Pokemon;

void inicializar_pokemon(Pokemon *p, int id, int numpoke, const char *nome, const char *tipo, Coordenadap localizacaop);

int pokemon_get_id(const Pokemon *p);
void pokemon_set_id(Pokemon *p, int id);

int pokemon_get_numpoke(const Pokemon *p);
void pokemon_set_numpoke(Pokemon *p, int numpoke);

void pokemon_get_nome(const Pokemon *p, char *nome, int tamanho);
void pokemon_set_nome(Pokemon *p, const char *nome);

void pokemon_get_tipo(const Pokemon *p, char *tipo, int tamanho);
void pokemon_set_tipo(Pokemon *p, const char *tipo);

Coordenadap pokemon_get_localizacao(const Pokemon *p);
void pokemon_set_localizacao(Pokemon *p, Coordenadap localizacaop);

void pokemon_imprimir(const Pokemon *p);

#endif