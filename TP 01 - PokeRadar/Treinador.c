#include <stdio.h>

#include "Treinador.h"

void treinador_inicializar (Treinador *t, int id, char *nome, int pokebolas) {
    t->id = id;

    strncpy(t->nome, nome, sizeof(t->nome) - 1);
    t->nome[sizeof(t->nome) - 1] = '\0';

    t->localizacaot.x = 0;
    t->localizacaot.y = 0;
    t->pokebolas = pokebolas;
    pokelista_inicializar (&t->poke_treinador);
}

void treinador_movimentacao (Treinador *t, int x, int y) {
    t->localizacaot.x = x;
    t->localizacaot.y = y;
}

int treinador_capturar_pokemon (Treinador *t, Pokemon *p) {
    if (t->pokebolas <= 0) {
        return 0;
    }
    else {
        t->pokebolas -= 1;
    }

    pokelista_inserir (&t->poke_treinador, p);
    return 1;
}

int treinador_remover_pokemon (Treinador *t, Pokemon *p) {
    return pokelista_remover (&t->poke_treinador, p);
}

void treinador_imprimir (const Treinador *t) {
    printf ("Treinador: %s", t->nome);
    printf ("Id: %d", t->id);
    printf ("Localização: (%d, %d)", t->localizacaot.x, t->localizacaot.y);
    printf ("Pokébolas: %d", t->pokebolas);
    pokelista_imprimir (&t->poke_treinador); 
}