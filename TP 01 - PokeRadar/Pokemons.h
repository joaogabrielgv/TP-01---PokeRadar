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

void inicializar_pokemon(Pokemon *p, int id, int numpoke, char *nome, char *tipo, Coordenadap localizacaop);

int pokemon_get_id(Pokemon *p);
void pokemon_set_id(Pokemon *p, int id);

int pokemon_get_numpoke(Pokemon *p);
void pokemon_set_numpoke(Pokemon *p, int numpoke);

void pokemon_get_nome(Pokemon *p);
void pokemon_set_nome(Pokemon *p, char *nome);

void pokemon_get_tipo(Pokemon *p);
void pokemon_set_tipo(Pokemon *p, char *tipo);

Coordenadap pokemon_get_localizacao(Pokemon *p);
void pokemon_set_localizacao(Pokemon *p, Coordenadap localizacaop);

void pokemon_imprimir(Pokemon *p);

#endif