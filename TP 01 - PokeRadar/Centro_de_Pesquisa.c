#include <stdio.h>
#include <stdlib.h>

#include "Centro_de_Pesquisa.h"

void centro_inicializar (CentroPesquisa *c) {
    c->localizacaoc.x=0;
    c->localizacaoc.y=0;

    pokelista_inicializar (&c->fugitivos);
    pokelista_inicializar (&c->recuperados);
}

int centro_insercao_fugitivos (CentroPesquisa *c, Pokemon *p) {
    return pokelista_inserir (&c->fugitivos, p);
}

int centro_remover_fugitivos (CentroPesquisa *c, Pokemon *p) {
    return pokelista_remover (&c->fugitivos, p);
}

void centro_imprimir_fugitivos (const CentroPesquisa *c) {
    pokelista_imprimir (&c->fugitivos);
}

int centro_recebimento_recuperados (CentroPesquisa *c, Pokemon *p) {
    return pokelista_inserir (&c->recuperados, p);
}

void centro_recarga_pokebolas (Treinador *t) {
    t->pokebolas = rand() % 20 + 1;
}