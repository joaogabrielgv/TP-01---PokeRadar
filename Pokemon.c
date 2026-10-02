
#include <stdio.h>
#include <string.h>
#include "Pokemons.h"

// TAD 1 - POKÉMON (IMPLEMENTAÇÃO)

void inicializar_pokemon(Pokemon *p, int id, int numpoke, char *nome, char *tipo, Coordenadap localizacaop) {
    p->id = id;
    p->numpoke = numpoke;
    strncpy(p->nome, nome, sizeof(p->nome) - 1);
    p->nome[sizeof(p->nome) - 1] = '\0';
    strncpy(p->tipo, tipo, sizeof(p->tipo) - 1);
    p->tipo[sizeof(p->tipo) - 1] = '\0';
    p->localizacaop = localizacaop;
}


void pokemon_imprimir(Pokemon *p){
    printf("id: %d \n numero na pokedex: %d \n nome: %s \n tipo: %s \n Coordenada x: %d \n Coordenada y: %d \n", p->id, p->numpoke, p->nome, p->tipo, p->localizacaop.x, p->localizacaop.y);
}


void pokemon_get_nome(Pokemon *p, char *nome, int tamanho) {
    strncpy(nome, p->nome, tamanho - 1);
    nome[tamanho - 1] = '\0';
}
void pokemon_set_nome(Pokemon *p, char *nome){
    strcpy(p->nome, nome);
}


void pokemon_get_tipo(Pokemon *p, char *tipo, int tamanho) {
    strncpy(tipo, p->tipo, tamanho - 1);
    tipo[tamanho - 1] = '\0';
}
void pokemon_set_tipo(Pokemon *p, char *tipo){
    strcpy(p->tipo, tipo);
}


Coordenadap pokemon_get_localizacao(Pokemon *p){
    return p->localizacaop;
}
void pokemon_set_localizacao(Pokemon *p, Coordenadap localizacaop){
    p->localizacaop = localizacaop; //Estao com o mesmo nome, mas acho que dá pra entender que o da direita é o que o usuário passou no parâmetro da função
}


int pokemon_get_id(Pokemon *p){
    return p->id;
}
void pokemon_set_id(Pokemon *p, int id){
    p->id = id;
}


int pokemon_get_numpoke(Pokemon *p){
    return p->numpoke;
}
void pokemon_set_numpoke(Pokemon *p, int numpoke){
    p->numpoke = numpoke;
}